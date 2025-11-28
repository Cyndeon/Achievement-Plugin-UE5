// -------------------------------------------------------------
// Copyright 2025 Justin Comans. Licensed under CC BY 4.0.    ||
// -------------------------------------------------------------

// Copyright Epic Games, Inc. All Rights Reserved.

#include "AchievementPlugin.h"

#include "AchievementLogCategory.h"
#include "USaveSystem.h"
#include "AchievementPlatforms.h"
#include "UAchievementPopupManager.h"


#define LOCTEXT_NAMESPACE "FAchievementPluginModule"

void FAchievementPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FAchievementPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

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
void UAchievementPluginSettings::CreateAchievement(const FString& localID, const FAchievementData& achievement)
{
	const auto linkID = m_nextLinkID++;

	// make a copy and then set the link ID
	auto achievementWithLinkId = achievement;
	achievementWithLinkId.OverrideLinkID(linkID);
	achievementsData.Add(localID, achievementWithLinkId);

	// also update the progress Map
	auto* manager = UAchievementManagerSubSystem::Get();
	manager->achievementsProgress.Add(linkID, FAchievementProgress());
}

void UAchievementPluginSettings::OverrideAchievementsWithThoseFromSelectedPlatform()
{
	if (auto* platformClass = UAchievementPlatformsClass::Get())
	{
		// if platform hadn't started yet, we'll need to start it first
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
			for (const auto& achievement : platformAchievements)
			{
				CreateAchievement(achievement.Key, achievement.Value);
			}
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
		if (bLoadRuntimeStatsButton)
		{
			UpdateRuntimeStats();

			// Reset so it can be clicked again
			bLoadRuntimeStatsButton = false;
		}
	}

	// force save progress button
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, bForceSaveAchievementProgress))
	{
		if (bForceSaveAchievementProgress)
		{
			const auto* manager = UAchievementManagerSubSystem::Get();
			manager->GetSaveManager()->SaveProgressAsync(manager->achievementsProgress);

			// Reset so it can be clicked again
			bForceSaveAchievementProgress = false;
		}
	}

	// force load progress button
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, bForceLoadAchievementProgress))
	{
		if (bForceLoadAchievementProgress)
		{
			auto* manager = UAchievementManagerSubSystem::Get();
			manager->achievementsProgress = manager->GetSaveManager()->LoadProgress();

			manager->CleanupAchievements();

			// Reset so it can be clicked again
			bForceLoadAchievementProgress = false;
		}
	}

	// force download Steam achievements button
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, bForceDownloadPlatformAchievements))
	{
		// first we only set this to true, doesn't do anything else
		// this will however, make the SafetyCheck button visible
	}
	// if the user is sure, override the old achievements with the new ones and save
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, bForceDownloadPlatformAchievementsSafetyCheck))
	{
		OverrideAchievementsWithThoseFromSelectedPlatform();

		bForceDownloadPlatformAchievements = false;
		bForceDownloadPlatformAchievementsSafetyCheck = false;
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
					auto* manager = UAchievementManagerSubSystem::Get();
					// if there are the max possible amount of achievements (unlikely but theoretically possible)
					if (manager->achievementsProgress.Num() >= TNumericLimits<int32>::Max())
					{
						UE_LOG(AchievementLog, Error, TEXT("Max achievement limit reached (unique int32 values), last added achievement will not work, please remove it!"));
						chiev.Key = "ERROR, DELETE ME, LIMIT REACHED";
					}

					int linkID = 0;
					do
					{
						// generate an ID for itself and the Progress struct
						// also increment the ID and make sure it is unique
						linkID = m_nextLinkID;

						if (m_nextLinkID == TNumericLimits<int32>::Max())
						{
							m_nextLinkID = TNumericLimits<int32>::Min();
						}
						else
						{
							m_nextLinkID++;
						}
					} while (manager->achievementsProgress.Contains(linkID));

					chiev.Value.OverrideLinkID(linkID);

					// generate a default name
					FString newKey = FString::Printf(TEXT("Achievement_%d"), linkID);
					while (achievementsData.Contains(newKey))
					{
						linkID++;
						newKey = FString::Printf(TEXT("Achievement_%d"), linkID);
					}
					chiev.Key = newKey;

					// create the empty Achievement Progress as well
					manager->achievementsProgress.Add(linkID, FAchievementProgress());
					UE_LOG(AchievementLog, Log, TEXT("Created a new achievement with Link ID '%d'"), linkID);

					AttemptSave();
					break;
				}
			}
		}
	}

	// platform specific data
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, m_steamAppID))
	{
		UAchievementPlatformsClass::CreateSteamAppIdFile(m_steamAppID);
	}

#if !STEAMWORKS_INCLUDED
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, m_achievementPlatform))
	{
		if (m_achievementPlatform == STEAM)
		{
			UE_LOG(AchievementLog, Warning, TEXT("Steamworks SDK has not been installed properly, please check the documentation on how to do so!"));
			m_achievementPlatform = LOCALONLY;
		}
	}
#endif

	Super::PostEditChangeProperty(propertyChangedEvent);
}

void UAchievementPluginSettings::PostInitProperties()
{
	Super::PostInitProperties();

	if (achievementWidgetSettings.achievementWidget == nullptr)
	{
		UE_LOG(AchievementLog, Warning, TEXT("Achievement Widget/Popup is not set, using default widget"));

		FSoftClassPath widgetPath(TEXT("/AchievementPlugin/BPW_AchievementPopup.BPW_AchievementPopup_C"));
		TSubclassOf<UUserWidget> widgetClass = widgetPath.TryLoadClass<UUserWidget>();

		if (widgetClass)
		{
			achievementWidgetSettings.achievementWidget = widgetClass;
			UE_LOG(AchievementLog, Log, TEXT("Successfully set the default Achievement widget"));
			AttemptSave();
		}
		else
		{
			UE_LOG(AchievementLog, Error, TEXT("Failed to load default achievement widget"));
		}
	}

#if !STEAMWORKS_INCLUDED
	if (m_achievementPlatform == EAchievementPlatforms::STEAM)
		m_achievementPlatform = EAchievementPlatforms::LOCALONLY;
#endif
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

EUnlockedPlatforms GetSelectedPlatformAsEUnlockedPlatforms()
{
	switch (UAchievementPluginSettings::Get()->GetAchievementPlatform())
	{
		case  EAchievementPlatforms::STEAM:
		{
			return EUnlockedPlatforms::Steam;
		}
		case EAchievementPlatforms::EOS:
		{
			return EUnlockedPlatforms::Epic;
		}

		default: return EUnlockedPlatforms::None;
	}
}

bool UAchievementManagerSubSystem::IncreaseAchievementProgress(const FString& achievementId, const float increase)
{
	const auto& settings = UAchievementPluginSettings::Get();
	if (!settings)
	{
		UE_LOG(AchievementLog, Error, TEXT("Settings::Get() returned nullptr!"));
		return false;
	}

	const auto linkId = settings->GetLinkIDByAchievementID(achievementId);
	if (auto* achievementProgress = achievementsProgress.Find(linkId))
	{
		// if it was already unlocked, return
		const auto& achievement = UAchievementPluginSettings::Get()->achievementsData.Find(achievementId);
		const auto goal = achievement->progressGoal;
		bool localUnlocked = EnumHasAnyFlags(achievementProgress->unlockedOnPlatforms, EUnlockedPlatforms::Local);

		if (!localUnlocked)
		{
			// if goal has been reached, unlock it
			if (achievementProgress->progress + increase >= goal)
			{
				achievementProgress->progress = goal;
				achievementProgress->unlockedOnPlatforms |= EUnlockedPlatforms::Local;
				achievementProgress->unlockedTime = FDateTime::Now().ToString();

				localUnlocked = true;
				UE_LOG(AchievementLog, Log, TEXT("Unlocked achievement '%s'"), *achievementId);
			}
			// otherwise we just increase progress
			else
			{
				achievementProgress->progress += increase;
				UE_LOG(AchievementLog, Log, TEXT("Increased progress for '%s' to '%f'"), *achievementId, achievementProgress->progress);
			}

			// create widget to show progress/unlock
			const auto& widgetSettings = settings->achievementWidgetSettings;
			if (widgetSettings.usePopups && widgetSettings.achievementWidget != nullptr)
			{
				const float progress = localUnlocked ? 0.f : (achievementProgress->progress / goal);
				const TSoftObjectPtr<UTexture2D>& image = localUnlocked ? achievement->unlockedTexture : achievement->lockedTexture;
				UAchievementPopupManager::Get()->QueuePopup(achievement->displayName, image, progress);
			}
		}
		else UE_LOG(AchievementLog, Log, TEXT("Achievement '%s' was already unlocked. Checking other platforms next."), *achievementId);

		if (!EnumHasAnyFlags(achievementProgress->unlockedOnPlatforms, GetSelectedPlatformAsEUnlockedPlatforms()))
		{
			const bool success = UAchievementPlatformsClass::SetPlatformAchievementProgress(achievement->platformData, achievementProgress->progress, localUnlocked);
			if (success && localUnlocked)
			{
				achievementProgress->unlockedOnPlatforms |= GetSelectedPlatformAsEUnlockedPlatforms();
			}
		}
		else UE_LOG(AchievementLog, Log, TEXT("Achievement '%s' was already unlocked on selected platform."), *achievementId);

		return true;
	}
	UE_LOG(AchievementLog, Error, TEXT("Could not find achievement progress for '%s'"), *achievementId);
	return false;
}

void UAchievementManagerSubSystem::DeleteAchievementPopup()
{
	UAchievementPopupManager::Get()->DeleteFirstWidgetInstance();
}

void UAchievementManagerSubSystem::RetroactivelyUpdateAchievementsOnPlatforms()
{
	if (UAchievementPlatformsClass::achievementPlatformInitialized)
	{
		const auto& progressAchievements = UAchievementManagerSubSystem::Get()->achievementsProgress;
		const auto& achievementsData = UAchievementPluginSettings::Get()->achievementsData;

		for (const auto& achievement : achievementsData)
		{
			if (const auto& progress = progressAchievements.Find(achievement.Value.GetLinkID()))
			{
				const bool success = UAchievementPlatformsClass::SetPlatformAchievementProgress(achievement.Value.platformData,
																								progress->progress,
																								EnumHasAnyFlags(progress->unlockedOnPlatforms, EUnlockedPlatforms::Local));
				if (!success)
				{
					UE_LOG(AchievementPlatformLog, Error, TEXT("Platform has not been set up yet, cannot retroactively unlock achievements!"));
					return;
				}
			}
			else UE_LOG(AchievementLog, Warning, TEXT("Cannot find progress by Link Id '%d'"), achievement.Value.GetLinkID());
		}
	}
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
			RetroactivelyUpdateAchievementsOnPlatforms();
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