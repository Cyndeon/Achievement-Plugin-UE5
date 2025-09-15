// Copyright Epic Games, Inc. All Rights Reserved.

#include "AchievementPluginBPLibrary.h"

#include "EdGraphSchema_K2.h"
#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintNodeSpawner.h"
#include "KismetCompiler.h"

#include "AchievementLogCategory.h"
#include "AchievementPlugin.h"
#include "K2Node_CallFunction.h"
#include "USaveSystem.h"

UAchievementPluginBPLibrary::UAchievementPluginBPLibrary(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
{

}

void LogFatalMissingManager()
{
	UE_LOG(AchievementLog, Fatal, TEXT("FATAL: UAchievementPluginSettings returns a nullptr!"));
}

int32 GetLinkIDByAchievementID(const FString& achievementName)
{
	if (const auto* settings = UAchievementPluginSettings::Get())
	{
		// check if the achievement name exists
		if (const auto* achievement = settings->achievementsData.Find(achievementName))
		{
			return achievement->GetLinkID();
		}
		UE_LOG(AchievementLog, Error, TEXT("Achievement with the name '%s' cannot be found!"), *achievementName);
		return 0;
	}
	UE_LOG(AchievementLog, Fatal, TEXT("FATAL: Cannot find UAchievementPluginSettings!"));
	return 0;
}
//TArray<FString> UAchievementPluginBPLibrary::GetAchievementNames()
//{
//	UE_LOG(AchievementLog, Warning, TEXT("G!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!etAchievementNames CALLED!"));
//	return TArray<FString> {"SDADS", "This?"};
//
//	const auto* settings = UAchievementPluginSettings::Get();
//	if (settings != nullptr)
//	{
//		return UAchievementPluginSettings::Get()->GetAchievementNames();
//	}
//	UE_LOG(AchievementLog, Fatal, TEXT("FATAL: Could not find UAchievementPluginSettings!"));
//	return TArray<FString>();
//}

bool UAchievementPluginBPLibrary::SetAchievementProgress(const FString& achievementID, const int32 increase)
{
	if (auto* achievementProgress = UAchievementManager::Get()->achievementsProgress.Find(id))
{
	// if it was already unlocked, return early
	if (achievementProgress->bIsAchievementUnlocked)
	{
		UE_LOG(AchievementLog, Log, TEXT("Achievement '%s' was already unlocked, skipping."), *achievementID);
		return true;
	}

	// if goal has been reached, unlock it
	const auto goal = UAchievementPluginSettings::Get()->achievementsData.Find(achievementID)->progressGoal;

	if (achievementProgress->progress + increase >= goal)
	{
		achievementProgress->progress = goal;
		achievementProgress->bIsAchievementUnlocked = true;


		// CALL UNLOCK ON PLATFORMS HERE =========================================================================
	}
	else
		achievementProgress->progress += increase;

	UE_LOG(AchievementLog, Log, TEXT("Increased progress for '%s' to '%d'"), *achievementID, achievementProgress->progress);
	return true;
}
UE_LOG(AchievementLog, Error, TEXT("Could not find achievement progress for the Link ID '%d'"), id);
return false;

	// WIP

	/*if (auto* manager = UAchievementManager::Get())
	{
		return manager->SetAchievementProgress(GetLinkIDByAchievementID(achievementID));
	}
	LogFatalMissingManager();
	return false;*/
}

bool UAchievementPluginBPLibrary::SaveAchievementProgressAsync()
{
	if (const auto* manager = UAchievementManager::Get())
	{
		return manager->GetSaveManager()->SaveProgressAsync(manager->achievementsProgress);
	}
	LogFatalMissingManager();
	return false;
}

bool UAchievementPluginBPLibrary::SaveAchievementProgress()
{
	if (const auto* manager = UAchievementManager::Get())
	{
		return manager->GetSaveManager()->SaveProgress(manager->achievementsProgress);
	}
	LogFatalMissingManager();
	return false;
}

bool UAchievementPluginBPLibrary::LoadAchievementProgress()
{
	if (auto* manager = UAchievementManager::Get())
	{
		manager->achievementsProgress = manager->GetSaveManager()->LoadProgress();

		// remove any deleted achievements
		manager->CleanupAchievements();

		// add achievement progress for any new achievements that weren't there before
		manager->InitializeAchievements();

		return true;
	}
	LogFatalMissingManager();
	return false;
}

bool UAchievementPluginBPLibrary::DeleteSingleAchievementProgress(const FString& achievementID)
{
	if (auto* manager = UAchievementManager::Get())
	{
		const auto linkID = GetLinkIDByAchievementID(achievementID);
		if (manager->achievementsProgress.Find(linkID))
		{
			// set the element to be empty
			manager->achievementsProgress[linkID] = FAchievementProgress();

			UE_LOG(AchievementLog, Log, TEXT("Reset achievement progress for '%s'"), *achievementID);
			return true;
		}
		UE_LOG(AchievementLog, Error, TEXT("Could not find achievement progress for the Link ID '%d'"), linkID);
		return false;
	}
	LogFatalMissingManager();
	return false;
}

bool UAchievementPluginBPLibrary::DeleteAllAchievementProgress()
{
	if (auto* manager = UAchievementManager::Get())
	{
		auto& progress = manager->achievementsProgress;
		const int32 deletedCount = progress.Num();

		progress.Empty();
		manager->InitializeAchievements();

		UE_LOG(AchievementLog, Log, TEXT("Deleted all achievement progress for' %d' entries"), deletedCount);
		return true;
	}
	LogFatalMissingManager();
	return false;
}

void UAchievementPluginBPLibrary::SetActiveSaveSlotIndex(const int32 newIndex)
{
	if (const auto* manager = UAchievementManager::Get())
	{
		manager->GetSaveManager()->SetSaveSlotIndex(newIndex);
		return;
	}
	LogFatalMissingManager();
}
