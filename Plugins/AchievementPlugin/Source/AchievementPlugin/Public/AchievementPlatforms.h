#pragma once
#include "AchievementPlatformsEnum.h"
#include "AchievementStructs.h"

#include "../ThirdParty/steamworks_sdk_162/sdk/public/steam/steam_api.h"


class ACHIEVEMENTPLUGIN_API SteamAchievementsClass
{
	static SteamAchievementsClass* m_instance;
public:
	SteamAchievementsClass();
	static SteamAchievementsClass* Get()
	{
		if (!m_instance)
		{
			m_instance = new SteamAchievementsClass();
		}
		return m_instance;
	}
	bool Initialize();
	static void Shutdown();
	static void Tick();
	bool SetSteamAchievementProgress(const FString& achievementId, int32 progress, bool unlocked);

	// callbacks, not meant to be touched at all
	STEAM_CALLBACK(SteamAchievementsClass, OnUserStatsReceived, UserStatsReceived_t,
				   m_CallbackUserStatsReceived);
	STEAM_CALLBACK(SteamAchievementsClass, OnUserStatsStored, UserStatsStored_t,
				   m_CallbackUserStatsStored);
	STEAM_CALLBACK(SteamAchievementsClass, OnAchievementStored,
				   UserAchievementStored_t, m_CallbackAchievementStored);

private:
	int32 m_appId = 0;
	bool m_initialized = false;
};

// Basically a wrapper class for all different platforms
class ACHIEVEMENTPLUGIN_API UAchievementPlatformsClass : public UObject, public FTickableGameObject
{
public:
	UAchievementPlatformsClass()
	{
		selectedPlatform = LOCALONLY;
	}
	static UAchievementPlatformsClass* Get()
	{
		if (auto* got = GetMutableDefault<UAchievementPlatformsClass>())
			return got;
		return nullptr;
	}

	bool InitializePlatform(const EAchievementPlatforms platform);
	static void ShutdownPlatform();

	bool SetPlatformAchievementProgress(const FAchievementPlatformIds& platformIds, int32 progress, bool unlocked) const;

	void Tick(float DeltaTime) override;

	// Steam Specific
	static void CreateSteamAppIdFile(const int32 appId);

	bool platformInitialized = false;
	static EAchievementPlatforms selectedPlatform;
};

// other achievement classes