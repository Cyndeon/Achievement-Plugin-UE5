// -------------------------------------------------------------
// Copyright 2025 Justin Comans. Licensed under CC BY 4.0.    ||
// -------------------------------------------------------------

#include "Platforms/EpicGamesPlatformAchievements.h"

#include "AchievementLogCategory.h"
#include "AchievementPlatforms.h"
#include "AchievementPlugin.h"

#include "eos_sdk.h"
#include "eos_platform_prereqs.h" 
#include "eos_init.h"
#include "GeneralProjectSettings.h"
#include "eos_auth.h"
#include "eos_stats.h"
#include "eos_achievements.h"

EOS_HPlatform EpicGamesAchievementsClass::m_platformHandle = nullptr;
EOS_ProductUserId EpicGamesAchievementsClass::m_productUserId = nullptr;
TUniquePtr<EpicGamesAchievementsClass> EpicGamesAchievementsClass::m_instance = nullptr;
bool EpicGamesAchievementsClass::m_eosInitialized = false;
FEventRef EpicGamesAchievementsClass::m_waitEvent;
float EpicGamesAchievementsClass::m_waitTime = 5.f;

void EpicGamesAchievementsClass::VerifyAchievements()
{
	if (!m_productUserId) return;

	// Query player achievements to see what's actually unlocked
	EOS_Achievements_QueryPlayerAchievementsOptions queryOptions = {};
	queryOptions.ApiVersion = EOS_ACHIEVEMENTS_QUERYPLAYERACHIEVEMENTS_API_LATEST;
	queryOptions.LocalUserId = m_productUserId;
	queryOptions.TargetUserId = m_productUserId;

	EOS_Achievements_QueryPlayerAchievements(
		EOS_Platform_GetAchievementsInterface(m_platformHandle),
		&queryOptions,
		m_instance.Get(),
		[](const EOS_Achievements_OnQueryPlayerAchievementsCompleteCallbackInfo* Data)
		{
			if (Data->ResultCode == EOS_EResult::EOS_Success)
			{
				UE_LOG(AchievementPlatformLog, Warning, TEXT("Successfully queried achievements"));

				// Get the count of achievements
				EOS_Achievements_GetPlayerAchievementCountOptions countOptions = {};
				countOptions.ApiVersion = EOS_ACHIEVEMENTS_GETPLAYERACHIEVEMENTCOUNT_API_LATEST;
				countOptions.UserId = Data->LocalUserId;

				const uint32_t achievementCount = EOS_Achievements_GetPlayerAchievementCount(
					EOS_Platform_GetAchievementsInterface(m_platformHandle),
					&countOptions
				);

				UE_LOG(AchievementPlatformLog, Warning, TEXT("Found %d achievements"), achievementCount);

				// Check each achievement
				for (uint32_t i = 0; i < achievementCount; i++)
				{
					EOS_Achievements_CopyPlayerAchievementByIndexOptions copyOptions = {};
					copyOptions.ApiVersion = EOS_ACHIEVEMENTS_COPYPLAYERACHIEVEMENTBYINDEX_API_LATEST;
					copyOptions.LocalUserId = Data->LocalUserId;
					copyOptions.TargetUserId = Data->TargetUserId;
					copyOptions.AchievementIndex = i;

					EOS_Achievements_PlayerAchievement* achievement = nullptr;
					const EOS_EResult result = EOS_Achievements_CopyPlayerAchievementByIndex(
						EOS_Platform_GetAchievementsInterface(m_platformHandle),
						&copyOptions,
						&achievement
					);

					if (result == EOS_EResult::EOS_Success && achievement)
					{
						const bool bUnlocked = (achievement->UnlockTime != EOS_ACHIEVEMENTS_ACHIEVEMENT_UNLOCKTIME_UNDEFINED);
						UE_LOG(AchievementPlatformLog, Warning, TEXT("Achievement '%hs': %s"),
							   achievement->AchievementId, bUnlocked ? TEXT("UNLOCKED") : TEXT("LOCKED"));

						EOS_Achievements_PlayerAchievement_Release(achievement);
					}
				}
			}
		}
	);
}

void LogProductUserId(const EOS_ProductUserId& id)
{
	// Convert Product User ID to string for logging
	char productUserIdString[EOS_PRODUCTUSERID_MAX_LENGTH + 1];
	int32_t bufferLen = sizeof(productUserIdString);
	EOS_ProductUserId_ToString(id, productUserIdString, &bufferLen);

	UE_LOG(AchievementPlatformLog, Warning, TEXT("Your Product User ID: %hs"), productUserIdString);
}


void EpicGamesAchievementsClass::OnCreateUserComplete(const EOS_Connect_CreateUserCallbackInfo* data)
{
	if (data->ResultCode == EOS_EResult::EOS_Success)
	{
		m_productUserId = data->LocalUserId;
		LogProductUserId(m_productUserId);
		UE_LOG(AchievementPlatformLog, Log, TEXT("EOS Connect User Created"));
	}
	else
	{
		UE_LOG(AchievementPlatformLog, Error, TEXT("Failed to create Connect user: %hs"), EOS_EResult_ToString(data->ResultCode));
	}
}

void EpicGamesAchievementsClass::OnConnectLoginComplete(const EOS_Connect_LoginCallbackInfo* data)
{
	if (data->ResultCode == EOS_EResult::EOS_Success)
	{
		m_productUserId = data->LocalUserId;  // Cache Product User ID
		LogProductUserId(m_productUserId);
		UE_LOG(AchievementPlatformLog, Log, TEXT("EOS Connect Login Success"));
	}
	else if (data->ResultCode == EOS_EResult::EOS_InvalidUser)
	{
		// User doesn't exist in Connect, create them
		UE_LOG(AchievementPlatformLog, Warning, TEXT("User not found in Connect, creating new user..."));
		EOS_Connect_CreateUserOptions createUserOptions = {};
		createUserOptions.ApiVersion = EOS_CONNECT_CREATEUSER_API_LATEST;
		createUserOptions.ContinuanceToken = data->ContinuanceToken;

		EOS_Connect_CreateUser(
			EOS_Platform_GetConnectInterface(m_platformHandle),
			&createUserOptions,
			m_instance.Get(),
			OnCreateUserComplete
		);
	}
	else
	{
		UE_LOG(AchievementPlatformLog, Error, TEXT("EOS Connect Login Failed: %hs"), EOS_EResult_ToString(data->ResultCode));
	}
}

void EpicGamesAchievementsClass::OnLoginComplete(const EOS_Auth_LoginCallbackInfo* data)
{
	if (data->ResultCode == EOS_EResult::EOS_Success)
	{
		UE_LOG(AchievementPlatformLog, Log, TEXT("Auth login successful"));

		// Get auth token and do Connect login
		EOS_Auth_CopyUserAuthTokenOptions autoTokenOptions = {};
		autoTokenOptions.ApiVersion = EOS_AUTH_COPYUSERAUTHTOKEN_API_LATEST;
		EOS_Auth_Token* authToken = nullptr;

		const EOS_EResult result = EOS_Auth_CopyUserAuthToken(
			EOS_Platform_GetAuthInterface(m_platformHandle),
			&autoTokenOptions,
			data->LocalUserId,
			&authToken
		);

		if (result == EOS_EResult::EOS_Success && authToken)
		{
			EOS_Connect_LoginOptions connectLoginOptions = {};
			connectLoginOptions.ApiVersion = EOS_CONNECT_LOGIN_API_LATEST;

			EOS_Connect_Credentials connectCredentials = {};
			connectCredentials.ApiVersion = EOS_CONNECT_CREDENTIALS_API_LATEST;
			connectCredentials.Type = EOS_EExternalCredentialType::EOS_ECT_EPIC;
			connectCredentials.Token = authToken->AccessToken;
			connectLoginOptions.Credentials = &connectCredentials;

			EOS_Connect_Login(
				EOS_Platform_GetConnectInterface(m_platformHandle),
				&connectLoginOptions,
				m_instance.Get(),
				OnConnectLoginComplete
			);

			EOS_Auth_Token_Release(authToken);
		}
	}
	else if (data->ResultCode == EOS_EResult::EOS_NotFound)
	{
		UE_LOG(AchievementPlatformLog, Warning, TEXT("No persistent auth found, trying Account Portal"));

		EOS_Auth_LoginOptions loginOptions = {};
		loginOptions.ApiVersion = EOS_AUTH_LOGIN_API_LATEST;

		EOS_Auth_Credentials credentials = {};
		credentials.ApiVersion = EOS_AUTH_CREDENTIALS_API_LATEST;
		credentials.Type = EOS_ELoginCredentialType::EOS_LCT_AccountPortal;
		credentials.Id = nullptr;
		credentials.Token = nullptr;
		loginOptions.Credentials = &credentials;

		EOS_Auth_Login(
			EOS_Platform_GetAuthInterface(m_platformHandle),
			&loginOptions,
			m_instance.Get(),
			OnLoginComplete
		);
	}
	else
	{
		UE_LOG(AchievementPlatformLog, Error, TEXT("EOS Login failed: %hs"), EOS_EResult_ToString(data->ResultCode));
	}
}

void EpicGamesAchievementsClass::OnIngestStatsComplete(const EOS_Stats_IngestStatCompleteCallbackInfo* data)
{
	// Taken directly from Epic's documentation

	if (data->ResultCode == EOS_EResult::EOS_Success)
	{
		// If the code gets here, the stats were ingested successfully.
		UE_LOG(AchievementPlatformLog, Log, TEXT("Epic stats were ingested (uploaded) successfully"))
	}
	else if (EOS_EResult_IsOperationComplete(data->ResultCode) == EOS_FALSE)
	{
		// If the code gets here, the operation is retrying, meaning it is not yet complete.
		return;
	}
	else
	{
		// If the code gets here, there was an error.
		UE_LOG(AchievementPlatformLog, Error, TEXT(" Epic could not ingest (upload) stats, error code '%d' - %hs"), static_cast<int>(data->ResultCode), EOS_EResult_ToString(data->ResultCode));
	}
}

void EpicGamesAchievementsClass::OnAchievementUnlockComplete(
	const EOS_Achievements_OnUnlockAchievementsCompleteCallbackInfo* data)
{
	if (data->ResultCode == EOS_EResult::EOS_Success)
	{
		UE_LOG(AchievementPlatformLog, Log, TEXT("Epic Achievement unlocked successfully"))
	}
	else if (EOS_EResult_IsOperationComplete(data->ResultCode) == EOS_FALSE)
	{
		// If the code gets here, the operation is retrying, meaning it is not yet complete.
		return;
	}
	else
	{
		// If the code gets here, there was an error; handle this however you need for your program.
		UE_LOG(AchievementPlatformLog, Error, TEXT(" Epic could not unlock achievement, error code '%d' - %hs"), static_cast<int>(data->ResultCode), EOS_EResult_ToString(data->ResultCode));
	}
	VerifyAchievements();
}


bool EpicGamesAchievementsClass::InitializeEos()
{
	m_instance = MakeUnique<EpicGamesAchievementsClass>();
	GetPlatformInitialized() = false;
	m_eosInitialized = false;

	// due to a lack of proper help on the EOS SDK, I asked Claude.AI to help write the Init
	const auto& info = UAchievementPluginSettings::Get()->GetEOSInfo();

	if (info.ProductId.IsEmpty() || info.SandboxId.IsEmpty() || info.DeploymentId.IsEmpty())
	{
		UE_LOG(AchievementPlatformLog, Error, TEXT("EOS data was not filled in properly! Aborting initialization of EOS."))
		return false;
	}

	EOS_InitializeOptions initOptions = {};
	initOptions.ApiVersion = EOS_INITIALIZE_API_LATEST;
	initOptions.ProductName = TCHAR_TO_ANSI(*info.GameName);
	FString version = "1.0";
	if (const UGeneralProjectSettings* projectSettings = GetDefault<UGeneralProjectSettings>())
	{
		version = projectSettings->ProjectVersion;
	}
	else
	{
		UE_LOG(AchievementPlatformLog, Error, TEXT(" Could not get project version!"));
	}
	initOptions.ProductVersion = TCHAR_TO_ANSI(*version);

	const EOS_EResult initResult = EOS_Initialize(&initOptions);
	if (initResult == EOS_EResult::EOS_AlreadyConfigured)
	{
		// if it was already configured, it has been set up correctly already, so just continue
		UE_LOG(AchievementPlatformLog, Warning, TEXT("EOS already initialized by Unreal"));
	}
	else if (initResult != EOS_EResult::EOS_Success)
	{
		UE_LOG(AchievementPlatformLog, Error, TEXT(" EOS_Initialize failed: %hs"),
			   EOS_EResult_ToString(initResult));
		return false;
	}


	// create Platform Interface
	EOS_Platform_Options platformOptions = {};
	platformOptions.ApiVersion = EOS_PLATFORM_OPTIONS_API_LATEST;
	platformOptions.bIsServer = EOS_FALSE;
#if WITH_EDITOR
	platformOptions.Flags = EOS_PF_DISABLE_OVERLAY;
#endif

	platformOptions.ProductId = TCHAR_TO_UTF8(*info.ProductId);
	platformOptions.SandboxId = TCHAR_TO_UTF8(*info.SandboxId);
	platformOptions.DeploymentId = TCHAR_TO_UTF8(*info.DeploymentId);
	platformOptions.ClientCredentials.ClientId = TCHAR_TO_UTF8(*info.ClientCredentialsId);
	platformOptions.ClientCredentials.ClientSecret = TCHAR_TO_UTF8(*info.ClientCredentialsSecret);

	m_platformHandle = EOS_Platform_Create(&platformOptions);
	if (!m_platformHandle)
	{
		UE_LOG(AchievementPlatformLog, Error, TEXT(" EOS_Platform_Create failed"));
		EOS_Shutdown();
		return false;
	}

	GetPlatformInitialized() = true;
	m_eosInitialized = true;
	UE_LOG(AchievementPlatformLog, Log, TEXT("Successfully created EOS platform."));


	// cache the user ID
	EOS_Auth_LoginOptions loginOptions = {};
	loginOptions.ApiVersion = EOS_AUTH_LOGIN_API_LATEST;

	// Use Epic Games Launcher credentials (if user is logged in)
	EOS_Auth_Credentials credentials = {};
	credentials.ApiVersion = EOS_AUTH_CREDENTIALS_API_LATEST;
	credentials.Type = EOS_ELoginCredentialType::EOS_LCT_PersistentAuth;
	credentials.Token = nullptr;
	credentials.Id = nullptr;

	loginOptions.Credentials = &credentials;

	EOS_Auth_Login(
		EOS_Platform_GetAuthInterface(m_platformHandle),
		&loginOptions,
		m_instance.Get(),
		OnLoginComplete // callback function
	);
	UE_LOG(AchievementPlatformLog, Log, TEXT("EOS_Auth_Login called - waiting for callback"));

	return true;
}

void EpicGamesAchievementsClass::Shutdown()
{
	return;
	// during testing, this seemed to cause errors, so I believe EOS already shuts it down for us

	// if (m_platformHandle)
	// {
	// 	EOS_Platform_Release(m_platformHandle);
	// 	m_platformHandle = nullptr;
	// }
	// 
	// EOS_Shutdown();
}

void EpicGamesAchievementsClass::Tick()
{
	if (m_platformHandle && m_eosInitialized)
	{
		EOS_Platform_Tick(m_platformHandle);
	}
}
void EOS_CALL EpicGamesAchievementsClass::OnQueryDefinitionsComplete(const EOS_Achievements_OnQueryDefinitionsCompleteCallbackInfo* Data)
{
	UE_LOG(AchievementPlatformLog, Log, TEXT("Query definitions callback triggered with result: %hs"),
		   EOS_EResult_ToString(Data->ResultCode));
	m_waitEvent->Trigger();
}

TMap<FString, FAchievementData> EpicGamesAchievementsClass::GetEpicAchievementsAsAchievementDataMap()
{
	if (!GetPlatformInitialized() || !m_platformHandle || !m_productUserId)
	{
		UE_LOG(AchievementPlatformLog, Error, TEXT("EOS not initialized or user not authenticated"));
		return TMap<FString, FAchievementData>();
	}

	TMap<FString, FAchievementData> achievementsData = TMap<FString, FAchievementData>();

	// First query achievement definitions
	EOS_Achievements_QueryDefinitionsOptions queryDefOptions = {};
	queryDefOptions.ApiVersion = EOS_ACHIEVEMENTS_QUERYDEFINITIONS_API_LATEST;
	queryDefOptions.LocalUserId = m_productUserId;

	EOS_Achievements_QueryDefinitions(
		EOS_Platform_GetAchievementsInterface(m_platformHandle),
		&queryDefOptions,
		nullptr,
		OnQueryDefinitionsComplete
	);

	// need to tick in order to receive callback
	Tick();
	m_waitEvent->Wait(m_waitTime);
	m_waitEvent->Reset();

	// Get achievement count
	EOS_Achievements_GetAchievementDefinitionCountOptions countOptions = {};
	countOptions.ApiVersion = EOS_ACHIEVEMENTS_GETACHIEVEMENTDEFINITIONCOUNT_API_LATEST;

	const uint32_t achievementCount = EOS_Achievements_GetAchievementDefinitionCount(
		EOS_Platform_GetAchievementsInterface(m_platformHandle),
		&countOptions
	);

	UE_LOG(AchievementPlatformLog, Log, TEXT("Found %d EOS achievements"), achievementCount);

	// Iterate through each achievement
	for (uint32_t i = 0; i < achievementCount; ++i)
	{
		EOS_Achievements_CopyAchievementDefinitionV2ByIndexOptions CopyOptions = {};
		CopyOptions.ApiVersion = EOS_ACHIEVEMENTS_COPYACHIEVEMENTDEFINITIONV2BYINDEX_API_LATEST;
		CopyOptions.AchievementIndex = i;

		EOS_Achievements_DefinitionV2* achievementDef = nullptr;
		const EOS_EResult result = EOS_Achievements_CopyAchievementDefinitionV2ByIndex(
			EOS_Platform_GetAchievementsInterface(m_platformHandle),
			&CopyOptions,
			&achievementDef
		);

		if (result == EOS_EResult::EOS_Success && achievementDef)
		{
			FAchievementData newAchievement;

			// Convert EOS data to your format
			FString achievementID = FString(achievementDef->AchievementId);
			newAchievement.isHidden = static_cast<bool>(achievementDef->bIsHidden);
			newAchievement.displayName = FText::FromString(FString(achievementDef->LockedDisplayName));
			newAchievement.description = FText::FromString(FString(achievementDef->LockedDescription));

			// Set platform data
			newAchievement.platformData.epicAchievementID = achievementID;
			if (achievementDef->StatThresholds && achievementDef->StatThresholdsCount > 0)
			{
				// If it's stat-based, get the stat name and threshold
				newAchievement.platformData.epicStatID = FString(achievementDef->StatThresholds[0].Name);
				newAchievement.progressGoal = achievementDef->StatThresholds[0].Threshold;
			}
			else
			{
				// Binary achievement
				newAchievement.progressGoal = 1;
			}

			// Add to map
			achievementsData.Add(achievementID, newAchievement);

			UE_LOG(AchievementPlatformLog, Log, TEXT("Added EOS achievement: %s - %s"),
				   *achievementID, *newAchievement.displayName.ToString());

			// Release the achievement definition
			EOS_Achievements_DefinitionV2_Release(achievementDef);
		}
	}

	return achievementsData;
}

bool EpicGamesAchievementsClass::SetEpicAchievementProgress(const FAchievementPlatformData& achievementData, float progress, bool unlocked)
{
	if (GetPlatformInitialized() && m_platformHandle && m_productUserId)
	{
		bool bSuccess = false;

		// if the achievement should be unlocked
		if (unlocked)
		{
			// Unlock the achievement directly
			EOS_Achievements_UnlockAchievementsOptions unlockOptions = {};
			unlockOptions.ApiVersion = EOS_ACHIEVEMENTS_UNLOCKACHIEVEMENTS_API_LATEST;
			unlockOptions.UserId = m_productUserId;

			const char* achievementChar = TCHAR_TO_UTF8(*achievementData.epicAchievementID);
			unlockOptions.AchievementIds = &achievementChar;
			unlockOptions.AchievementsCount = 1;

			EOS_Achievements_UnlockAchievements(
				EOS_Platform_GetAchievementsInterface(m_platformHandle),
				&unlockOptions,
				m_instance.Get(),
				OnAchievementUnlockComplete
			);

			UE_LOG(AchievementPlatformLog, Log, TEXT("Telling Epic to unlock: %s"), *achievementData.epicAchievementID);

			bSuccess = true;
		}
		else
		{
			// Set stat progress
			EOS_Stats_IngestStatOptions ingestOptions = {};
			ingestOptions.ApiVersion = EOS_STATS_INGESTSTAT_API_LATEST;
			ingestOptions.LocalUserId = m_productUserId;
			ingestOptions.TargetUserId = m_productUserId;

			EOS_Stats_IngestData ingestData = {};
			ingestData.StatName = TCHAR_TO_UTF8(*achievementData.epicStatID);
			ingestData.IngestAmount = static_cast<int32>(progress);

			ingestOptions.Stats = &ingestData;
			ingestOptions.StatsCount = 1;

			EOS_Stats_IngestStat(
				EOS_Platform_GetStatsInterface(m_platformHandle),
				&ingestOptions,
				m_instance.Get(),
				OnIngestStatsComplete
			);


			bSuccess = true;
		}

		if (bSuccess)
		{
			UE_LOG(AchievementPlatformLog, Log, TEXT("Telling Epic to update achievement stat: %s = %f"), *achievementData.epicAchievementID, progress);
			// EOS automatically syncs stats, no need for explicit "store" like Steam
		}
		else
		{
			UE_LOG(AchievementPlatformLog, Error, TEXT(" SetStat/SetAchievement returned false for Epic"));
		}

		return bSuccess;
	}

	UE_LOG(AchievementPlatformLog, Error, TEXT(" Epic API wasn't initialized properly!"));
	return false;
}

bool& EpicGamesAchievementsClass::GetPlatformInitialized()
{
	return UAchievementPlatformsClass::achievementPlatformInitialized;
}