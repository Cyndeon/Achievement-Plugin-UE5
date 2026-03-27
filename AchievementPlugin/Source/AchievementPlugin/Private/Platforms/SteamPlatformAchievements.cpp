// -------------------------------------------------------------
// Copyright 2025 Justin Comans. All rights reserved.         ||
// -------------------------------------------------------------

#include "Platforms/SteamPlatformAchievements.h"

#include "AchievementLogCategory.h"
#include "AchievementPlatforms.h"
#include "AchievementPlugin.h"
#include "Misc/Paths.h"
#include "Interfaces/IPluginManager.h"
#if WITH_EDITOR
#include "UObject/SavePackage.h"
#include "AssetRegistry/AssetRegistryModule.h"
#endif

int32 SteamAchievementsClass::m_appId = 0;
TUniquePtr<SteamCallbacksClass> SteamAchievementsClass::m_steamCallbacksClass = nullptr;
bool SteamAchievementsClass::m_steamInitialized = false;

#pragma region helpers
#if STEAMWORKS_INCLUDED
UTexture2D* CreateTextureFromSteamIcon(const int32 IconHandle, const FString& TextureName, const FString& PackagePath,
                                       const bool Grayscale = false)
{
	if (IconHandle == 0) return nullptr;

	uint32 Width = 0;
	uint32 Height = 0;
	if (!SteamUtils()->GetImageSize(IconHandle, &Width, &Height) || Width == 0 || Height == 0)
	{
		return nullptr;
	}

	TArray<uint8> ImageData;
	ImageData.SetNumZeroed(Width * Height * 4);

	if (!SteamUtils()->GetImageRGBA(IconHandle, ImageData.GetData(), ImageData.Num()))
	{
		return nullptr;
	}

#if WITH_EDITOR
	const FString FullPackagePath = PackagePath / TextureName;
	UPackage* Package = CreatePackage(*FullPackagePath);
	Package->FullyLoad();

	UTexture2D* Texture = NewObject<UTexture2D>(Package, *TextureName, RF_Public | RF_Standalone);
	Texture->Source.Init(Width, Height, 1, 1, TSF_BGRA8);

	uint8* MipData = Texture->Source.LockMip(0);
	for (uint32 i = 0; i < Width * Height; ++i)
	{
		const uint8 R = ImageData[i * 4 + 0];
		const uint8 G = ImageData[i * 4 + 1];
		const uint8 B = ImageData[i * 4 + 2];
		const uint8 A = ImageData[i * 4 + 3];

		if (Grayscale)
		{
			const uint8 Gray = static_cast<uint8>(0.299f * R + 0.587f * G + 0.114f * B);
			MipData[i * 4 + 0] = Gray; // B
			MipData[i * 4 + 1] = Gray; // G
			MipData[i * 4 + 2] = Gray; // R
		}
		else
		{
			MipData[i * 4 + 0] = B;
			MipData[i * 4 + 1] = G;
			MipData[i * 4 + 2] = R;
		}
		MipData[i * 4 + 3] = A;
	}
	Texture->Source.UnlockMip(0);

	Texture->CompressionSettings = TC_Default;
	Texture->MipGenSettings = TMGS_NoMipmaps;
	Texture->SRGB = true;
	Texture->UpdateResource();

	Texture->PostEditChange();
	Texture->MarkPackageDirty();

	FAssetRegistryModule::AssetCreated(Texture);

	const FString PackageFilename = FPackageName::LongPackageNameToFilename(
		FullPackagePath, FPackageName::GetAssetPackageExtension());

	FSavePackageArgs SaveArgs;
	SaveArgs.TopLevelFlags = RF_Public | RF_Standalone;
	UPackage::SavePackage(Package, Texture, *PackageFilename, SaveArgs);

	return Texture;
#else
	return nullptr;
#endif
}
#endif

void CleanAndCreateIconFolders(const FString& GamePath)
{
	const FString RelativePath = GamePath.StartsWith(TEXT("/Game/"))
		                             ? GamePath.RightChop(6)
		                             : GamePath;
	const FString AbsolutePath = FPaths::ProjectContentDir() / RelativePath;

	// delete old folder
	if (IFileManager::Get().DirectoryExists(*AbsolutePath))
	{
		IFileManager::Get().DeleteDirectory(*AbsolutePath, false, true);
	}

	// Create new structure
	IFileManager::Get().MakeDirectory(*(AbsolutePath / TEXT("UnlockedTextures")), true);
	IFileManager::Get().MakeDirectory(*(AbsolutePath / TEXT("LockedTextures")), true);
}

void SteamUploadTypeNotSupported(const EAchievementUploadTypes& type)
{
	UE_LOG(AchievementPlatformLog, Error, TEXT("Achievement Type: %s is not supported for Steam uploads!"),
	       *UEnum::GetValueAsString(type));
}
#pragma endregion

bool SteamAchievementsClass::Initialize()
{
	GetPlatformInitialized() = false;
	m_steamInitialized = false;
	const auto* settings = UAchievementPluginSettings::Get();

#if STEAMWORKS_INCLUDED
	// PRE-LOAD the Steam DLL from the plugin's Binaries folder
	FString pluginBaseDir = IPluginManager::Get().FindPlugin(TEXT("AchievementPlugin"))->GetBaseDir();
	const FString steamDllPath = FPaths::Combine(pluginBaseDir, TEXT("Binaries/Win64/steam_api64.dll"));

	UE_LOG(AchievementPlatformLog, Log, TEXT("Loading steam_api64.dll from: %s"), *steamDllPath);

	const void* steamDllHandle = FPlatformProcess::GetDllHandle(*steamDllPath);
	if (!steamDllHandle)
	{
		UE_LOG(AchievementPlatformLog, Error, TEXT("Failed to load steam_api64.dll from plugin directory!"));
		UE_LOG(AchievementPlatformLog, Error, TEXT("Expected location: %s"), *steamDllPath);
		return false;
	}

	UE_LOG(AchievementPlatformLog, Log, TEXT("Successfully pre-loaded steam_api64.dll"));

	// Now create the steam callbacks - delay-load will find the already-loaded DLL
	m_steamCallbacksClass = MakeUnique<SteamCallbacksClass>();
#else
	UE_LOG(AchievementPlatformLog, Error,
	       TEXT("Steamworks SDK has not been installed, please visit the documentation on how to install it!"));
	return false;
#endif

#if STEAMWORKS_INCLUDED
#if WITH_EDITOR
	const FString appIdString = FString::Printf(TEXT("%d"), settings->GetSteamAppID());
	FPlatformMisc::SetEnvironmentVar(TEXT("SteamAppId"), *appIdString);
#endif
	m_appId = settings->GetSteamAppID();
	UAchievementPlatformsClass::Get()->CreateSteamAppIdFile(m_appId);

	if (!SteamAPI_IsSteamRunning())
	{
		UE_LOG(AchievementPlatformLog, Error, TEXT("Steam is not running!"));
		return false;
	}

	UE_LOG(AchievementPlatformLog, Log, TEXT("Steam is running, attempting detailed initialization..."));

	SteamErrMsg errMsg;
	switch (const ESteamAPIInitResult initResult = SteamAPI_InitEx(&errMsg))
	{
	case k_ESteamAPIInitResult_OK:
		UE_LOG(AchievementPlatformLog, Log, TEXT("Steam API initialized successfully!"));
		break;
	case k_ESteamAPIInitResult_FailedGeneric:
		UE_LOG(AchievementPlatformLog, Error, TEXT("Steam Init Failed: Generic failure"));
		UE_LOG(AchievementPlatformLog, Error, TEXT("Error message: %s"), ANSI_TO_TCHAR(errMsg));
		return false;
	case k_ESteamAPIInitResult_NoSteamClient:
		UE_LOG(AchievementPlatformLog, Error, TEXT("Steam Init Failed: No Steam client running"));
		UE_LOG(AchievementPlatformLog, Error, TEXT("Error message: %s"), ANSI_TO_TCHAR(errMsg));
		return false;
	case k_ESteamAPIInitResult_VersionMismatch:
		UE_LOG(AchievementPlatformLog, Error, TEXT("Steam Init Failed: Version mismatch between client and SDK"));
		UE_LOG(AchievementPlatformLog, Error, TEXT("Error message: %s"), ANSI_TO_TCHAR(errMsg));
		return false;
	default:
		UE_LOG(AchievementPlatformLog, Error, TEXT("Steam Init Failed: Unknown error %d"), (int32)initResult);
		UE_LOG(AchievementPlatformLog, Error, TEXT("Error message: %s"), ANSI_TO_TCHAR(errMsg));
		return false;
	}

	if (SteamUser() && SteamUser()->BLoggedOn())
	{
		const CSteamID steamID = SteamUser()->GetSteamID();
		UE_LOG(AchievementPlatformLog, Log, TEXT("Steam User ID: %llu"), steamID.ConvertToUint64());

		if (SteamUserStats())
		{
			UE_LOG(AchievementPlatformLog, Log, TEXT("SteamUserStats interface ready"));
			const auto bSuccess = static_cast<bool>(SteamUserStats()->RequestUserStats(SteamUser()->GetSteamID()));
			UE_LOG(AchievementPlatformLog, Log, TEXT("RequestUserStats result: %s"),
			       bSuccess ? TEXT("SUCCESS") : TEXT("FAILED"));
			GetPlatformInitialized() = true;
			m_steamInitialized = true;
			return bSuccess;
		}
	}
	return false;
#endif
}

void SteamAchievementsClass::Shutdown()
{
#if STEAMWORKS_INCLUDED
	UE_LOG(AchievementPlatformLog, Log, TEXT("Shutting down Steam API"));
	SteamAPI_Shutdown();
#endif
}

void SteamAchievementsClass::Tick()
{
#if STEAMWORKS_INCLUDED
	if (!m_steamInitialized) return;
	// run Steam's callbacks
	SteamAPI_RunCallbacks();
#endif
}

TMap<FString, FAchievementData> SteamAchievementsClass::GetSteamAchievementsAsAchievementDataMap()
{
	if (!GetPlatformInitialized())
	{
		UE_LOG(AchievementPlatformLog, Error, TEXT(" Steam API not initialized yet, cannot get achievements!"));
		return TMap<FString, FAchievementData>();
	}
#if STEAMWORKS_INCLUDED
	const ISteamUserStats* UserStats = SteamUserStats();
	const ISteamUtils* Utils = SteamUtils();

	if (!UserStats || !Utils)
	{
		UE_LOG(AchievementPlatformLog, Error,
		       TEXT("Steam interfaces are null - try restarting the editor with Steam running"));
		return TMap<FString, FAchievementData>();
	}

	const uint32 numAchievements = SteamUserStats()->GetNumAchievements();
	UE_LOG(AchievementPlatformLog, Log, TEXT("Found %d Steam achievements"), numAchievements);

	TMap<FString, FAchievementData> achievementsData = TMap<FString, FAchievementData>();

	// set paths for textures
	// todo: make customizable paths in user settings!
	const FString IconsPath = "/Game/Achievements";
	// todo make function to get paths
	const FString UnlockedPath = IconsPath + "/UnlockedTextures";
	const FString LockedPath = IconsPath + "/LockedTextures";

	CleanAndCreateIconFolders(IconsPath);
	// using uint32 since Steam api expects that
	for (uint32 i = 0; i < numAchievements; ++i)
	{
		// get achievement info
		const auto* achievementID = SteamUserStats()->GetAchievementName(i);
		if (!achievementID) continue;

		FAchievementData newAchievement;
		newAchievement.isHidden = static_cast<bool>(SteamUserStats()->GetAchievementDisplayAttribute(
			achievementID, "hidden"));

		newAchievement.displayName = FText::FromString(
			SteamUserStats()->GetAchievementDisplayAttribute(achievementID, "name"));
		newAchievement.description = FText::FromString(
			SteamUserStats()->GetAchievementDisplayAttribute(achievementID, "desc"));

		// Get current state first
		bool bWasAchieved = false;
		SteamUserStats()->GetAchievement(achievementID, &bWasAchieved);

		// Temporarily unlock locally (no StoreStats so no notification)
		if (!bWasAchieved)
		{
			SteamUserStats()->SetAchievement(achievementID);
		}

		// Get the colored icon
		const int32 IconHandle = SteamUserStats()->GetAchievementIcon(achievementID);
		// make sure the icon exists

		bool bValidIcon = false;
		if (IconHandle != 0)
		{
			uint32 Width = 0;
			uint32 Height = 0;
			if (SteamUtils()->GetImageSize(IconHandle, &Width, &Height) && Width > 0 && Height > 0)
			{
				bValidIcon = true;
			}
		}

		// Create both textures from the colored icon
		if (bValidIcon)
		{
			const FString AchievementName = FString(ANSI_TO_TCHAR(achievementID));

			if (UTexture2D* UnlockedTex = CreateTextureFromSteamIcon(IconHandle, AchievementName, UnlockedPath, false))
			{
				newAchievement.unlockedTexture = TSoftObjectPtr<UTexture2D>(FSoftObjectPath(UnlockedTex));
			}

			if (UTexture2D* LockedTex = CreateTextureFromSteamIcon(IconHandle, AchievementName, LockedPath, true))
			{
				newAchievement.lockedTexture = TSoftObjectPtr<UTexture2D>(FSoftObjectPath(LockedTex));
			}
		}
		else
		{
			UE_LOG(AchievementPlatformLog, Warning, TEXT("No valid icon for achievement: %s"), *FString(achievementID));
		}

		// Revert to original state
		if (!bWasAchieved)
		{
			SteamUserStats()->ClearAchievement(achievementID);
		}

		// Set platform data
		newAchievement.platformData.steamAchievementID = FString(ANSI_TO_TCHAR(achievementID));
		// stats cannot be downloaded with the achievement so these will have to be set manually

		// progress goals also are not given to us by Steam API
		newAchievement.progressGoal = 1; // Default for one-time achievements

		// Add to map using achievement ID as key
		achievementsData.Add(FString(achievementID), newAchievement);

		UE_LOG(AchievementPlatformLog, Log, TEXT("Added achievement: %s - %s"),
		       *FString(achievementID), *newAchievement.displayName.ToString());
	}
	UE_LOG(AchievementPlatformLog, Log, TEXT("Successfully downloaded achievements"));

	return achievementsData;
#else
	return TMap<FString, FAchievementData>();
#endif
}

bool SteamAchievementsClass::SetSteamAchievementProgress(const FAchievementPlatformData& achievementData,
                                                         const float progress, const bool unlocked)
{
	if (GetPlatformInitialized())
	{
#if STEAMWORKS_INCLUDED
		bool bSuccess = false;
		// if the achievement should be unlocked
		if (unlocked)
		{
			// Unlock the achievement
			bSuccess = SteamUserStats()->SetAchievement(TCHAR_TO_ANSI(*achievementData.steamAchievementID));
			UE_LOG(AchievementPlatformLog, Log, TEXT("Telling Steam to unlock: %s"),
			       *achievementData.steamAchievementID);
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
					bSuccess = SteamUserStats()->SetStat(
						TCHAR_TO_ANSI(*achievementData.steamStatID), static_cast<int32>(progress));
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
			UE_LOG(AchievementPlatformLog, Log, TEXT("Telling Steam to update achievement stat: %s = %f"),
			       *achievementData.steamAchievementID, progress);
			SteamUserStats()->StoreStats();
		}
		else
			UE_LOG(AchievementPlatformLog, Error,
		       TEXT("ERROR, SetStat/SetAchievevement returned false, could not update StoreStats()"));

		return bSuccess;
#endif
	}
	UE_LOG(AchievementPlatformLog, Error, TEXT(" Steam API wasn't initialized properly!"));
	return false;
}

bool SteamAchievementsClass::DeleteSteamAchievementProgress(const FAchievementPlatformData& achievementData)
{
#if STEAMWORKS_INCLUDED
	if (GetPlatformInitialized())
	{
		const auto& name = achievementData.steamAchievementID;
		UE_LOG(AchievementPlatformLog, Log, TEXT("Attempting to delete achievement: '%s' on Steam"), *name);
		return SteamUserStats()->ClearAchievement(TCHAR_TO_ANSI(*name));
	}
	else
	{
		UE_LOG(AchievementPlatformLog, Error, TEXT(" Steam API wasn't initialized properly!"));
	}
#endif
	return false;
}

bool SteamAchievementsClass::DeleteAllSteamAchievementProgress()
{
#if STEAMWORKS_INCLUDED
	if (GetPlatformInitialized())
	{
		const auto& achievements = UAchievementPluginSettings::Get()->achievementsData;
		for (const auto& achievement : achievements)
		{
			const auto& platformData = achievement.Value.platformData;

			const auto& achievementName = platformData.steamAchievementID;
			SteamUserStats()->ClearAchievement(TCHAR_TO_ANSI(*achievementName));
			UE_LOG(AchievementPlatformLog, Log, TEXT("Attempting to delete achievement: '%s' on Steam"),
			       *achievementName);

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
#endif
	UE_LOG(AchievementPlatformLog, Error, TEXT(" Steam API wasn't initialized properly!"));
	return false;
}

bool& SteamAchievementsClass::GetPlatformInitialized()
{
	return UAchievementPlatformsClass::achievementPlatformInitialized;
}

SteamCallbacksClass::SteamCallbacksClass()
#if STEAMWORKS_INCLUDED
	:
	m_CallbackUserStatsReceived(this, &SteamCallbacksClass::OnUserStatsReceived),
	m_CallbackUserStatsStored(this, &SteamCallbacksClass::OnUserStatsStored),
	m_CallbackAchievementStored(this, &SteamCallbacksClass::OnAchievementStored)
#endif
{
}

#if STEAMWORKS_INCLUDED
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
			UE_LOG(AchievementPlatformLog, Error, TEXT(" Failed to store user stats: %d"), pCallback->m_eResult);
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
#endif
