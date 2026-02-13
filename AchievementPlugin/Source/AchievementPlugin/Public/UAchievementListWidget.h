// -------------------------------------------------------------
// Copyright 2026 Justin Comans. Licensed under CC BY 4.0.    ||
// -------------------------------------------------------------
#pragma once

#include "Blueprint/UserWidget.h"
#include "UAchievementListWidget.generated.h"

UENUM(BlueprintType)
enum class EAchievementSortMode : uint8
{
	ProgressDescending = 0, // Default
	ProgressAscending,
	Creator, // untouched order
	Alphabetical,
	AlphabeticalReverse,
};

USTRUCT(BlueprintType)
struct FAchievementFilterSettings
{
	GENERATED_BODY()
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAchievementSortMode SortMode = EAchievementSortMode::ProgressDescending;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool unlockedAtBottom = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool hideUnlocked = false;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool hideLocked = false;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool hideHidden = false;
};

class UListView;
class UAchievementRowData;

UCLASS()
class ACHIEVEMENTPLUGIN_API UAchievementListWidget : public UUserWidget
{
	GENERATED_BODY()
    
public:
	UFUNCTION()
	void PopulateList();
    
	UFUNCTION()
	void RefreshDisplay() const;
    
	UFUNCTION()
	void ClearList();
	
	UFUNCTION()
	void ApplyFilter(const FAchievementFilterSettings& NewFilter);
    
private:
	TArray<FString> GetFilteredAndSortedIds() const;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UListView> AchievementListView;
	
	UPROPERTY()
	TArray<TObjectPtr<UAchievementRowData>> RowDataObjects;
	
	UPROPERTY()
	FAchievementFilterSettings CurrentFilter;
};