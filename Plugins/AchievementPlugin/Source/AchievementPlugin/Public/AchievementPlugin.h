// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"
#include "CoreMinimal.h"
#include "AchievementPlatformsEnum.h"
#include "Engine/DeveloperSettings.h"
#include "AchievementStructs.h"
#include "Subsystems/EngineSubsystem.h"
#include "Engine/Engine.h"
#include "Engine/World.h"

#include "AchievementPlugin.generated.h"


class FAchievementPluginModule : public IModuleInterface
{
public:
	static FAchievementPluginModule* Get()
	{
		return FModuleManager::GetModulePtr<FAchievementPluginModule>("AchievementPlugin");
	}

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	// this is there to make sure the platform gets shut down if the program closes unexpectedly
	bool bHasPlatformShutDown = false;

	bool bWasManuallyInitialized = false;
};

UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Achievement System"))
class UAchievementPluginSettings : public UObject
{
	GENERATED_BODY()

	// used for hiding variables
	UFUNCTION()
	bool IsSteamPlatform() const
	{
		return m_achievementPlatform == EAchievementPlatforms::STEAM;
	}

public:
	UAchievementPluginSettings() = default;
	static UAchievementPluginSettings* Get()
	{
		return GetMutableDefault<UAchievementPluginSettings>();
	}
	TEnumAsByte<EAchievementPlatforms> GetAchievementPlatform() const
	{
		return m_achievementPlatform;
	}
	int32 GetSteamAppID() const
	{
		return m_steamAppID;
	}
	// returns whether platforms should be (de)initialized
	bool GetManuallyInitializePlatform() const
	{
		return m_initializePlatform;
	}
	int32 GetLinkIDByAchievementID(const FString& achievementId);

	UPROPERTY(config, EditAnywhere, Category = "Save Slot Settings", meta = (DisplayName = "Default Save Slot Settings",
			  Tooltip = "The defaults used for the saved profiles for achievementsData. Modifying this can cause old achievement progress to break"))
	FSaveSlotSettings defaultSaveSlotSettings = FSaveSlotSettings();

	// Note: has to be a TMap, TArray gave issues when modifying it in C++ and then trying to save it
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Achievements", meta = (DisplayName = "AchievementsData",
			  ToolTip = "Key: Name used for modifying achievementsData in Blueprint Nodes, Value: Achievement settings"))
	TMap<FString, FAchievementData> achievementsData;

	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category = "Achievement Settings", meta = (DisplayName = "Cleanup Achievements on Load",
			  ToolTip = "If enabled, will delete any achievement progress for achievements that no longer exist"))
	bool bCleanupAchievements = true;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category = "Achievements Settings Buttons", Transient, meta = (DisplayName = "Load/Update Runtime Stats",
			  Tooltip = "Enable this to update the runtime stats (progress) of the achievementsData"))
	bool bLoadRuntimeStatsButton = false;
	// TEMP DELETE
	UPROPERTY(EditAnywhere, Category = "Achievements Settings Buttons", Transient, meta = (DisplayName = "Force Save Achievments"))
	bool bForceSaveAchievements = false;
	// TEMP DELETE
	UPROPERTY(EditAnywhere, Category = "Achievements Settings Buttons", Transient, meta = (DisplayName = "Force Load Achievement Progress"))
	bool bForceLoadAchievementProgress = false;


	// Platform-dependant buttons
	UPROPERTY(EditAnywhere, Category = "Achievements Platform Buttons", Transient, meta = (DisplayName = "Force Download Steam Achievements", 
			  Tooltip="This will override all your achievements with those from Steam. Please note that Stats will still have to be set manually!",
			  EditCondition = "IsSteamPlatform", EditConditionHides))
	bool bForceDownloadSteamAchievements = false;
	UPROPERTY(EditAnywhere, Category = "Achievements Platform Buttons", Transient, meta = (DisplayName = "This cannot be undone unless you make a backup of your current DefaultGame.ini!",
			  Tooltip = "Start Download (might take a little bit depending on the amount of achievements!",
			  EditCondition = "IsSteamPlatform && bForceDownloadSteamAchievements", EditConditionHides))
	bool bForceDownloadSteamAchievementsSafetyCheck = false;

	// TEMP DELETE
	UPROPERTY(EditAnywhere, Category = "Achievements Settings Buttons", Transient, meta = (DisplayName = "PROGESS TEST TEMP RANDOM VALUES"))
	bool progressStuff = false;
#endif

#if WITH_EDITOR
	// Override to detect when the property is clicked
	virtual void PostEditChangeProperty(FPropertyChangedEvent& propertyChangedEvent) override;

	// marks the package dirty and attempts to save the config file
	void AttemptSave();

private:
	void UpdateRuntimeStats();
	void OverrideAchievementsWithThoseFromSelectedPlatform();
#endif
	// this is only used to "generate" the next ID for achievements
	UPROPERTY(config)
	int32 m_nextLinkID = 1;
private:

	// platform specific data
	UPROPERTY(EditAnywhere, config, Category = "Platform Settings", meta = (DisplayName = "Achievement Platform"))
	TEnumAsByte<EAchievementPlatforms> m_achievementPlatform;

	UPROPERTY(EditAnywhere, config, Category = "Platform Settings", meta = (DisplayName = "Initialize Platform",
			  Tooltip = "This will Initialize and Deinitialize the platform's API, disable this if you want to set it up yourself! If setting up manually, make sure to also call AchievementPlatformInitialized in your level blueprint!"))
	bool m_initializePlatform = true;

	UPROPERTY(EditAnywhere, config, Category = "Platform Settings", meta = (DisplayName = "Steam App ID", EditCondition = "IsSteamPlatform", EditConditionHides))
	int32 m_steamAppID;
};

class UAchievementSaveManager;
UCLASS()
// Note: If a default UI ever gets added, change this into a UGameEngineSubsystem and remove the buttons from the class above
class ACHIEVEMENTPLUGIN_API UAchievementManagerSubSystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	static UAchievementManagerSubSystem* Get();
	UAchievementSaveManager* GetSaveManager() const;

	// Override the Initialize function to add loading the progress
	virtual void Initialize(FSubsystemCollectionBase& collection) override;

	// Override the Deinitialize function to add saving the progress
	virtual void Deinitialize() override;

	// creates Progress for any achievements without them
	void InitializeAchievements();

	// this will remove any achievements progress towards achievements that no longer exist
	void CleanupAchievements();

	// Sets the progress for the achievement, including updating platforms
	bool IncreaseAchievementProgress(const FString& achievementId, float increase);

	UPROPERTY(BlueprintReadOnly, SaveGame, Category = "Achievements")
	// the 'Key' is the LinkID that the achievementData has
	TMap<int32, FAchievementProgress> achievementsProgress;

	UFUNCTION()
	static void OnWorldInitialized(const UWorld* world);
	UFUNCTION()
	static void OnWorldCleanup(const UWorld* world, bool bSessionEnded, bool bCleanupResources);
private:
	UPROPERTY()
	UAchievementSaveManager* m_saveManager;

	FDelegateHandle m_worldInitializedHandle;
	FDelegateHandle m_worldCleanupHandle;
};
