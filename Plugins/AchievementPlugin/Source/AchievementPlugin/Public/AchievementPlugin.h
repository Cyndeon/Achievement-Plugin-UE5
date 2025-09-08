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
class ACHIEVEMENTPLUGIN_API UAchievementPluginSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category = "Achievements", meta = (DisplayName = "Achievements", 
			  ToolTip = "Key: Name used for modifying achievements in Blueprint Nodes, Value: Achievement settings"))
	TMap<FString, FAchievementSettings> achievements;

	// This is our "fake button"
	UPROPERTY(EditAnywhere, Category = "Achievements", Transient, meta = (DisplayName = "Load/Update Runtime Stats", 
			  Tooltip = "Enable this to update the runtime stats (progress) of the achievements"))
	bool loadRuntimeStatsButton = false;

	// Override to detect when the property is clicked
	virtual void PostEditChangeProperty(FPropertyChangedEvent& propertyChangedEvent) override;

private:
	void UpdateRuntimeStats();
};

UCLASS()
// UEngineSubSystem will allow the achievements to be loaded right away and allow them to be modified inside the developer settings
class UAchievementManager : public UGameInstanceSubsystem // NEEDS SOMETHING ELSE
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TArray<FAchievementProgress> achievementsProgress;

	// Override the Initialize function to add loading the progress
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	// Override the Deinitialize function to add saving the progress
	virtual void Deinitialize() override;
};
