// Copyright Epic Games, Inc. All Rights Reserved.

#include "AchievementPluginBPLibrary.h"

#include "EdGraphSchema_K2.h"
#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintNodeSpawner.h"
#include "KismetCompiler.h"

#include "AchievementLogCategory.h"
#include "AchievementPlatforms.h"
#include "AchievementPlugin.h"
#include "K2Node_CallFunction.h"
#include "USaveSystem.h"

UAchievementPluginBPLibrary::UAchievementPluginBPLibrary(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
{

}

UAchievementManagerSubSystem* GetManager()
{
	if (auto* manager = UAchievementManagerSubSystem::Get())
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

bool UAchievementPluginBPLibrary::IncreaseAchievementProgress(const FString& localAchievementId, const float change)
{
	return GetManager()->IncreaseAchievementProgress(localAchievementId, change);
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

bool UAchievementPluginBPLibrary::DeleteSingleAchievementProgress(const FString& achievementID, bool platformsToo)
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

		if (platformsToo)
			UAchievementPlatformsClass::Get()->PlatformDeleteAllAchievementProgress();
		return false;
	}
	return false;
}

bool UAchievementPluginBPLibrary::DeleteAllAchievementProgress(const bool platformsToo)
{
	if (auto* manager = GetManager())
	{
		auto& progress = manager->achievementsProgress;
		const int32 deletedCount = progress.Num();

		progress.Empty();
		manager->InitializeAchievements();

		UE_LOG(AchievementLog, Log, TEXT("Deleted all achievement progress for' %d' entries"), deletedCount);

		// delete on non-local platform too if true
		if (platformsToo)
			UAchievementPlatformsClass::Get()->PlatformDeleteAllAchievementProgress();
		return true;
	}
	return false;
}

void UAchievementPluginBPLibrary::SetActiveSaveSlotIndex(const int32 newIndex)
{
	GetManager()->GetSaveManager()->SetSaveSlotIndex(newIndex);
	return;
}

void UAchievementPluginBPLibrary::AchievementPlatformInitialized(const EAchievementPlatforms platform, const bool init)
{
	if (auto* platformClass = UAchievementPlatformsClass::Get())
	{
		platformClass->achievementPlatformInitialized = init;
		platformClass->selectedPlatform = platform;
		return;
	}

	UE_LOG(AchievementPlatformLog, Error, TEXT("ERROR: AchievementPlatformClass cannot be found!"));
}
