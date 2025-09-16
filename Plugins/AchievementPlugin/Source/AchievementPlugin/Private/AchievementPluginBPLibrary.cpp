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

UAchievementManager* GetManager()
{
	if (auto* manager = UAchievementManager::Get())
	{
		return manager;
	}
	UE_LOG(AchievementLog, Fatal, TEXT("FATAL: UAchievementPluginSettings returns a nullptr!"));
	return nullptr;

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

bool UAchievementPluginBPLibrary::SetAchievementProgress(const FString& achievementId, const int32 increase)
{
	return GetManager()->IncreaseAchievementProgress(achievementId, increase);
}

bool UAchievementPluginBPLibrary::SaveAchievementProgressAsync()
{
	const auto* manager = GetManager();
	return GetManager()->GetSaveManager()->SaveProgressAsync(manager->achievementsProgress);
}

bool UAchievementPluginBPLibrary::SaveAchievementProgress()
{
	const auto* manager = GetManager();
	return manager->GetSaveManager()->SaveProgress(manager->achievementsProgress);
}

bool UAchievementPluginBPLibrary::LoadAchievementProgress()
{
	auto* manager = GetManager();
	manager->achievementsProgress = manager->GetSaveManager()->LoadProgress();

	// remove any deleted achievements
	manager->CleanupAchievements();

	// add achievement progress for any new achievements that weren't there before
	manager->InitializeAchievements();

	return true;
}

bool UAchievementPluginBPLibrary::DeleteSingleAchievementProgress(const FString& achievementID)
{
	if (auto* manager = GetManager())
	{
		const auto linkID = UAchievementPluginSettings::Get()->GetLinkIDByAchievementID(achievementID);
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
	return false;
}

bool UAchievementPluginBPLibrary::DeleteAllAchievementProgress()
{
	if (auto* manager = GetManager())
	{
		auto& progress = manager->achievementsProgress;
		const int32 deletedCount = progress.Num();

		progress.Empty();
		manager->InitializeAchievements();

		UE_LOG(AchievementLog, Log, TEXT("Deleted all achievement progress for' %d' entries"), deletedCount);
		return true;
	}
	return false;
}

void UAchievementPluginBPLibrary::SetActiveSaveSlotIndex(const int32 newIndex)
{
	GetManager()->GetSaveManager()->SetSaveSlotIndex(newIndex);
	return;
}
