// Copyright Epic Games, Inc. All Rights Reserved.

#include "AchievementPlugin.h"

#if WITH_EDITOR
#include "ISettingsModule.h" 
#include "ISettingsSection.h"
#endif
#include "AchievementLogCategory.h"
#include "Misc/MessageDialog.h"
#include "USaveSystem.h"


#define LOCTEXT_NAMESPACE "FAchievementPluginModule"

void FAchievementPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

#if WITH_EDITOR
	 // Register with settings system to appear in Project Settings
	if (ISettingsModule* settingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		settingsModule->RegisterSettings("Project", "Plugins", "AchievementPlugin",
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
		// Unregister from settings system
	if (ISettingsModule* settingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		settingsModule->UnregisterSettings("Project", "Plugins", "AchievementPlugin");
	}
#endif
}

#if WITH_EDITOR
void UAchievementPluginSettings::PostEditChangeProperty(FPropertyChangedEvent& propertyChangedEvent)
{
	const FName changedPropertyName = propertyChangedEvent.GetPropertyName();

	// if the "button" was pressed (the boolean value changed)
	if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, loadRuntimeStatsButton))
	{
		if (loadRuntimeStatsButton) // only when checked
		{
			UpdateRuntimeStats();

			// Reset so it can be clicked again
			loadRuntimeStatsButton = false;

			// Force the package to be marked as dirty and save
#if WITH_EDITOR
			(void)MarkPackageDirty();

			// Force immediate save
			TryUpdateDefaultConfigFile();
#endif
		}
	}

	// TEMP BUTTON!!!!!!!!!! DELETE THIS ONCE DONE TESTING!
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, Savestuff))
	{
		if (Savestuff) // only when checked
		{
			// From any class that has access to the engine
			auto* manager = UAchievementManager::Get();
			manager->GetSaveManager()->SaveProgressAsync(manager->achievementsProgress);

			// Reset so it can be clicked again
			Savestuff = false;
		}
	}

	// TEMP BUTTON!!!!!!!!!! DELETE THIS ONCE DONE TESTING!
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, loadstuff))
	{
		if (loadstuff) // only when checked
		{
			// From any class that has access to the engine
			auto* manager = UAchievementManager::Get();
			manager->achievementsProgress = manager->GetSaveManager()->LoadProgress();

			manager->CleanupAchievements();

			// Reset so it can be clicked again
			loadstuff = false;
		}
	}

	// TEMP BUTTON!!!!!!!!!! DELETE THIS ONCE DONE TESTING!
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, progressStuff))
	{
		if (progressStuff) // only when checked
		{
			// From any class that has access to the engine
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
	}

	// if a new achievement got added, set the key's name to a default name	
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, achievementsData))
	{
		for (auto& chiev : achievementsData)
		{
			if (chiev.Key.IsEmpty())
			{
				auto newKey = FString(TEXT("Achievement ")) + FString::FromInt(achievementsData.Num());
				chiev.Key = newKey;

				// auto* manager = UAchievementManager::Get();
				// 
				// FAchievementProgress& newProgress = manager->achievementsProgress.AddDefaulted_GetRef();
				// newProgress.key = 
				// UE_LOG(AchievementLog, Log, TEXT("Created a new achievement for ID '%s'"), *achievementPair.Key);
				// break;
			}
		}
	}

	else
	{
		Super::PostEditChangeProperty(propertyChangedEvent);
	}
}
#endif

void UAchievementPluginSettings::UpdateRuntimeStats()
{
	// this will create a new achievement and then set the runtime stats variable to the actual stats
	const auto progressData = UAchievementManager::Get()->achievementsProgress;
	for (const auto& progress : progressData)
	{
		if (achievementsData.Contains(progress.key))
		{
			achievementsData[progress.key].currentProgress = progress;
		}
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


	// Create a set of existing achievement IDs for O(1) lookup
	TSet<FString> existingIDs;
	for (const FAchievementProgress& progress : achievementsProgress)
	{
		existingIDs.Add(progress.key);
	}

	// Add missing achievements progress
	const auto& data = settings->achievementsData;
	for (const auto& achievementPair : data)
	{
		if (!existingIDs.Contains(achievementPair.Key))
		{
			FAchievementProgress& newProgress = achievementsProgress.AddDefaulted_GetRef();
			newProgress.key = achievementPair.Key;
			UE_LOG(AchievementLog, Log, TEXT("Created a new achievement for ID '%s'"), *achievementPair.Key);
		}
	}
}

void UAchievementManager::CleanupAchievements()
{
	// Remove any progress entries that don't exist in settings anymore
	UAchievementPluginSettings* settings = UAchievementPluginSettings::Get();

	const int startingCount = achievementsProgress.Num();

	// Remove any progress entries that don't exist in settings anymore
	achievementsProgress.RemoveAll([settings](const FAchievementProgress& progress)
								   {
									   const bool bShouldRemove = !settings->achievementsData.Contains(progress.key);

									   if (bShouldRemove)
									   {
										   UE_LOG(AchievementLog, Warning, TEXT("Removing progress for deleted achievement: %s"), *progress.key);
									   }

									   return bShouldRemove;
								   });
	// log how many achievements were removed if any were
	const int removedAchievements = startingCount - achievementsProgress.Num();
	if (removedAchievements != 0)
		UE_LOG(AchievementLog, Log, TEXT("Cleanup finished, deleted achievement progress for %d achievements."), removedAchievements)
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAchievementPluginModule, AchievementPlugin)