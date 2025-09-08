// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "AchievementStructs.h"

#include "AchievementPlugin.generated.h"

class FAchievementPluginModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Achievement System"))
class UAchievementPluginSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Achievements", meta = (DisplayName = "Default Profile Name",
			  Tooltip = "The default name used for the saved profiles for achievements"))
	FString defaultSlotName = "Achievements";
	UPROPERTY(EditAnywhere, Category = "Achievements", meta = (DisplayName = "Default Save Slot",
			  Tooltip = "The default name used for the save slots for achievements"))
	int32 defaultSlotIndex = 0;

	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category = "Achievements", meta = (DisplayName = "Achievements",
			  ToolTip = "Key: Name used for modifying achievements in Blueprint Nodes, Value: Achievement settings"))
	TMap<FString, FAchievementSettings> achievements;

	// This is the "fake button"
	UPROPERTY(EditAnywhere, Category = "Achievements", Transient, meta = (DisplayName = "Load/Update Runtime Stats",
			  Tooltip = "Enable this to update the runtime stats (progress) of the achievements"))
	bool loadRuntimeStatsButton = false;

	// This is the "fake button"
	UPROPERTY(EditAnywhere, Category = "Achievements", Transient, meta = (DisplayName = "SAVE TEST TEMP"))
	bool Savestuff = false;

	// Override to detect when the property is clicked
	virtual void PostEditChangeProperty(FPropertyChangedEvent& propertyChangedEvent) override;

private:
	void UpdateRuntimeStats();
};

class UAchievementSaveManager;
UCLASS()
// Note: If a default UI ever gets added, change this into a UGameEngineSubsystem and remove the buttons from the class above
class ACHIEVEMENTPLUGIN_API UAchievementManager : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	UAchievementSaveManager* GetSaveManager() const
	{
		return m_saveManager;
	}

	// Override the Initialize function to add loading the progress
	virtual void Initialize(FSubsystemCollectionBase& collection) override;

	// Override the Deinitialize function to add saving the progress
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadWrite, SaveGame)
	TArray<FAchievementProgress> achievementsProgress;

private:
	UPROPERTY()
	UAchievementSaveManager* m_saveManager;
};
