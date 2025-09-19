#include "SteamPlatformAchievements.h"

#include "AchievementLogCategory.h"
#include "AchievementPlatforms.h"
#include "AchievementPlugin.h"

int32 SteamAchievementsClass::m_appId = 0;
TUniquePtr<SteamCallbacksClass> SteamAchievementsClass::m_steamCallbacksClass = nullptr;

void SteamUploadTypeNotSupported(const EAchievementUploadTypes& type)
{
	UE_LOG(AchievementPlatformLog, Error, TEXT("Achievement Type: %s is not supported for Steam uploads!"), *UEnum::GetValueAsString(type));
}

bool SteamAchievementsClass::Initialize()
{
	// just in case temporarily set it to false
	GetPlatformInitialized() = false;

	// create the steam callbacks 
	m_steamCallbacksClass = MakeUnique<SteamCallbacksClass>();

	const auto* settings = UAchievementPluginSettings::Get();
#if WITH_EDITOR
	// sets the environment variable for SteamAppID during editor (basically telling SteamAPI what SteamAppId is)
	const FString appIdString = FString::Printf(TEXT("%d"), settings->GetSteamAppID());
	FPlatformMisc::SetEnvironmentVar(TEXT("SteamAppId"), *appIdString);
#endif

	m_appId = settings->GetSteamAppID();
	// just to make sure the file exists
	UAchievementPlatformsClass::Get()->CreateSteamAppIdFile(m_appId);

	if (!SteamAPI_IsSteamRunning())
	{
		UE_LOG(AchievementPlatformLog, Error, TEXT("ERROR: Steam is not running!"));
		return false;
	}

	UE_LOG(AchievementPlatformLog, Log, TEXT("Steam is running, attempting detailed initialization..."));

	// Use SteamAPI_InitEx for detailed error information
	SteamErrMsg errMsg;
	switch (const ESteamAPIInitResult initResult = SteamAPI_InitEx(&errMsg))
	{
		case k_ESteamAPIInitResult_OK:
			UE_LOG(AchievementPlatformLog, Log, TEXT("Steam API initialized successfully!"));
			break;

		case k_ESteamAPIInitResult_FailedGeneric:
			UE_LOG(AchievementPlatformLog, Error, TEXT("ERROR: Steam Init Failed: Generic failure"));
			UE_LOG(AchievementPlatformLog, Error, TEXT("Error message: %s"), ANSI_TO_TCHAR(errMsg));
			return false;

		case k_ESteamAPIInitResult_NoSteamClient:
			UE_LOG(AchievementPlatformLog, Error, TEXT("ERROR: Steam Init Failed: No Steam client running"));
			UE_LOG(AchievementPlatformLog, Error, TEXT("Error message: %s"), ANSI_TO_TCHAR(errMsg));
			return false;

		case k_ESteamAPIInitResult_VersionMismatch:
			UE_LOG(AchievementPlatformLog, Error, TEXT("ERROR: Steam Init Failed: Version mismatch between client and SDK"));
			UE_LOG(AchievementPlatformLog, Error, TEXT("Error message: %s"), ANSI_TO_TCHAR(errMsg));
			return false;

		default:
			UE_LOG(AchievementPlatformLog, Error, TEXT("ERROR: Steam Init Failed: Unknown error %d"), (int32)initResult);
			UE_LOG(AchievementPlatformLog, Error, TEXT("Error message: %s"), ANSI_TO_TCHAR(errMsg));
			return false;
	}

	// verify user has been found and is logged int
	if (SteamUser() && SteamUser()->BLoggedOn())
	{
		const CSteamID steamID = SteamUser()->GetSteamID();
		UE_LOG(AchievementPlatformLog, Log, TEXT("Steam User ID: %llu"), steamID.ConvertToUint64());

		if (SteamUserStats())
		{
			UE_LOG(AchievementPlatformLog, Log, TEXT("SteamUserStats interface ready"));
			const auto bSuccess = static_cast<bool>(SteamUserStats()->RequestUserStats(SteamUser()->GetSteamID()));
			UE_LOG(AchievementPlatformLog, Log, TEXT("RequestUserStats result: %s"), bSuccess ? TEXT("SUCCESS") : TEXT("FAILED"));
			GetPlatformInitialized() = true;

			return bSuccess;
		}
	}
	return false;
}

void SteamAchievementsClass::Shutdown()
{
	UE_LOG(AchievementPlatformLog, Log, TEXT("Shutting down Steam API"));
	SteamAPI_Shutdown();
}

void SteamAchievementsClass::Tick()
{
	// run Steam's callbacks
	SteamAPI_RunCallbacks();
}

TMap<FString, FAchievementData> SteamAchievementsClass::GetSteamAchievementsAsAchievementDataMap()
{
	if (!GetPlatformInitialized())
	{
		UE_LOG(AchievementPlatformLog, Error, TEXT("ERROR: Steam API not initialized yet, cannot get achievements!"));
		return TMap<FString, FAchievementData>();
	}

	const uint32 numAchievements = SteamUserStats()->GetNumAchievements();
	UE_LOG(AchievementPlatformLog, Log, TEXT("Found %d Steam achievements"), numAchievements);

	TMap<FString, FAchievementData> achievementsData = TMap<FString, FAchievementData>();

	// using uint32 since Steam api expects that
	for (uint32 i = 0; i < numAchievements; ++i)
	{
		// get achievement info
		const auto* achievementID = SteamUserStats()->GetAchievementName(i);
		if (!achievementID) continue;

		FAchievementData newAchievement;
		newAchievement.isHidden = static_cast<bool>(SteamUserStats()->GetAchievementDisplayAttribute(achievementID, "hidden"));

		newAchievement.displayName = FText::FromString(SteamUserStats()->GetAchievementDisplayAttribute(achievementID, "name"));
		newAchievement.description = FText::FromString(SteamUserStats()->GetAchievementDisplayAttribute(achievementID, "desc"));

		// Set platform data
		newAchievement.platformData.steamAchievementID = FString(ANSI_TO_TCHAR(achievementID));
		// stats cannot be downloaded with the achievement so these will have to be set manually

		// progress goals also are not given to us by Steam API
		newAchievement.progressGoal = 1; // Default for binary achievements

		// Add to map using achievement ID as key
		achievementsData.Add(FString(achievementID), newAchievement);

		UE_LOG(AchievementPlatformLog, Log, TEXT("Added achievement: %s - %s"),
			   *FString(achievementID), *newAchievement.displayName.ToString());
	}
	return achievementsData;
}

bool SteamAchievementsClass::SetSteamAchievementProgress(const FAchievementPlatformData& achievementData, const float progress, const bool unlocked)
{
	if (GetPlatformInitialized())
	{
		bool bSuccess = false;
		// if the achievement should be unlocked
		if (unlocked)
		{
			// Unlock any achievement (works for both one-time and incremental)
			bSuccess = SteamUserStats()->SetAchievement(TCHAR_TO_ANSI(*achievementData.steamAchievementID));
			UE_LOG(AchievementPlatformLog, Log, TEXT("Telling Steam to unlock: %s"), *achievementData.steamAchievementID);
		}
		else
		{
			// Set progress (only works for stat-based incremental achievements)
			// we have to convert the type to the type Steam is expecting
			switch (const auto& type = achievementData.uploadType)
			{
				case Float:
				{
					// no need to cast, progress is already a float
					bSuccess = SteamUserStats()->SetStat(TCHAR_TO_ANSI(*achievementData.steamStatID), progress);
					break;
				}
				case Int32:
				{
					bSuccess = SteamUserStats()->SetStat(TCHAR_TO_ANSI(*achievementData.steamStatID), static_cast<int32>(progress));
					break;
				}

				default:
				{
					SteamUploadTypeNotSupported(type);
					bSuccess = false;
				}
			}
		}

		// Store changes to Steam
		if (bSuccess)
		{
			UE_LOG(AchievementPlatformLog, Log, TEXT("Telling Steam to update achievement stat: %s = %f"), *achievementData.steamAchievementID, progress);
			SteamUserStats()->StoreStats();
		}
		else
			UE_LOG(AchievementPlatformLog, Error, TEXT("ERROR, SetStat/SetAchievevement returned false, could not update StoreStats()"));

		return bSuccess;
	}
	UE_LOG(AchievementPlatformLog, Error, TEXT("ERROR: Steam API wasn't initialized properly!"));
	return false;
}

bool SteamAchievementsClass::DeleteSteamAchievementProgress(const FAchievementPlatformData& achievementData)
{
	const auto& name = achievementData.steamAchievementID;
	UE_LOG(AchievementPlatformLog, Log, TEXT("Attempting to delete achievement: '%s' on Steam"), *name);
	return SteamUserStats()->ClearAchievement(TCHAR_TO_ANSI(*name));
}

bool SteamAchievementsClass::DeleteAllSteamAchievementProgress()
{
	const auto& achievements = UAchievementPluginSettings::Get()->achievementsData;
	for (const auto& achievement : achievements)
	{
		const auto& platformData = achievement.Value.platformData;

		const auto& achievementName = platformData.steamAchievementID;
		SteamUserStats()->ClearAchievement(TCHAR_TO_ANSI(*achievementName));
		UE_LOG(AchievementPlatformLog, Log, TEXT("Attempting to delete achievement: '%s' on Steam"), *achievementName);

		// if the achievement has any progress Stat, also set that to 0 (reset it)
		const auto& statName = achievement.Value.platformData.steamStatID;
		if (!statName.IsEmpty())
		{
			switch (const auto& type = platformData.uploadType)
			{
				case Float:
				{
					SteamUserStats()->SetStat(TCHAR_TO_ANSI(*statName), 0.f);
					break;
				}
				case Int32:
				{
					SteamUserStats()->SetStat(TCHAR_TO_ANSI(*statName), 0);
					break;
				}
				default:
				{
					SteamUploadTypeNotSupported(type);
					break;
				}
			}
			UE_LOG(AchievementPlatformLog, Log, TEXT("Attempting to delete Stat: '%s' on Steam"), *statName);
		}
	}

	return true;
}

bool& SteamAchievementsClass::GetPlatformInitialized()
{
	return UAchievementPlatformsClass::achievementPlatformInitialized;
}

SteamCallbacksClass::SteamCallbacksClass() :
	m_CallbackUserStatsReceived(this, &SteamCallbacksClass::OnUserStatsReceived),
	m_CallbackUserStatsStored(this, &SteamCallbacksClass::OnUserStatsStored),
	m_CallbackAchievementStored(this, &SteamCallbacksClass::OnAchievementStored)
{}

void SteamCallbacksClass::OnUserStatsReceived(UserStatsReceived_t* pCallback)
{
	if (pCallback->m_nGameID == SteamUtils()->GetAppID())
	{
		if (pCallback->m_eResult == k_EResultOK)
		{
			UE_LOG(AchievementPlatformLog, Log, TEXT("User stats received successfully!"));
			// Now it's safe to read/write stats and achievements
			SteamAchievementsClass::GetPlatformInitialized() = true;
		}
		else
		{
			UE_LOG(AchievementPlatformLog, Error, TEXT("Failed to receive user stats: %d"), pCallback->m_eResult);
			SteamAchievementsClass::GetPlatformInitialized() = false;
		}
	}
}

void SteamCallbacksClass::OnUserStatsStored(UserStatsStored_t* pCallback)
{
	if (pCallback->m_nGameID == SteamUtils()->GetAppID())
	{
		if (pCallback->m_eResult == k_EResultOK)
		{
			UE_LOG(AchievementPlatformLog, Log, TEXT("User stats stored successfully!"));
		}
		else
		{
			UE_LOG(AchievementPlatformLog, Error, TEXT("ERROR: Failed to store user stats: %d"), pCallback->m_eResult);
		}
	}
}

void SteamCallbacksClass::OnAchievementStored(UserAchievementStored_t* pCallback)
{
	if (pCallback->m_nGameID == SteamUtils()->GetAppID())
	{
		const FString achievementName = ANSI_TO_TCHAR(pCallback->m_rgchAchievementName);
		UE_LOG(AchievementPlatformLog, Log, TEXT("Steam Achievement Unlocked: %s"), *achievementName);
	}
}
#pragma endregion