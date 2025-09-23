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

void EpicGamesAchievementsClass::OnCreateUserComplete(const EOS_Connect_CreateUserCallbackInfo* data)
{
	if (data->ResultCode == EOS_EResult::EOS_Success)
	{
		m_productUserId = data->LocalUserId;
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
}


bool EpicGamesAchievementsClass::Initialize()
{
	m_instance = MakeUnique<EpicGamesAchievementsClass>();

	// due to a lack of proper help on the EOS SDK, I asked Claude.AI to help write the Init
	const auto& info = UAchievementPluginSettings::Get()->GetEOSInfo();

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
	platformOptions.Flags = EOS_PF_DISABLE_OVERLAY;

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
	if (m_platformHandle)
	{
		EOS_Platform_Tick(m_platformHandle);
	}
}

TMap<FString, FAchievementData> EpicGamesAchievementsClass::GetEpicAchievementsAsAchievementDataMap()
{
	return TMap<FString, FAchievementData>();
}

bool EpicGamesAchievementsClass::SetEpicAchievementProgress(const FAchievementPlatformData& achievementData, float progress, bool unlocked)
{
	if (GetPlatformInitialized() && m_platformHandle)
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

			// For simplicity, using synchronous approach - you might want async callbacks
			EOS_Achievements_UnlockAchievements(
				EOS_Platform_GetAchievementsInterface(m_platformHandle),
				&unlockOptions,
				nullptr,
				OnAchievementUnlockComplete
			);

			UE_LOG(AchievementPlatformLog, Log, TEXT("Telling Epic to unlock: %s"), *achievementData.epicAchievementID);

			bSuccess = true;
		}
		else
		{
			// Set stat progress (which may trigger achievement unlock if threshold is reached)
			// Convert the type to what EOS is expecting
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
				nullptr,
				OnIngestStatsComplete // No callback for now
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

bool EpicGamesAchievementsClass::DeleteEpicAchievementProgress(const FAchievementPlatformData& achievementData)
{
	return false;
}

bool EpicGamesAchievementsClass::DeleteAllEpicAchievementProgress()
{
	return false;
}

bool& EpicGamesAchievementsClass::GetPlatformInitialized()
{
	return UAchievementPlatformsClass::achievementPlatformInitialized;
}