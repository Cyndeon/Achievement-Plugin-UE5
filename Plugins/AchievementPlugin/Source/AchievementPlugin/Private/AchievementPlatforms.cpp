// otherwise it will complain about logging using %s instead of %hs, even though %hs gives compile errors
// ReSharper disable CppPrintfBadFormat

#include "AchievementPlatforms.h"

#include "AchievementLogCategory.h"
#include "AchievementPlugin.h"

#pragma region Steam
SteamAchievementsClass* SteamAchievementsClass::m_instance = nullptr;

SteamAchievementsClass::SteamAchievementsClass() :
	m_CallbackUserStatsReceived(this, &SteamAchievementsClass::OnUserStatsReceived),
	m_CallbackUserStatsStored(this, &SteamAchievementsClass::OnUserStatsStored),
	m_CallbackAchievementStored(this, &SteamAchievementsClass::OnAchievementStored)
{}

bool SteamAchievementsClass::Initialize()
{
	m_initialized = false;

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
			m_initialized = true;
			return bSuccess;
		}
	}
	return false;
}

void SteamAchievementsClass::Shutdown()
{
	SteamAPI_Shutdown();
}

void SteamAchievementsClass::Tick()
{
	// run Steam's callbacks
	SteamAPI_RunCallbacks();
}

bool SteamAchievementsClass::SetSteamAchievementProgress(const FAchievementPlatformData& achievementData, const float progress, const bool unlocked) const
{
	if (m_initialized)
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
			switch (achievementData.uploadType)
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
					UE_LOG(AchievementPlatformLog, Error, TEXT("Achievement Type: %s is not supported for Steam uploads!"), *UEnum::GetValueAsString(achievementData.uploadType));
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

void SteamAchievementsClass::OnUserStatsReceived(UserStatsReceived_t* pCallback)
{
	if (pCallback->m_nGameID == SteamUtils()->GetAppID())
	{
		if (pCallback->m_eResult == k_EResultOK)
		{
			UE_LOG(AchievementPlatformLog, Log, TEXT("User stats received successfully!"));
			// Now it's safe to read/write stats and achievements
			m_initialized = true;
		}
		else
		{
			UE_LOG(AchievementPlatformLog, Error, TEXT("Failed to receive user stats: %d"), pCallback->m_eResult);
			m_initialized = false;
		}
	}
}

void SteamAchievementsClass::OnUserStatsStored(UserStatsStored_t* pCallback)
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

void SteamAchievementsClass::OnAchievementStored(UserAchievementStored_t* pCallback)
{
	if (pCallback->m_nGameID == SteamUtils()->GetAppID())
	{
		const FString achievementName = ANSI_TO_TCHAR(pCallback->m_rgchAchievementName);
		UE_LOG(AchievementPlatformLog, Log, TEXT("Steam Achievement Unlocked: %s"), *achievementName);
	}
}
#pragma endregion


EAchievementPlatforms UAchievementPlatformsClass::selectedPlatform;

bool UAchievementPlatformsClass::InitializePlatform(const EAchievementPlatforms platform)
{
	selectedPlatform = platform;
	switch (platform)
	{
		case STEAM:
		{
			platformInitialized = SteamAchievementsClass::Get()->Initialize();
			break;
		}

		default:break;
	}
	return platformInitialized;
}

void UAchievementPlatformsClass::ShutdownPlatform()
{
	switch (selectedPlatform)
	{
		case STEAM:
		{
			SteamAchievementsClass::Shutdown();
			break;
		}
		// no shutdown required
		case LOCALONLY:
		{
			break;
		}

		default:break;
	}
}

bool UAchievementPlatformsClass::SetPlatformAchievementProgress(const FAchievementPlatformData& platformData, const int32 progress, const bool unlocked) const
{
	switch (selectedPlatform)
	{
		case STEAM:
		{
			return SteamAchievementsClass::Get()->SetSteamAchievementProgress(platformData, progress, unlocked);
		}

		default:break;
	}
	return true;
}

void UAchievementPlatformsClass::Tick(float DeltaTime)
{
	switch (selectedPlatform)
	{
		case STEAM:
		{
			SteamAchievementsClass::Tick();
		}
		default:break;
	}
}

void UAchievementPlatformsClass::CreateSteamAppIdFile(const int32 appId)
{
	FString executableDir = "";
#if WITH_EDITOR
	// In editor, use the project directory (instead of Engine's folder)
	executableDir = FPaths::ProjectDir();
#else
	// In packaged game, use the executable directory
	executableDir = FPaths::GetPath(FPlatformProcess::ExecutablePath());
#endif
	const FString appIdFilePath = FPaths::Combine(executableDir, TEXT("steam_appid.txt"));

	UE_LOG(AchievementPlatformLog, Log, TEXT("Creating steam_appid.txt at: %s"), *appIdFilePath);

	// Write the App ID to the file (this will overwrite if file exists)
	const FString& appIdString = FString().FormatAsNumber(appId);

	if (FFileHelper::SaveStringToFile(appIdString, *appIdFilePath, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM))
	{
		UE_LOG(AchievementPlatformLog, Log, TEXT("Successfully created steam_appid.txt with App ID: %s"), *appIdString);
	}
	else
	{
		UE_LOG(AchievementPlatformLog, Error, TEXT("ERROR: Failed to create steam_appid.txt file"));
	}
}
