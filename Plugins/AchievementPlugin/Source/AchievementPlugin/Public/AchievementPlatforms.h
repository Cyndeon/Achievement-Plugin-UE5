#pragma once
#include "AchievementPlatformsEnum.h"
#include "AchievementStructs.h"

#include "AchievementPlatforms.generated.h"


UCLASS()
class ACHIEVEMENTPLUGIN_API UAchievementPlatformsClass : public UObject, public FTickableGameObject
{
	GENERATED_BODY()
public:
	UAchievementPlatformsClass()
	{
		selectedPlatform = LOCALONLY;
		achievementPlatformInitialized = false;
	}
	static UAchievementPlatformsClass* Get()
	{
		if (auto* got = GetMutableDefault<UAchievementPlatformsClass>())
			return got;
		return nullptr;
	}

	bool InitializePlatform(const EAchievementPlatforms platform);
	static void ShutdownPlatform();

	static bool SetPlatformAchievementProgress(const FAchievementPlatformData& platformData, int32 progress, bool unlocked);
	static bool PlatformDeleteAchievementProgress(const FAchievementPlatformData& platformData);
	static bool PlatformDeleteAllAchievementProgress();

	static TMap<FString, FAchievementData> GetPlatformAchievementsAsAchievementDataMap();

	// overrides for the Tickable
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(UAchievementPlatformsClass, STATGROUP_Tickables);
	}

	// Steam Specific
	static void CreateSteamAppIdFile(const int32 appId);

	static bool achievementPlatformInitialized;

	static EAchievementPlatforms selectedPlatform;
};

// other achievement classes