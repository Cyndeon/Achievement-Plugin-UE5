// -------------------------------------------------------------
// Copyright 2025 Justin Comans. All rights reserved.         ||
// -------------------------------------------------------------

#pragma once

#include "AchievementStructs.h"
#include "UAchievementRowData.generated.h"


UCLASS(Blueprintable, BlueprintType)
class ACHIEVEMENTPLUGIN_API UAchievementRowData : public UObject
{
	GENERATED_BODY()
    
public:
	UPROPERTY(BlueprintReadOnly, Category = "Achievement")
	FString AchievementId;
    
	// Core data access
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Achievement")
	FAchievementData GetAchievementData() const;
    
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Achievement")
	FAchievementProgress GetProgress() const;
    
	// Helpers functions
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Achievement")
	float GetProgressPercent() const;
    
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Achievement")
	bool IsUnlocked() const;
    
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Achievement")
	UTexture2D* GetIcon() const;
};