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
	// the "key" that connects this structs data to that of an achievement
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Public", SaveGame)
	FString key = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Public", meta = (ClampMin = "0"), SaveGame)
	int32 progress = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Public", SaveGame)
	bool bIsUnlocked = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Public", SaveGame)
	FString unlockedTime = "Never";
};

USTRUCT(BlueprintType)
// this struct has all the data that is inside the developer settings, ReadOnly for blueprints
struct ACHIEVEMENTPLUGIN_API FAchievementSettings
{
	GENERATED_BODY()

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
	FAchievementProgress currentProgress;
};