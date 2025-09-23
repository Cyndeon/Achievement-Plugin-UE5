#pragma once

#include "AchievementStructs.h"
#include "../ThirdParty/steamworks_sdk_162/sdk/public/steam/steam_api.h"

class SteamCallbacksClass;
class ACHIEVEMENTPLUGIN_API SteamAchievementsClass
{
public:
	static bool Initialize();
	static void Shutdown();
	static void Tick();
	static TMap<FString, FAchievementData> GetSteamAchievementsAsAchievementDataMap();

	static bool SetSteamAchievementProgress(const FAchievementPlatformData& achievementData, float progress, bool unlocked);
	static bool DeleteSteamAchievementProgress(const FAchievementPlatformData& achievementData);
	static bool DeleteAllSteamAchievementProgress();

	static bool& GetPlatformInitialized();

private:
	static int32 m_appId;
	static TUniquePtr<SteamCallbacksClass> m_steamCallbacksClass;
};

class ACHIEVEMENTPLUGIN_API SteamCallbacksClass
{
public:
	SteamCallbacksClass();
	// callbacks for the Steam API
	STEAM_CALLBACK(SteamCallbacksClass, OnUserStatsReceived, UserStatsReceived_t,
				   m_CallbackUserStatsReceived);
	STEAM_CALLBACK(SteamCallbacksClass, OnUserStatsStored, UserStatsStored_t,
				   m_CallbackUserStatsStored);
	STEAM_CALLBACK(SteamCallbacksClass, OnAchievementStored,
				   UserAchievementStored_t, m_CallbackAchievementStored);
};