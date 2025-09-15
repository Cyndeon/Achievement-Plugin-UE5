// Copyright Epic Games, Inc. All Rights Reserved.

#include "AchievementPlugin.h"

#if WITH_EDITOR
#include "ISettingsModule.h"
#endif

#include "AchievementLogCategory.h"
#include "Misc/MessageDialog.h"
#include "USaveSystem.h"

#include "../ThirdParty/steamworks_sdk_162/sdk/public/steam/steam_api.h"


#define LOCTEXT_NAMESPACE "FAchievementPluginModule"

void CreateSteamAppIdFile(const int32 appId)
{
	// Get the directory where the executable is located
	FString ExecutableDir = FPaths::ConvertRelativePathToFull(FPlatformProcess::BaseDir());
	FString AppIdFilePath = FPaths::Combine(ExecutableDir, TEXT("steam_appid.txt"));

	UE_LOG(AchievementLog, Log, TEXT("Creating steam_appid.txt at: %s"), *AppIdFilePath);

	// Write the App ID to the file (this will overwrite if file exists)
	const FString& appIdString = FString().FormatAsNumber(appId);
	bool bSuccess = FFileHelper::SaveStringToFile(appIdString, *AppIdFilePath, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM);

	if (bSuccess)
	{
		UE_LOG(AchievementLog, Log, TEXT("Successfully created steam_appid.txt with App ID: %s"), *appIdString);

		// Verify the file was created correctly
		FString ReadBack;
		if (FFileHelper::LoadFileToString(ReadBack, *AppIdFilePath))
		{
			UE_LOG(AchievementLog, Log, TEXT("File verification - contents: '%s'"), *ReadBack.TrimStartAndEnd());
		}
	}
	else
	{
		UE_LOG(AchievementLog, Error, TEXT("Failed to create steam_appid.txt file"));
	}	
}

void FAchievementPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

#if WITH_EDITOR
	 // Register with settings system to appear in Project Settings
	if (ISettingsModule* settingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		settingsModule->RegisterSettings("Project", "Game", "AchievementPlugin",
										 LOCTEXT("RuntimeSettingsName", "Achievement Plugin"),
										 LOCTEXT("RuntimeSettingsDescription", "Configure Achievement Plugin settings"),
										 GetMutableDefault<UAchievementPluginSettings>()
		);
	}
#endif
	const auto* settings = UAchievementPluginSettings::Get();
	switch (settings->GetAchievementPlatform())
	{
		case EAchievementPlatforms::STEAM:
		{
			// just to make sure the file exists:
			CreateSteamAppIdFile(settings->GetSteamAppID());

			UE_LOG(AchievementLog, Warning, TEXT("AchievementPlugin module starting up..."));

			if (!SteamAPI_IsSteamRunning())
			{
				UE_LOG(AchievementLog, Error, TEXT("Steam is not running!"));
				return;
			}

			UE_LOG(AchievementLog, Log, TEXT("Steam is running, attempting detailed initialization..."));

			// Use SteamAPI_InitEx for detailed error information
			SteamErrMsg errMsg;
			ESteamAPIInitResult initResult = SteamAPI_InitEx(&errMsg);

			switch (initResult)
			{
				case k_ESteamAPIInitResult_OK:
					UE_LOG(AchievementLog, Log, TEXT("Steam API initialized successfully!"));
					break;

				case k_ESteamAPIInitResult_FailedGeneric:
					UE_LOG(AchievementLog, Error, TEXT("Steam Init Failed: Generic failure"));
					UE_LOG(AchievementLog, Error, TEXT("Error message: %s"), ANSI_TO_TCHAR(errMsg));
					return;

				case k_ESteamAPIInitResult_NoSteamClient:
					UE_LOG(AchievementLog, Error, TEXT("Steam Init Failed: No Steam client running"));
					UE_LOG(AchievementLog, Error, TEXT("Error message: %s"), ANSI_TO_TCHAR(errMsg));
					return;

				case k_ESteamAPIInitResult_VersionMismatch:
					UE_LOG(AchievementLog, Error, TEXT("Steam Init Failed: Version mismatch between client and SDK"));
					UE_LOG(AchievementLog, Error, TEXT("Error message: %s"), ANSI_TO_TCHAR(errMsg));
					return;

				default:
					UE_LOG(AchievementLog, Error, TEXT("Steam Init Failed: Unknown error %d"), (int32)initResult);
					UE_LOG(AchievementLog, Error, TEXT("Error message: %s"), ANSI_TO_TCHAR(errMsg));
					return;
			}

			// Rest of your Steam verification code...
			if (SteamUser() && SteamUser()->BLoggedOn())
			{
				UE_LOG(AchievementLog, Log, TEXT("Steam user is logged on successfully"));
				CSteamID steamID = SteamUser()->GetSteamID();
				UE_LOG(AchievementLog, Log, TEXT("Steam User ID: %llu"), steamID.ConvertToUint64());

				if (SteamUserStats())
				{
					UE_LOG(AchievementLog, Log, TEXT("SteamUserStats interface ready"));
					auto bSuccess = SteamUserStats()->RequestUserStats(SteamUser()->GetSteamID());
					UE_LOG(AchievementLog, Log, TEXT("RequestUserStats result: %s"), bSuccess ? TEXT("SUCCESS") : TEXT("FAILED"));
				}
			}

			break;
		}

		// IMPLEMENT EOS

		// for Local Only, no need to set up anything
		default:
			break;
	}
}

void FAchievementPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

#if WITH_EDITOR
		// Unregister from settings system
	if (ISettingsModule* settingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		settingsModule->UnregisterSettings("Project", "Plugins", "AchievementPlugin");
	}
#endif

	SteamAPI_Shutdown();
}

UAchievementPluginSettings::UAchievementPluginSettings()
{
	CacheAchievementNamesArray();
}

#if WITH_EDITOR

void UAchievementPluginSettings::PostEditChangeProperty(FPropertyChangedEvent& propertyChangedEvent)
{
	const FName changedPropertyName = propertyChangedEvent.GetPropertyName();

	// load runtime stats button
	if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, loadRuntimeStatsButton))
	{
		if (loadRuntimeStatsButton) // only when checked
		{
			UpdateRuntimeStats();

			// Reset so it can be clicked again
			loadRuntimeStatsButton = false;
		}
	}

	// force save progress button
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, forceSaveAchievements))
	{
		if (forceSaveAchievements) // only when checked
		{
			// From any class that has access to the engine
			auto* manager = UAchievementManager::Get();
			manager->GetSaveManager()->SaveProgressAsync(manager->achievementsProgress);

			// Reset so it can be clicked again
			forceSaveAchievements = false;
		}
	}

	// force load progress button
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, forceLoadAchievementProgress))
	{
		if (forceLoadAchievementProgress) // only when checked
		{
			// From any class that has access to the engine
			auto* manager = UAchievementManager::Get();
			manager->achievementsProgress = manager->GetSaveManager()->LoadProgress();

			manager->CleanupAchievements();

			// Reset so it can be clicked again
			forceLoadAchievementProgress = false;
		}
	}

	// TEMP BUTTON!!!!!!!!!! DELETE THIS ONCE DONE TESTING!
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, progressStuff))
	{
		if (progressStuff) // only when checked
		{
			auto* manager = UAchievementManager::Get();
			const int count = manager->achievementsProgress.Num();
			for (int i = 0; i < count; i++)
			{
				manager->achievementsProgress[i].progress = FMath::RandRange(1, 100);
			}

			// Reset so it can be clicked again
			progressStuff = false;
		}
	}


	// If the save slot data has been modified, also update that of the USaveSystem's
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(FSaveSlotSettings, slotName) ||
			 changedPropertyName == GET_MEMBER_NAME_CHECKED(FSaveSlotSettings, slotIndex))
	{
		const auto getter = UAchievementManager::Get();
		getter->GetSaveManager()->SetSaveSlotSettings(defaultSaveSlotSettings);

		AttemptSave();
	}

	// if a new achievement got added/removed
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, achievementsData))
	{
		// If a new achievement got added
		if (propertyChangedEvent.ChangeType == EPropertyChangeType::ArrayAdd)
		{
			// find it
			for (auto& chiev : achievementsData)
			{
				if (chiev.Key.IsEmpty())
				{
					// generate an ID for itself and the Progress struct
					// also increment the ID
					const int linkID = m_nextLinkID++;

					// generate a default name so it is obvious this is the next achievement
					auto newKey = FString(TEXT("Achievement_")) + FString::FromInt(achievementsData.Num());
					chiev.Key = newKey;
					chiev.Value.OverrideLinkID(linkID);

					// create the empty Achievement Progress as well
					auto* manager = UAchievementManager::Get();
					manager->achievementsProgress.Add(linkID, FAchievementProgress());
					UE_LOG(AchievementLog, Log, TEXT("Created a new achievement with Link ID '%d'"), linkID);

					CacheAchievementNamesArray();

					AttemptSave();
					break;
				}
			}
		}
	}

	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, m_steamAppID))
	{
		CreateSteamAppIdFile(m_steamAppID);
	}

	Super::PostEditChangeProperty(propertyChangedEvent);
}

void UAchievementPluginSettings::AttemptSave()
{
	// Force the package to be marked as dirty and save
	(void)MarkPackageDirty();

	// Force immediate save
	TryUpdateDefaultConfigFile();
}
#endif

void UAchievementPluginSettings::UpdateRuntimeStats()
{
	const auto progressData = UAchievementManager::Get()->achievementsProgress;
	// look for the progress that has the same LinkID
	for (auto& chiev : achievementsData)
	{
		const auto* progress = progressData.Find(chiev.Value.GetLinkID());
		if (progress != nullptr)
		{
			// set the currentProgress
			chiev.Value.UpdateProgressEditorOnly(*progress);
			break;
		}

	}
}

void UAchievementPluginSettings::CacheAchievementNamesArray()
{
	m_cachedAchievementNames.Empty();
	for (const auto& achievement : achievementsData)
	{
		m_cachedAchievementNames.Add(achievement.Key);
	}
}

UAchievementManager* UAchievementManager::Get()
{
	if (GEngine)
	{
		return GEngine->GetEngineSubsystem<UAchievementManager>();
	}
	// should never happen
	UE_LOG(AchievementLog, Error, TEXT("Achievement Manager subsystem is deleted, please restart the engine/game (if this doesn't crash it already)!"));
	return nullptr;
}

UAchievementSaveManager* UAchievementManager::GetSaveManager() const
{
	{
		if (m_saveManager)
			return m_saveManager;
		else
		{
			UE_LOG(AchievementLog, Fatal, TEXT("UAchievementSaveManager is null! Returning nullptr."));
			return nullptr;
		}
	}
}

void UAchievementManager::Initialize(FSubsystemCollectionBase& collection)
{
	Super::Initialize(collection);

	m_saveManager = NewObject<UAchievementSaveManager>(this);

	// load the progress if any existed
	const UAchievementPluginSettings* settings = UAchievementPluginSettings::Get();
	achievementsProgress = m_saveManager->LoadProgress();

	// then make sure all achievements have a progress one as well
	InitializeAchievements();

	// make sure to remove any deleted achievements
	if (UAchievementPluginSettings::Get()->bCleanupAchievements)
		CleanupAchievements();
}

void UAchievementManager::Deinitialize()
{
	// Make sure to save the current achievementsData before exiting (using the sync, not Async version)
	if (m_saveManager)
	{

		// then attempt to save
		const bool bSavedCorrectly = m_saveManager->SaveProgress(achievementsProgress);
		if (!bSavedCorrectly)
		{
			UE_LOG(AchievementLog, Error, TEXT("Achievements could not be saved properly!"));
		}
	}
	else
	{
		UE_LOG(AchievementLog, Fatal, TEXT("SaveManager seems to have been deleted, achievementsData will not save properly!"));
	}

	// Deinitialize it last to make sure the subsystem isn't destroyed before we are done saving
	Super::Deinitialize();
}

void UAchievementManager::InitializeAchievements()
{
	const UAchievementPluginSettings* settings = UAchievementPluginSettings::Get();
	// if there are as many achievements as there are progress for them, return
	if (settings->achievementsData.Num() == achievementsProgress.Num())
		return;

	// Add missing achievements progress
	const auto& data = settings->achievementsData;
	for (const auto& achievementPair : data)
	{
		const auto id = achievementPair.Value.GetLinkID();
		// if the id doesn't exist in the achievements progress yet
		if (!achievementsProgress.Contains(id))
		{
			// create an empty achievement with that id
			achievementsProgress.Add(id, FAchievementProgress());
			UE_LOG(AchievementLog, Log, TEXT("Created a new achievement Progress for '%s'"), *achievementPair.Key);
		}
	}
}

void UAchievementManager::CleanupAchievements()
{
	// Remove any progress entries that don't exist in settings anymore
	UAchievementPluginSettings* settings = UAchievementPluginSettings::Get();

	const int startingCount = achievementsProgress.Num();
	TArray<int32> linkIDs = TArray<int32>();
	for (const auto& chievs : settings->achievementsData)
	{
		linkIDs.Add(chievs.Value.GetLinkID());
	}

	// used the UE5 documentation for this one https://dev.epicgames.com/documentation/en-us/unreal-engine/map-containers-in-unreal-engine#iterate

	// Iterate with iterator so we can safely remove during iteration
	for (auto it = achievementsProgress.CreateIterator(); it; ++it)
	{
		if (!linkIDs.Contains(it.Key()))
		{
			it.RemoveCurrent();
		}
	}

	// log how many achievements were removed if any were
	const int removedAchievements = startingCount - achievementsProgress.Num();
	if (removedAchievements != 0)
		UE_LOG(AchievementLog, Log, TEXT("Cleanup finished, deleted achievement progress for %d achievements."), removedAchievements)
}

bool UAchievementManager::SetAchievementProgress(int32 achievementID)
{
	// WIP
	return false;
	//if (auto* achievementProgress = UAchievementManager::Get()->achievementsProgress.Find(id))
	//{
	//	// if it was already unlocked, return early
	//	if (achievementProgress->bIsAchievementUnlocked)
	//	{
	//		UE_LOG(AchievementLog, Log, TEXT("Achievement '%s' was already unlocked, skipping."), *achievementID);
	//		return true;
	//	}

	//	// if goal has been reached, unlock it
	//	const auto goal = UAchievementPluginSettings::Get()->achievementsData.Find(achievementID)->progressGoal;

	//	if (achievementProgress->progress + increase >= goal)
	//	{
	//		achievementProgress->progress = goal;
	//		achievementProgress->bIsAchievementUnlocked = true;


	//		// CALL UNLOCK ON PLATFORMS HERE =========================================================================
	//	}
	//	else
	//		achievementProgress->progress += increase;

	//	UE_LOG(AchievementLog, Log, TEXT("Increased progress for '%s' to '%d'"), *achievementID, achievementProgress->progress);
	//	return true;
	//}
	//UE_LOG(AchievementLog, Error, TEXT("Could not find achievement progress for the Link ID '%d'"), id);
	//return false;
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAchievementPluginModule, AchievementPlugin)