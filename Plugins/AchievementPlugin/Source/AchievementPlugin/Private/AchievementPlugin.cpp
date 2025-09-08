// Copyright Epic Games, Inc. All Rights Reserved.

#include "AchievementPlugin.h"

#if WITH_EDITOR
#include "ISettingsModule.h" 
#include "ISettingsSection.h"
#endif
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

	if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, Savestuff))
	{
		if (Savestuff) // only when checked
		{
			// attempt to save data here:
			FAchievementProgress testingThingy = FAchievementProgress("TestChiev", 64, true, FDateTime::Now().ToString());
			// From any class that has access to the engine
			if (UAchievementManager* achievementMgr = GEngine->GetEngineSubsystem<UAchievementManager>())
			{
				achievementMgr->GetSaveManager()->SaveProgressAsync(TArray<FAchievementProgress>{testingThingy}, defaultSlotName, defaultSlotIndex);
			}

			// Reset so it can be clicked again
			Savestuff = false;

			// Force the package to be marked as dirty and save
			(void)MarkPackageDirty();
		}
	}

	// if a new achievement got added, set the key's name to a default name
	else if (changedPropertyName == GET_MEMBER_NAME_CHECKED(UAchievementPluginSettings, achievements))
	{
		for (auto& chiev : achievements)
		{
			if (chiev.Key.IsEmpty())
			{
				chiev.Key = FString(TEXT("Achievement ")) + FString::FromInt(achievements.Num());
				break;
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
	// this will create a new achievement and then set the runtime's stats to this stuff.
	const FAchievementProgress temp{ "test", 12,true, FDateTime::Now().ToString() };
	const FString word = "key" + achievements.Num();
	auto& chiev = achievements.Add(word, FAchievementSettings());
	chiev.currentProgress = temp;
}

void UAchievementManager::Initialize(FSubsystemCollectionBase& collection)
{
	Super::Initialize(collection);

	m_saveManager = NewObject<UAchievementSaveManager>(this);
	// CALL LOAD SAVE DATA FUNCTION HERE
}

void UAchievementManager::Deinitialize()
{
	Super::Deinitialize();

	// CALL SAVE DATA FUNCTION HERE
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAchievementPluginModule, AchievementPlugin)