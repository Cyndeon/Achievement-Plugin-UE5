#pragma once
#include "AchievementPlatformsEnum.h"
#include "AchievementStructs.h"


class ACHIEVEMENTPLUGIN_API SteamAchievementsClass
{
public:
	static bool Initialize();
	static void Shutdown();
	static bool IncreaseSteamAchievementProgress(FString& achievementId);
};

// Basically a wrapper class for all different platforms
class ACHIEVEMENTPLUGIN_API UAchievementPlatformsClass : public UObject
{
public:
	UAchievementPlatformsClass()
	{
		selectedPlatform = LOCALONLY;
	}
	static UAchievementPlatformsClass* Get()
	{
		return GetMutableDefault<UAchievementPlatformsClass>();
	}

	bool InitializePlatform(const EAchievementPlatforms platform);
	void ShutdownPlatform() const;

	bool IncreasePlatformAchievementProgress(FAchievementSettings& achievement, int32 increase) const;

	// Steam Specific
	static void CreateSteamAppIdFile(const int32 appId);

	bool platformInitialized = false;
	EAchievementPlatforms selectedPlatform;
};

// other achievement classes