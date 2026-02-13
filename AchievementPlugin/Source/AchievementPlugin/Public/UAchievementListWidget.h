// -------------------------------------------------------------
// Copyright 2026 Justin Comans. Licensed under CC BY 4.0.    ||
// -------------------------------------------------------------
#pragma once

#include "Blueprint/UserWidget.h"
#include "UAchievementListWidget.generated.h"

class UListView;
class UAchievementRowData;

UCLASS()
class ACHIEVEMENTPLUGIN_API UAchievementListWidget : public UUserWidget
{
	GENERATED_BODY()
    
public:
	UFUNCTION(BlueprintCallable, Category = "Achievement UI")
	void PopulateList();
    
	UFUNCTION(BlueprintCallable, Category = "Achievement UI")
	void RefreshDisplay() const;
    
	UFUNCTION(BlueprintCallable, Category = "Achievement UI")
	void ClearList();
    
protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UListView> AchievementListView;
    
	// Keep references alive
	UPROPERTY()
	TArray<TObjectPtr<UAchievementRowData>> RowDataObjects;
};