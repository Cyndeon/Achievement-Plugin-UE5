// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "AchievementStructs.h"
#include "Subsystems/EngineSubsystem.h"
#include "Engine/Engine.h"

#include "AchievementPlugin.generated.h"

class FAchievementPluginModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Achievement System"))
class UAchievementPluginSettings : public UObject
{
	GENERATED_BODY()

public:
	static UAchievementPluginSettings* Get()
	{
		return GetMutableDefault<UAchievementPluginSettings>();
	}

	UPROPERTY(config, EditAnywhere, Category = "Achievements", meta = (DisplayName = "Default Save Slot Settings",
			  Tooltip = "The defaults used for the saved profiles for achievementsData. Modifying this can cause old achievement progress to break"))
	FSaveSlotSettings defaultSaveSlotSettings = FSaveSlotSettings();

	// Note: has to be a TMap, TArray gave issues when modifying it in C++ and then trying to save it
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category = "Achievements", meta = (DisplayName = "AchievementsData",
			  ToolTip = "Key: Name used for modifying achievementsData in Blueprint Nodes, Value: Achievement settings"))
	TMap<FString, FAchievementSettings> achievementsData;

	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category = "Achievements", meta = (DisplayName = "Cleanup Achievements on Load",
			  ToolTip = "If enabled, will delete any achievement progress for achievements that no longer exist"))
	bool bCleanupAchievements = true;

#if WITH_EDITORONLY_DATA
	// This is the "button"
	UPROPERTY(EditAnywhere, Category = "Achievements", Transient, meta = (DisplayName = "Load/Update Runtime Stats",
			  Tooltip = "Enable this to update the runtime stats (progress) of the achievementsData"))
	bool loadRuntimeStatsButton = false;

	// TEMP
	UPROPERTY(EditAnywhere, Category = "Achievements", Transient, meta = (DisplayName = "SAVE TEST TEMP"))
	bool Savestuff = false;

	// TEMP
	UPROPERTY(EditAnywhere, Category = "Achievements", Transient, meta = (DisplayName = "LOAD TEST TEMP"))
	bool loadstuff = false;

	// TEMP
	UPROPERTY(EditAnywhere, Category = "Achievements", Transient, meta = (DisplayName = "PROGESS TEST TEMP RANDOM VALUES"))
	bool progressStuff = false;
#endif

#if WITH_EDITOR
	// Override to detect when the property is clicked
	virtual void PostEditChangeProperty(FPropertyChangedEvent& propertyChangedEvent) override;

	// marks the package dirty and attempts to save the config file
	void AttemptSave();
#endif

private:
	void UpdateRuntimeStats();
	// this is only used to "generate" the next ID for achievements
	// MAKE NOT VISIBLE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	UPROPERTY(VisibleAnywhere, config)
	int32 m_nextLinkID = 1;
};

class UAchievementSaveManager;
UCLASS()
// Note: If a default UI ever gets added, change this into a UGameEngineSubsystem and remove the buttons from the class above
class ACHIEVEMENTPLUGIN_API UAchievementManager : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	static UAchievementManager* Get();
	UAchievementSaveManager* GetSaveManager() const
	{
		return m_saveManager;
	}

	// Override the Initialize function to add loading the progress
	virtual void Initialize(FSubsystemCollectionBase& collection) override;

	// Override the Deinitialize function to add saving the progress
	virtual void Deinitialize() override;

	void InitializeAchievements();

	// this will remove any achievements progress towards achievements that no longer exist
	void CleanupAchievements();

	UPROPERTY(BlueprintReadOnly, SaveGame, Category = "Achievements")
	TArray<FAchievementProgress> achievementsProgress;

private:
	UPROPERTY()
	UAchievementSaveManager* m_saveManager;
};
