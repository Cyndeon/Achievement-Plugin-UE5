// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "AchievementPlatformsEnum.h"
#include "AchievementPluginBPLibrary.generated.h"


UCLASS()
class ACHIEVEMENTPLUGIN_API UAchievementPluginBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
public:
	//UFUNCTION(BlueprintCallable)
	//static TArray<FString> GetAchievementNames();

	//UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "Parameter Collection",
	//		  meta = (DisplayName = "Set Value as Bool",
	//		  AutoCreateRefTerm = "achievementName",
	//		  GetOptions = "UAchievementPluginBPLibrary.GetAchievementNames"))
	//bool IncreaseAchievementProgress(const FString& achievementName, int32 increase);


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Achievement Progress", Keywords = "Set Achievement Progress"), Category = "AchievementPlugin")
	static bool IncreaseAchievementProgress(
		const FString& localAchievementId,
		float increase);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Save Achievement Progress Async", Keywords = "Save Achievement Progress Async"), Category = "AchievementPlugin")
	static bool SaveAchievementProgressAsync();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Save Achievement Progress", Keywords = "Save Achievement Progress"), Category = "AchievementPlugin")
	static bool SaveAchievementProgress();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Load Achievement Progress", Keywords = "Load Achievement Progress", 
			  Tooltip = "This is already done at the start of the game, however, this will force reload it without saving, be careful!"), Category = "AchievementPlugin")
	static bool LoadAchievementProgress();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Delete Single Achievement Progress", Keywords = "Delete Single Achievement Progress",
			  Tooltip = "Delete's given achievement's progress. This cannot be undone!"), Category = "AchievementPlugin")
	static bool DeleteSingleAchievementProgress(const FString& achievementID);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Delete All Achievement Progress", Keywords = "Delete Achievement Progress",
			  Tooltip="Delete's ALL achievements progress. Will empty all progress but keep the file. This cannot be undone!"), Category = "AchievementPlugin")
	static bool DeleteAllAchievementProgress();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Save Slot Index", Keywords = "Save Slot Index"), Category = "AchievementPlugin")
	static void SetActiveSaveSlotIndex(int32 newIndex);

	// this function should only be called when the user manually initializes the platform
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Achievement Platform Initialized", Keywords = "Achievement Platform Initialized"), Category = "AchievementPlugin")
	static void AchievementPlatformInitialized(EAchievementPlatforms platform, bool init = true);
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