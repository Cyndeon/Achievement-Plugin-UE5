// Copyright Epic Games, Inc. All Rights Reserved.

#include "AchievementPlugin.h"

#if WITH_EDITOR
#include "ISettingsModule.h"
#endif

#include "AchievementLogCategory.h"
#include "USaveSystem.h"
#include "AchievementPlatforms.h"


#define LOCTEXT_NAMESPACE "FAchievementPluginModule"

void FAchievementPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

#if WITH_EDITOR
	 // register the pluginSettings in the developer settings
	if (ISettingsModule* settingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		settingsModule->RegisterSettings("Project", "Game", "AchievementPlugin",
										 LOCTEXT("RuntimeSettingsName", "Achievement Plugin"),
										 LOCTEXT("RuntimeSettingsDescription", "Configure Achievement Plugin settings"),
										 GetMutableDefault<UAchievementPluginSettings>()
		);
	}
#endif
}

void FAchievementPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

#if WITH_EDITOR
	// unregister from settings system
	if (ISettingsModule* settingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		settingsModule->UnregisterSettings("Project", "Plugins", "AchievementPlugin");
	}
#endif

	// an extra shutdown at the end just to make sure it did shut down properly in case the program exits unexpectedly
	if (!bHasPlatformShutDown)
	{
		UAchievementPlatformsClass::ShutdownPlatform();
		bHasPlatformShutDown = true;
	}
}

int32 UAchievementPluginSettings::GetLinkIDByAchievementID(const FString& achievementId)
{
	// check if the achievement name exists
	if (const auto* achievement = achievementsData.Find(achievementId))
	{
		return achievement->GetLinkID();
	}
	UE_LOG(AchievementLog, Error, TEXT("Achievement with the name '%s' cannot be found!"), *achievementId);
	return 0;
}

#if WITH_EDITOR

void UAchievementPluginSettings::OverrideAchievementsWithThoseFromSelectedPlatform()
{
	if (auto* platformClass = UAchievementPlatformsClass::Get())
	{
		// if Steam hadn't started yet, we'll need to start it first
		if (!platformClass->achievementPlatformInitialized)
		{
			platformClass->InitializePlatform(m_achievementPlatform);
		}
		// store the received achievements in a separate map for now
		const auto platformAchievements = platformClass->GetPlatformAchievementsAsAchievementDataMap();
		// if there are received achievements, empty the map we have and instead fill it with the platform's
		if (platformAchievements.Num() > 0)
		{
			achievementsData.Empty();
			achievementsData = platformAchievements;
		}
		else
		{
			UE_LOG(AchievementPlatformLog, Warning, TEXT("Could not download achievements from the selected platform."));
		}

		AttemptSave();
	}
}

void UAchievementPluginSettings::PostEditChangeProperty(FPropertyChangedEvent& propertyChangedEvent)
{
	const FName changedPropertyName = propertyChangedEvent.GetPropertyName();

#pragma region buttons
	// load runtime stats button
	if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, bLoadRuntimeStatsButton))
	{
		if (bLoadRuntimeStatsButton) // only when checked
		{
			UpdateRuntimeStats();

			// Reset so it can be clicked again
			bLoadRuntimeStatsButton = false;
		}
	}

	// force save progress button
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, bForceSaveAchievements))
	{
		if (bForceSaveAchievements) // only when checked
		{
			// From any class that has access to the engine
			const auto* manager = UAchievementManagerSubSystem::Get();
			manager->GetSaveManager()->SaveProgressAsync(manager->achievementsProgress);

			// Reset so it can be clicked again
			bForceSaveAchievements = false;
		}
	}

	// force load progress button
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, bForceLoadAchievementProgress))
	{
		if (bForceLoadAchievementProgress) // only when checked
		{
			// From any class that has access to the engine
			auto* manager = UAchievementManagerSubSystem::Get();
			manager->achievementsProgress = manager->GetSaveManager()->LoadProgress();

			manager->CleanupAchievements();

			// Reset so it can be clicked again
			bForceLoadAchievementProgress = false;
		}
	}

	// force download Steam achievements button
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, bForceDownloadSteamAchievements))
	{
		// first we only set this to true, doesn't do anything else
	}
	// if the user is sure, override the old achievements with the new ones and save
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, bForceDownloadSteamAchievementsSafetyCheck))
	{
		OverrideAchievementsWithThoseFromSelectedPlatform();

		bForceDownloadSteamAchievements = false;
		bForceDownloadSteamAchievementsSafetyCheck = false;
	}

	// TEMP BUTTON!!!!!!!!!! DELETE THIS ONCE DONE TESTING!
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, progressStuff))
	{
		if (progressStuff) // only when checked
		{
			auto* manager = UAchievementManagerSubSystem::Get();
			for (auto& progress : manager->achievementsProgress)
			{
				progress.Value.progress = FMath::RandRange(1, 100);
			}

			// Reset so it can be clicked again
			progressStuff = false;
		}
	}

#pragma endregion
	// If the save slot data has been modified, also update that of the USaveSystem's
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(FSaveSlotSettings, slotName) ||
			 changedPropertyName == GET_MEMBER_NAME_CHECKED(FSaveSlotSettings, slotIndex))
	{
		const auto getter = UAchievementManagerSubSystem::Get();
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
					auto* manager = UAchievementManagerSubSystem::Get();
					manager->achievementsProgress.Add(linkID, FAchievementProgress());
					UE_LOG(AchievementLog, Log, TEXT("Created a new achievement with Link ID '%d'"), linkID);

					AttemptSave();
					break;
				}
			}
		}
	}

	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, m_steamAppID))
	{
		UAchievementPlatformsClass::CreateSteamAppIdFile(m_steamAppID);
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

void UAchievementPluginSettings::UpdateRuntimeStats()
{
	const auto progressData = UAchievementManagerSubSystem::Get()->achievementsProgress;
	// look for the progress that has the same LinkID
	for (auto& chiev : achievementsData)
	{
		if (const auto* progress = progressData.Find(chiev.Value.GetLinkID()))
		{
			// set the currentProgress
			chiev.Value.UpdateProgressEditorOnly(*progress);

		}

	}
}
#endif

UAchievementManagerSubSystem* UAchievementManagerSubSystem::Get()
{
	if (GEngine)
	{
		return GEngine->GetEngineSubsystem<UAchievementManagerSubSystem>();
	}
	// should never happen
	UE_LOG(AchievementLog, Fatal, TEXT("Achievement Manager subsystem is deleted, please restart the engine/game (if this doesn't crash it already)!"));
	return nullptr;
}

UAchievementSaveManager* UAchievementManagerSubSystem::GetSaveManager() const
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

void UAchievementManagerSubSystem::Initialize(FSubsystemCollectionBase& collection)
{
	Super::Initialize(collection);

	m_worldInitializedHandle = FWorldDelegates::OnPostWorldInitialization.AddUFunction(
		this,
		FName("OnWorldInitialized")
	);

	m_worldCleanupHandle = FWorldDelegates::OnWorldCleanup.AddUFunction(
		this,
		FName("OnWorldCleanup")
	);

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

void UAchievementManagerSubSystem::Deinitialize()
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

void UAchievementManagerSubSystem::InitializeAchievements()
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

void UAchievementManagerSubSystem::CleanupAchievements()
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

bool UAchievementManagerSubSystem::IncreaseAchievementProgress(const FString& achievementId, const float increase)
{
	const auto linkId = UAchievementPluginSettings::Get()->GetLinkIDByAchievementID(achievementId);
	if (auto* achievementProgress = achievementsProgress.Find(linkId))
	{
		// if it was already unlocked, return
		if (achievementProgress->bIsAchievementUnlocked)
		{
			UE_LOG(AchievementLog, Log, TEXT("Achievement '%s' was already unlocked, skipping."), *achievementId);
			return true;
		}

		// if goal has been reached, unlock it
		const auto& achievement = UAchievementPluginSettings::Get()->achievementsData.Find(achievementId);
		const auto goal = achievement->progressGoal;

		if (achievementProgress->progress + increase >= goal)
		{
			achievementProgress->progress = goal;
			achievementProgress->bIsAchievementUnlocked = true;
			achievementProgress->unlockedTime = FDateTime::Now().ToString();
		}
		else
		{
			achievementProgress->progress += increase;
		}
		UAchievementPlatformsClass::SetPlatformAchievementProgress(achievement->platformData, achievementProgress->progress, achievementProgress->bIsAchievementUnlocked);

		UE_LOG(AchievementLog, Log, TEXT("Increased progress for '%s' to '%f'"), *achievementId, achievementProgress->progress);
		return true;
	}
	UE_LOG(AchievementLog, Error, TEXT("Could not find achievement progress for the '%s'"), *achievementId);
	return false;
}

void UAchievementManagerSubSystem::OnWorldInitialized(const UWorld* world)
{
	// Only initialize for actual game worlds, not editor preview worlds
	if (world && world->IsGameWorld())
	{
		if (const auto* settings = UAchievementPluginSettings::Get())
		{
			if (settings->GetManuallyInitializePlatform())
			{
				if (auto* platformClass = UAchievementPlatformsClass::Get())
				{
					platformClass->InitializePlatform(settings->GetAchievementPlatform());
					FAchievementPluginModule::Get()->bWasManuallyInitialized = true;
				}
			}
		}
	}
}

void UAchievementManagerSubSystem::OnWorldCleanup(const UWorld* world, bool bSessionEnded, bool bCleanupResources)
{
	// Only initialize for actual game worlds, not editor preview worlds
	if (world && world->IsGameWorld())
	{
		if (auto* plugin = FAchievementPluginModule::Get())
		{
			if (!plugin->bHasPlatformShutDown && plugin->bWasManuallyInitialized)
			{
				if (const auto* platformClass = UAchievementPlatformsClass::Get())
				{
					UE_LOG(AchievementPlatformLog, Log, TEXT("Starting platform shutdown process..."));
					platformClass->ShutdownPlatform();
					plugin->bHasPlatformShutDown = true;
				}
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAchievementPluginModule, AchievementPlugin)