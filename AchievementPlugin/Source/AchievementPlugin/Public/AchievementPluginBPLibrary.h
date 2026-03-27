// -------------------------------------------------------------
// Copyright 2025 Justin Comans. All rights reserved.         ||
// -------------------------------------------------------------


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "AchievementPlatformsEnum.h"
#include "AchievementStructs.h"
#include "UAchievementListWidget.h"
#include "AchievementPluginBPLibrary.generated.h"

class UAchievementPluginSettings;

UCLASS()
class ACHIEVEMENTPLUGIN_API UAchievementPluginBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get Achievement Plugin Settings", Keywords = "Achievement Plugin Settings"), 
		Category = "AchievementPlugin|Settings")
	static UAchievementPluginSettings* GetAchievementPluginSettings();
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Change Achievement Progress", Keywords = "Change Achievement Progress"), 
		Category = "AchievementPlugin|Achievement Progress")
	static bool IncreaseAchievementProgress(
		const FString& localAchievementId,
		float change);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Achievement Unlocked Status", Keywords = "Get Achievement unlocked Status"), 
		Category = "AchievementPlugin|Achievement Progress")
	static bool GetAchievementUnlockedStatus(const FString& localAchievementId);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Achievement Data", Keywords = "Get Achievement Data",
			Tooltip = "Returns a copy of the achievement using the achievementId"), 
			Category = "AchievementPlugin|Achievement Data")
	static FAchievementData GetAchievementData(const FString& localAchievementId);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Achievement Progress By Id", Keywords = "Get Achievement Progress By Id",
			Tooltip = "Returns a copy of the progress for the given achievement's Id"), Category = "AchievementPlugin|Achievement Progress")
	static FAchievementProgress GetAchievementProgressById(const FString& localAchievementId);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Achievement Progress By Data", Keywords = "Get Achievement Progress By Data", 
			Tooltip = "Returns a copy of the progress for the given achievement"), Category = "AchievementPlugin|Achievement Progress")
	static FAchievementProgress GetAchievementProgressByData(const FAchievementData& achievementData);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Save Achievement Progress Async", Keywords = "Save Achievement Progress Async"), 
		Category = "AchievementPlugin|Saving and Loading")
	static bool SaveAchievementProgressAsync();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Save Achievement Progress", Keywords = "Save Achievement Progress"), 
		Category = "AchievementPlugin|Saving and Loading")
	static bool SaveAchievementProgress();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Load Achievement Progress", Keywords = "Load Achievement Progress", 
			  Tooltip = "This is already done at the start of the game, however, this will force reload it without saving, be careful!"), 
			  Category = "AchievementPlugin|Saving and Loading")
	static bool LoadAchievementProgress();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Delete Single Achievement Progress", Keywords = "Delete Single Achievement Progress",
			  Tooltip = "Deletes given achievement's progress. This cannot be undone!"), Category = "AchievementPlugin|Achievement Progress")
	static bool DeleteSingleAchievementProgress(const FString& localAchievementID, bool platformsToo = true);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Delete All Achievement Progress", Keywords = "Delete Achievement Progress",
			  Tooltip="Delete's ALL achievements progress. Will empty all progress but keep the file. This cannot be undone!"), Category = "AchievementPlugin|Achievement Progress")
	static bool DeleteAllAchievementProgress(bool platformsToo = true);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Save Slot Index", Keywords = "Save Slot Index"), Category = "AchievementPlugin|Saving and Loading")
	static void SetActiveSaveSlotIndex(int32 newIndex);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Retroactviely Update Achievements On Platforms", Keywords = "Retroactviely Update Achievements Platforms"), 
		Category = "AchievementPlugin|Platforms")
	static void RetroactivelyUpdateAchievementsOnPlatforms();

	// this function should only be called when the user manually initializes the platform
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Achievement Platform Initialized", Keywords = "Achievement Platform Initialized"), Category = "AchievementPlugin|Platforms")
	static void AchievementPlatformInitialized(EAchievementPlatforms platform, bool init = true);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Has Platform Flag", Keywords = "Platform Flag"), Category = "AchievementPlugin|Platforms")
	static bool HasPlatformFlag(EUnlockedPlatforms flags, EUnlockedPlatforms flagToCheck);

	// this function is required for the Widget to function properly
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Remove Achievement Widget", Keywords = "Achievement Widget Remove"), Category = "AchievementPlugin|Achievement Popup")
	static void RemoveAchievementWidget();
	
	// achievement list functions
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create Achievement List Widget", Keywords = "Create Achievement List Widget"), Category = "AchievementPlugin|Achievement List")
	static bool CreateAchievementList();
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Show Achievement List Widget", Keywords = "Show Achievement List Widget"), Category = "AchievementPlugin|Achievement List")
	static bool ShowAchievementList();
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Hide Achievement List Widget", Keywords = "Hide Achievement List Widget"), Category = "AchievementPlugin|Achievement List")
	static bool HideAchievementList();
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Change Filter For Achievement List Widget", Keywords = "Change Filter Achievement List Widget"), Category = "AchievementPlugin|Achievement List")
	static bool SetAchievementListFilter(FAchievementFilterSettings filter);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get Filter For Achievement List Widget", Keywords = "Get Filter Achievement List Widget"), Category = "AchievementPlugin|Achievement List")
	static FAchievementFilterSettings GetAchievementFilter();
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get Default Filter For Achievement List Widget", Keywords = "Get Current Default Filter Achievement List Widget"), Category = "AchievementPlugin|Achievement List")
	static FAchievementFilterSettings GetDefaultAchievementFilter();
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Search Text", Keywords = "Search Filter Achievement"), Category = "AchievementPlugin|Achievement List")
	static bool SetSearchTextInFilter(const FString& text);
	
	// general helper functions
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Format Number With Suffix", Keywords = "Format Number With Suffix"), Category = "AchievementPlugin|Achievement List")
	static FString FormatNumberWithSuffix(float Value);
};


/*
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/