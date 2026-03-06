// -------------------------------------------------------------
// Copyright 2025 Justin Comans. Licensed under CC BY 4.0.    ||
// -------------------------------------------------------------


// Copyright Epic Games, Inc. All Rights Reserved.

#include "AchievementPluginBPLibrary.h"

#include "AchievementLogCategory.h"
#include "AchievementPlatforms.h"
#include "AchievementPlugin.h"
#include "UAchievementUIManager.h"
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

bool UAchievementPluginBPLibrary::IncreaseAchievementProgress(const FString& localAchievementId, const float change)
{
	return GetManager()->IncreaseAchievementProgress(localAchievementId, change);
}

bool UAchievementPluginBPLibrary::GetAchievementUnlockedStatus()
{
	return true;
}

FAchievementData UAchievementPluginBPLibrary::GetAchievementData(const FString& achievementId)
{
	return GetManager()->GetAchievementData(achievementId);
}

FAchievementProgress UAchievementPluginBPLibrary::GetAchievementProgressById(const FString& achievementId)
{
	return GetManager()->GetAchievementProgress(achievementId);
}

FAchievementProgress UAchievementPluginBPLibrary::GetAchievementProgressByData(const FAchievementData& achievementData)
{
	return GetManager()->GetAchievementProgress(achievementData);
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
}

void UAchievementPluginBPLibrary::RetroactivelyUpdateAchievementsOnPlatforms()
{
	UAchievementManagerSubSystem::RetroactivelyUpdateAchievementsOnPlatforms();
}

void UAchievementPluginBPLibrary::AchievementPlatformInitialized(const EAchievementPlatforms platform, const bool init)
{
	if (auto* platformClass = UAchievementPlatformsClass::Get())
	{
		platformClass->achievementPlatformInitialized = init;
		platformClass->selectedPlatform = platform;
		return;
	}

	UE_LOG(AchievementPlatformLog, Error, TEXT(" AchievementPlatformClass cannot be found!"));
}

void UAchievementPluginBPLibrary::RemoveAchievementWidget()
{
	GetManager()->DeleteAchievementPopup();
}

bool UAchievementPluginBPLibrary::CreateAchievementList()
{
	return UAchievementUIManager::Get()->CreateAchievementList();
}

bool UAchievementPluginBPLibrary::ShowAchievementList()
{
	return UAchievementUIManager::Get()->ShowAchievementList();
}

bool UAchievementPluginBPLibrary::HideAchievementList()
{
	return UAchievementUIManager::Get()->HideAchievementList();
}

bool UAchievementPluginBPLibrary::SetAchievementListFilter(const FAchievementFilterSettings filter)
{
	return UAchievementUIManager::Get()->ChangeAchievementListFilters(filter);
}

FAchievementFilterSettings UAchievementPluginBPLibrary::GetAchievementFilter()
{
	if (const auto filter = UAchievementUIManager::Get()->GetCurrentAchievementFilterSettings())
		return *filter;
	return FAchievementFilterSettings();
}

FAchievementFilterSettings UAchievementPluginBPLibrary::GetDefaultAchievementFilter()
{
	if (const auto settings = UAchievementPluginSettings::Get())
	{
		return settings->defaultAchievementListFilter;
	}
	else return FAchievementFilterSettings();
}

FString UAchievementPluginBPLibrary::FormatNumberWithSuffix(const float Value)
{
	// if Value is too low, just return 0
	if (FMath::IsNearlyZero(Value))
	{
		return TEXT("0");
	}

	const auto& filter = GetAchievementFilter();

	// Below 1000 - show as-is regardless of notation setting
	if (Value < 1000.0f)
	{
		if (FMath::Fmod(Value, 1.0) == 0.0)
		{
			return FString::Printf(TEXT("%lld"), FMath::FloorToInt64(Value));
		}
		return FString::Printf(TEXT("%.*f"), filter.decimalCount, Value);
	}

	// Scientific notation mode
	if (filter.useScientificNotation)
	{
		const int32 Exponent = FMath::FloorToInt(FMath::LogX(10.0, Value));
		const double Mantissa = Value / FMath::Pow(10.0, Exponent);

		FString Result = FString::Printf(TEXT("%.*f"), filter.decimalCount, Mantissa);

		// Remove trailing zeros
		while (Result.EndsWith(TEXT("0")) && Result.Contains(TEXT(".")))
		{
			Result.LeftChopInline(1);
		}
		if (Result.EndsWith(TEXT(".")))
		{
			Result.LeftChopInline(1);
		}

		return FString::Printf(TEXT("%se%d"), *Result, Exponent);
	}

	// Named suffix mode
	struct FSuffixInfo
	{
		double Threshold;
		double Divisor;
		const TCHAR* Suffix;
	};

	static const FSuffixInfo Suffixes[] =
	{
		{1e33, 1e33, TEXT("Dc")},
		{1e30, 1e30, TEXT("No")},
		{1e27, 1e27, TEXT("Oc")},
		{1e24, 1e24, TEXT("Sp")},
		{1e21, 1e21, TEXT("Sx")},
		{1e18, 1e18, TEXT("Qi")},
		{1e15, 1e15, TEXT("Qa")},
		{1e12, 1e12, TEXT("T")},
		{1e9, 1e9, TEXT("B")},
		{1e6, 1e6, TEXT("M")},
		{1e3, 1e3, TEXT("K")},
	};

	// Beyond our suffixes - fall back to scientific notation
	if (Value >= 1e36)
	{
		const int32 Exponent = FMath::FloorToInt(FMath::LogX(10.0, Value));
		const double Mantissa = Value / FMath::Pow(10.0, Exponent);

		FString Result = FString::Printf(TEXT("%.*f"), filter.decimalCount, Mantissa);

		while (Result.EndsWith(TEXT("0")) && Result.Contains(TEXT(".")))
		{
			Result.LeftChopInline(1);
		}
		if (Result.EndsWith(TEXT(".")))
		{
			Result.LeftChopInline(1);
		}

		return FString::Printf(TEXT("%se%d"), *Result, Exponent);
	}

	for (const FSuffixInfo& Info : Suffixes)
	{
		if (Value >= Info.Threshold)
		{
			const double Divided = Value / Info.Divisor;
			FString Result = FString::Printf(TEXT("%.*f"), filter.decimalCount, Divided);

			while (Result.EndsWith(TEXT("0")) && Result.Contains(TEXT(".")))
			{
				Result.LeftChopInline(1);
			}
			if (Result.EndsWith(TEXT(".")))
			{
				Result.LeftChopInline(1);
			}

			return Result + Info.Suffix;
		}
	}

	return FString::Printf(TEXT("%.*f"), filter.decimalCount, Value);
}

bool UAchievementPluginBPLibrary::SetSearchTextInFilter(FString text)
{
	if (const auto* UIManager = UAchievementUIManager::Get())
	{
		return UIManager->SetSearchText(text);
	}
	return false;
}
