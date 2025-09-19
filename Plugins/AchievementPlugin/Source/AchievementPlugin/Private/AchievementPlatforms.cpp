// otherwise it will complain about logging using %s instead of %hs, even though %hs gives compile errors
// ReSharper disable CppPrintfBadFormat

#include "AchievementPlatforms.h"

#include "AchievementLogCategory.h"
#include "AchievementPlugin.h"
#include "SteamPlatformAchievements.h"

EAchievementPlatforms UAchievementPlatformsClass::selectedPlatform;
bool UAchievementPlatformsClass::achievementPlatformInitialized = false;

bool UAchievementPlatformsClass::InitializePlatform(const EAchievementPlatforms platform)
{
	selectedPlatform = platform;
	switch (platform)
	{
		case STEAM:
		{
			achievementPlatformInitialized = SteamAchievementsClass::Initialize();
			break;
		}

		default:break;
	}
	return achievementPlatformInitialized;
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

bool UAchievementPlatformsClass::SetPlatformAchievementProgress(const FAchievementPlatformData& platformData, const int32 progress, const bool unlocked)
{
	switch (selectedPlatform)
	{
		case STEAM:
		{
			return SteamAchievementsClass::SetSteamAchievementProgress(platformData, progress, unlocked);
		}

		default:break;
	}
	return true;
}

bool UAchievementPlatformsClass::PlatformDeleteAchievementProgress(const FAchievementPlatformData& platformData)
{
	switch (selectedPlatform)
	{
		case STEAM:
		{
			return SteamAchievementsClass::DeleteSteamAchievementProgress(platformData);
		}
		default:break;
	}
	return true;
}

bool UAchievementPlatformsClass::PlatformDeleteAllAchievementProgress()
{
	switch (selectedPlatform)
	{
		case STEAM:
		{
			return SteamAchievementsClass::DeleteAllSteamAchievementProgress();
		}
		default:break;
	}
	return true;
}

TMap<FString, FAchievementData> UAchievementPlatformsClass::GetPlatformAchievementsAsAchievementDataMap()
{
	switch (selectedPlatform)
	{
		case STEAM:
		{
			return SteamAchievementsClass::GetSteamAchievementsAsAchievementDataMap();
		}
		default:break;
	}
	UE_LOG(AchievementPlatformLog, Error, TEXT("ERROR: Could not retrieve platform achievements!"));
	return TMap<FString, FAchievementData>();
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
