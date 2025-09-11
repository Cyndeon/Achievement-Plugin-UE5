// Copyright Epic Games, Inc. All Rights Reserved.

#include "AchievementPluginBPLibrary.h"

#include "EdGraphSchema_K2.h"
#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintNodeSpawner.h"
#include "KismetCompiler.h"

#include "AchievementLogCategory.h"
#include "AchievementPlugin.h"
#include "K2Node_CallFunction.h"

UAchievementPluginBPLibrary::UAchievementPluginBPLibrary(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
{

}

TArray<FString> UAchievementPluginBPLibrary::GetAchievementNames()
{
	return TArray<FString> {"SDADS", "This?"};

	const auto* settings = UAchievementPluginSettings::Get();
	if (settings != nullptr)
	{
		return UAchievementPluginSettings::Get()->GetAchievementNames();
	}
	UE_LOG(AchievementLog, Fatal, TEXT("FATAL: Could not find UAchievementPluginSettings!"));
	return TArray<FString>();
}

bool UAchievementPluginBPLibrary::SetAchievementProgress(const FString& achievementName, const int32 increase)
	{
	const auto* settings = UAchievementPluginSettings::Get();
	if (settings != nullptr)
	{
		// check if the achievement name exists
		if (const auto* achievement = settings->achievementsData.Find(achievementName))
		{
			const auto id = achievement->GetLinkID();
			if (auto* achievementProgress = UAchievementManager::Get()->achievementsProgress.Find(id))
			{
				// if it was already unlocked, return early
				if (achievementProgress->bIsUnlocked)
				{
					return true;
				}

				achievementProgress->progress += increase;

				// if goal has been reached, unlock it 
				if (achievementProgress->progress >= achievement->progressGoal)
				{
					// Note: Needs to updated with a function that also updates other platforms like Steam and EOS!!!
					achievementProgress->bIsUnlocked = true;

					// CALL UNLOCK ON PLATFORM HERE
				}
				return true;
			}
		}
		UE_LOG(AchievementLog, Error, TEXT("ERROR: Achievement by the name of '%s' does not exist!"), *achievementName);
		return false;
	}
	UE_LOG(AchievementLog, Fatal, TEXT("FATAL: UAchievementPluginSettings returns a nullptr!"));
	return false;
}