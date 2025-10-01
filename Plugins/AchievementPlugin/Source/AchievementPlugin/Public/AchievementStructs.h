#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include "AchievementPlatformsEnum.h"

#include "AchievementStructs.generated.h" 

// this will allow the achievement structs to be "linked", only inherited by the data version
USTRUCT(BlueprintType)
struct FLinkedStruct
{
	GENERATED_BODY()
public:
	explicit FLinkedStruct(const int32 key = 0)
	{
		m_linkID = key;
	}
	// sets a new link
	void OverrideLinkID(const int32 newKey)
	{
		m_linkID = newKey;
	}

	int32 GetLinkID() const
	{
		return m_linkID;
	}
private:
	UPROPERTY(config)
	int32 m_linkID = 0;
};


USTRUCT(BlueprintType)
// this struct has all the data that can be changed during runtime, ReadWrite for blueprints
struct ACHIEVEMENTPLUGIN_API FAchievementProgress
{
	GENERATED_BODY()
public:
	FAchievementProgress() = default;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Achievement Progress", meta = (ClampMin = "0"), SaveGame)
	float progress = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Achievement Progress", SaveGame)
	bool bIsAchievementUnlocked = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Achievement Progress", SaveGame)
	FString unlockedTime = "Never";
};

USTRUCT(BlueprintType)
struct ACHIEVEMENTPLUGIN_API FAchievementPlatformData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platforms", meta = (DisplayName = "Platform Upload Type"))
	TEnumAsByte<EAchievementUploadTypes> uploadType = Float;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Steam",
			  meta = (DisplayName = "Steam Achievement ID"))
	FString steamAchievementID = "";

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Steam",
			  meta = (DisplayName = "Steam Stat ID", Tooltip = "For progressive achievements (using Stats), please enter the Stat name used for tracking progress!"))
	FString steamStatID = "";

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Epic",
			  meta = (DisplayName = "Epic Achievement ID"))
	FString epicAchievementID = "";

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Epic",
			  meta = (DisplayName = "Epic Stat ID", Tooltip = "For progressive achievements (using Stats), please enter the Stat name used for tracking progress!"))
	FString epicStatID = "";
};

USTRUCT(BlueprintType)
// this struct has all the data that is inside the developer settings, ReadOnly for blueprints
struct ACHIEVEMENTPLUGIN_API FAchievementData : public FLinkedStruct
{
	GENERATED_BODY()
public:
#if WITH_EDITOR
	void UpdateProgressEditorOnly(const FAchievementProgress& progress)
	{
		m_currentProgress = progress;
	}
#endif
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Developer")
	bool isHidden = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Public")
	FText displayName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Public")
	FText description;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Public")
	TSoftObjectPtr<UTexture2D> lockedTexture;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Public")
	TSoftObjectPtr<UTexture2D> unlockedTexture;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Public", meta = (ClampMin = "0"))
	int32 progressGoal = 1;

	// Platform-specific identifiers
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platforms",
			  meta = (DisplayName = "Platform Data"))
	FAchievementPlatformData platformData;
#if WITH_EDITORONLY_DATA
private:
	// Runtime data (visible only here but not editable, NOT saved to config)
	UPROPERTY(VisibleAnywhere, Transient, Category = "Runtime Stats",
			  meta = (DisplayName = "Current Progress (NOT LIVE)"))
	FAchievementProgress m_currentProgress = FAchievementProgress();
#endif
};

USTRUCT(BlueprintType)
struct FSaveSlotSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(config, EditAnywhere, Category = "Achievements", meta = (DisplayName = "Profile Name"))
	FString slotName = "Achievements";
	UPROPERTY(config, EditAnywhere, Category = "Achievements", meta = (DisplayName = "Save Slot"))
	int32 slotIndex = 0;
};

// the information needed to initialize EOS SDK
USTRUCT(BlueprintType)
struct FEpicGamesInfo
{
	GENERATED_BODY()
public:
	// mostly copied from EOS, just without the information filled in and I added UPROPERTY
	/** The product id for the running application, found on the dev portal */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platforms", meta = (DisplayName = "Product ID"))
	FString ProductId;
	/** The application id for the running application, found on the dev portal */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platforms", meta = (DisplayName = "Application ID"))
	FString ApplicationId;
	/** The sandbox id for the running application, found on the dev portal */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platforms", meta = (DisplayName = "Sandbox ID"))
	FString SandboxId;
	/** The deployment id for the running application, found on the dev portal */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platforms", meta = (DisplayName = "Deployment ID"))
	FString DeploymentId;
	/** Client id of the service permissions entry, found on the dev portal */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platforms", meta = (DisplayName = "Client Credentials ID"))
	FString ClientCredentialsId;
	/** Client secret for accessing the set of permissions, found on the dev portal */
	// Never explicitly share the client secret, especially when the client is used in a trusted server environment!!!!!
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platforms", meta = (DisplayName = "Client Secret Credentials ID"))
	FString ClientCredentialsSecret;
	/** Game name */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platforms", meta = (DisplayName = "Game Name"))
	FString GameName;
	/** Encryption key */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platforms", meta = (DisplayName = "Encryption Key (Optional)"))
	FString EncryptionKey;
};

USTRUCT(BlueprintType)
struct FAchievementWidgetSettings
{
	GENERATED_BODY()
public:
	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category = "Achievement UI Settings", meta = (DisplayName = "Achievement User Widget",
			  ToolTip = "The achievement widget to use for popups. If using a custom one, make sure to check the user guide to make sure it will work!"))
	TSubclassOf<UUserWidget> achievementWidget = nullptr;

	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category = "Achievement UI Settings", meta = (DisplayName = "Max popups to show at once"))
	int maxToShow = 3;

	UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category = "Achievement UI Settings", meta = (DisplayName = "Distance Between Popups",
			  ToolTip = "The distance in the y axis between multiple popups"))
	float distanceBetweenPopups = 120.f;
};
