// -------------------------------------------------------------
// Copyright 2025 Justin Comans. All rights reserved.         ||
// -------------------------------------------------------------


#pragma once

#include <eos_achievements_types.h>
#include <eos_auth_types.h>
#include <eos_connect_types.h>
#include <eos_stats_types.h>
#include <eos_types.h>

#include "AchievementStructs.h"

class ACHIEVEMENTPLUGIN_API EpicGamesAchievementsClass
{
	static TUniquePtr<EpicGamesAchievementsClass> m_instance;
public:
	static bool InitializeEos();
	static void Shutdown();
	static void Tick();
	static TMap<FString, FAchievementData> GetEpicAchievementsAsAchievementDataMap();

	static bool SetEpicAchievementProgress(const FAchievementPlatformData& achievementData, float progress, bool unlocked);

	static bool& GetPlatformInitialized();
private:
	static void EOS_CALL OnConnectLoginComplete(const EOS_Connect_LoginCallbackInfo* data);
	static void EOS_CALL OnLoginComplete(const EOS_Auth_LoginCallbackInfo* data);
	static void EOS_CALL OnIngestStatsComplete(const EOS_Stats_IngestStatCompleteCallbackInfo* data);
	static void EOS_CALL OnAchievementUnlockComplete(const EOS_Achievements_OnUnlockAchievementsCompleteCallbackInfo* data);
	static void EOS_CALL OnCreateUserComplete(const EOS_Connect_CreateUserCallbackInfo* data);
	static void EOS_CALL OnQueryDefinitionsComplete(const EOS_Achievements_OnQueryDefinitionsCompleteCallbackInfo* data);

	// this will Log all found achievements
	static void VerifyAchievements();

	static EOS_HPlatform m_platformHandle;
	static EOS_ProductUserId m_productUserId;
	static bool m_eosInitialized;
	static FEventRef m_waitEvent;
	static float m_waitTime; // how long the event will wait for before continuing anyway
};