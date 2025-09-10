#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"

#include "AchievementStructs.generated.h" 

USTRUCT(BlueprintType)
// this struct has all the data that can be changed during runtime, ReadWrite for blueprints
struct ACHIEVEMENTPLUGIN_API FAchievementProgress
{
	GENERATED_BODY()
public:
	FAchievementProgress(const int32 linkKey)
	{
		m_linkKey = linkKey;
	}
	FAchievementProgress() = default;
	void OverrideLinkKey(const int32 newKey)
	{
		m_linkKey = newKey;
	}
	int32 GetLinkKey() const
	{
		return m_linkKey;
	}
	// the "key" that connects this structs data to that of an achievement
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Public", SaveGame)
	FString key = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Public", meta = (ClampMin = "0"), SaveGame)
	int32 progress = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Public", SaveGame)
	bool bIsUnlocked = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Public", SaveGame)
	FString unlockedTime = "Never";

private:
	int32 m_linkKey = 0; // used for linking this with the Settings achievement part
};

USTRUCT(BlueprintType)
// this struct has all the data that is inside the developer settings, ReadOnly for blueprints
struct ACHIEVEMENTPLUGIN_API FAchievementSettings
{
	GENERATED_BODY()
public:
	// Platform-specific identifiers
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Steam",
			  meta = (DisplayName = "Steam Achievement ID"))
	FString steamID = "";
	// Platform-specific identifiers
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Epic",
			  meta = (DisplayName = "Epic Achievement ID"))
	FString epicID = "";

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

	// Runtime data (visible only here but not editable, NOT saved to config)
	UPROPERTY(VisibleAnywhere, Transient, Category = "Runtime Stats",
			  meta = (DisplayName = "Current Progress (NOT LIVE)"))
	FAchievementProgress currentProgress = FAchievementProgress(0);
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