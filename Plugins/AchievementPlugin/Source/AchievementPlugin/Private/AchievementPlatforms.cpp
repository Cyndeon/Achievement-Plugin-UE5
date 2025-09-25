// otherwise it will complain about logging using %s instead of %hs, even though %hs gives compile errors
// ReSharper disable CppPrintfBadFormat

#include "AchievementPlatforms.h"

#include "AchievementLogCategory.h"
#include "AchievementPlugin.h"
	
#include "HAL/PlatformFilemanager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

// platform includes
#include "Platforms/SteamPlatformAchievements.h"
#include "Platforms/EpicGamesPlatformAchievements.h"

EAchievementPlatforms UAchievementPlatformsClass::selectedPlatform;
bool UAchievementPlatformsClass::achievementPlatformInitialized = false;

bool UAchievementPlatformsClass::InitializePlatform(const EAchievementPlatforms platform)
{
	selectedPlatform = platform;
	switch (platform)
	{
		case EAchievementPlatforms::STEAM:
		{
			achievementPlatformInitialized = SteamAchievementsClass::Initialize();
			break;
		}
		case EAchievementPlatforms::EOS:
		{
			achievementPlatformInitialized = EpicGamesAchievementsClass::InitializeEOS();
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
		case EAchievementPlatforms::STEAM:
		{
			SteamAchievementsClass::Shutdown();
			break;
		}
		case EAchievementPlatforms::EOS:
		{
			EpicGamesAchievementsClass::Shutdown();
			break;
		}

		default:break;
	}
}

bool UAchievementPlatformsClass::SetPlatformAchievementProgress(const FAchievementPlatformData& platformData, const float progress, const bool unlocked)
{
	switch (selectedPlatform)
	{
		case EAchievementPlatforms::STEAM:
		{
			return SteamAchievementsClass::SetSteamAchievementProgress(platformData, progress, unlocked);
		}
		case EAchievementPlatforms::EOS:
		{
			return EpicGamesAchievementsClass::SetEpicAchievementProgress(platformData, progress, unlocked);
		}

		default:break;
	}
	return true;
}

bool UAchievementPlatformsClass::PlatformDeleteAchievementProgress(const FAchievementPlatformData& platformData)
{
	switch (selectedPlatform)
	{
		case EAchievementPlatforms::STEAM:
		{
			return SteamAchievementsClass::DeleteSteamAchievementProgress(platformData);
		}
		case EAchievementPlatforms::EOS:
		{
			return EpicGamesAchievementsClass::DeleteEpicAchievementProgress(platformData);
		}
		default:break;
	}
	return true;
}

bool UAchievementPlatformsClass::PlatformDeleteAllAchievementProgress()
{
	switch (selectedPlatform)
	{
		case EAchievementPlatforms::STEAM:
		{
			return SteamAchievementsClass::DeleteAllSteamAchievementProgress();
		}
		case EAchievementPlatforms::EOS:
		{
			return EpicGamesAchievementsClass::DeleteAllEpicAchievementProgress();
		}
		default:break;
	}
	return true;
}

TMap<FString, FAchievementData> UAchievementPlatformsClass::GetPlatformAchievementsAsAchievementDataMap()
{
	switch (selectedPlatform)
	{
		case EAchievementPlatforms::STEAM:
		{
			return SteamAchievementsClass::GetSteamAchievementsAsAchievementDataMap();
		}
		case EAchievementPlatforms::EOS:
		{
			return EpicGamesAchievementsClass::GetEpicAchievementsAsAchievementDataMap();
		}
		default:break;
	}
	return TMap<FString, FAchievementData>();
}

void UAchievementPlatformsClass::Tick(float DeltaTime)
{
	if (!achievementPlatformInitialized) return;
	switch (selectedPlatform)
	{
		case EAchievementPlatforms::STEAM:
		{
			SteamAchievementsClass::Tick();
			break;
		}
		case EAchievementPlatforms::EOS:
		{
			EpicGamesAchievementsClass::Tick();
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
		UE_LOG(AchievementPlatformLog, Error, TEXT(" Failed to create steam_appid.txt file"));
	}
}
