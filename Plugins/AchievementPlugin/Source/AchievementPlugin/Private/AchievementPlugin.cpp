// Copyright Epic Games, Inc. All Rights Reserved.

#include "AchievementPlugin.h"
#include "Misc/MessageDialog.h"

#include "SaveSystem.h"

#define LOCTEXT_NAMESPACE "FAchievementPluginModule"

void FAchievementPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	 // Register settings
}

void FAchievementPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

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
	// if a new achievement got added, set the key's name
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

void UAchievementPluginSettings::UpdateRuntimeStats()
{
	// this will create a new achievement and then set the runtime's stats to this stuff.
	FAchievementProgress temp{ "test", 12,true,FDateTime::Now() };
	const FString word = "key" + achievements.Num();
	auto& chiev = achievements.Add(word, FAchievementSettings());
	chiev.currentProgress = temp;
}

void UAchievementManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// CALL LOAD SAVE DATA FUNCTION HERE
}

void UAchievementManager::Deinitialize()
{
	Super::Deinitialize();

	// CALL SAVE DATA FUNCTION HERE
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAchievementPluginModule, AchievementPlugin)