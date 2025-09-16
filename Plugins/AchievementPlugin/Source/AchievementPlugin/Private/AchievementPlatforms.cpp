// otherwise it will complain about logging using %s instead of %hs, even though %hs gives compile errors
// ReSharper disable CppPrintfBadFormat

#include "AchievementPlatforms.h"

#include "AchievementLogCategory.h"
#include "AchievementPlugin.h"
#include "../ThirdParty/steamworks_sdk_162/sdk/public/steam/steam_api.h"

bool SteamAchievementsClass::Initialize()
{
	const auto* settings = UAchievementPluginSettings::Get();
#if WITH_EDITOR
	// sets the environment variable for SteamAppID during editor (basically telling SteamAPI what SteamAppId is)
	const FString appIdString = FString::Printf(TEXT("%d"), settings->GetSteamAppID());
	FPlatformMisc::SetEnvironmentVar(TEXT("SteamAppId"), *appIdString);
#endif

	// just to make sure the file exists
	UAchievementPlatformsClass::Get()->CreateSteamAppIdFile(settings->GetSteamAppID());

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
			return bSuccess;
		}
	}
	return false;
}

void SteamAchievementsClass::Shutdown()
{
	SteamAPI_Shutdown();
}

bool SteamAchievementsClass::IncreaseSteamAchievementProgress(FString& achievementId)
{
	// TODO
	return false;
}


bool UAchievementPlatformsClass::InitializePlatform(const EAchievementPlatforms platform)
{
	selectedPlatform = platform;
	switch (platform)
	{
		case STEAM:
		{
			platformInitialized = SteamAchievementsClass::Initialize();
			break;
		}

		default:break;
	}
	return platformInitialized;
}

void UAchievementPlatformsClass::ShutdownPlatform() const
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

bool UAchievementPlatformsClass::IncreasePlatformAchievementProgress(FAchievementSettings& achievement, int32 increase) const
{
	switch (selectedPlatform)
	{
		case STEAM:
		{
			return SteamAchievementsClass::IncreaseSteamAchievementProgress(achievement.steamID);
		}

		default:break;
	}
	return true;
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
