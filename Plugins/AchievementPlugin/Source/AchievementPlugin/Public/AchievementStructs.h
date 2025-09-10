#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"

#include "AchievementStructs.generated.h" 

// this will allow the achievement structs to be "linked"
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
	UPROPERTY(SaveGame)
	int32 m_linkID = 0;
};


USTRUCT(BlueprintType)
// this struct has all the data that can be changed during runtime, ReadWrite for blueprints
struct ACHIEVEMENTPLUGIN_API FAchievementProgress : public FLinkedStruct
{
	GENERATED_BODY()
public:
	FAchievementProgress() = default;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Public", meta = (ClampMin = "0"), SaveGame)
	int32 progress = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Public", SaveGame)
	bool bIsUnlocked = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Public", SaveGame)
	FString unlockedTime = "Never";
};

USTRUCT(BlueprintType)
// this struct has all the data that is inside the developer settings, ReadOnly for blueprints
struct ACHIEVEMENTPLUGIN_API FAchievementSettings : public FLinkedStruct
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
	FAchievementProgress currentProgress = FAchievementProgress();
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