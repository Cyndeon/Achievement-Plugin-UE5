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
	
	// only used for caching the search text
	FString SearchText;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool unlockedAtBottom = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool hideUnlocked = false;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool hideLocked = false;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool hideHidden = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ToolTip = "Whether hidden achievements should be clickable to be revealed"))
	bool clickableHidden = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ToolTip = "Whether to use Scientific Notation for all Progress and Goals. NOTE: When numbers get too high, they will default to Scientific Notation anyway!"))
	bool useScientificNotation = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ToolTip = "How many decimals to use for progress", ClampMin = "0", ClampMax = "2"))
	int32 decimalCount = 0;
};

class UListView;
class UAchievementRowData;

UCLASS(Abstract)
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
	
	UFUNCTION()
	FAchievementFilterSettings& GetCurrentFilter() {return CurrentFilter;}
	
	UFUNCTION()
	void SetSearchText(const FString& NewSearchText);
    
private:
	TArray<FString> GetFilteredAndSortedIds() const;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UListView> AchievementListView;
	
	UPROPERTY()
	TArray<TObjectPtr<UAchievementRowData>> RowDataObjects;
	
	UPROPERTY()
	FAchievementFilterSettings CurrentFilter;
	
	// timer for typing
	FTimerHandle SearchDebounceTimer;

	UPROPERTY()
	FString PendingSearchText;
	
	float WaitTime = 0.2f;
};