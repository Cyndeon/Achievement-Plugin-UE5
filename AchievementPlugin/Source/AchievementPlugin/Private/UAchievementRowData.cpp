// -------------------------------------------------------------
// Copyright 2025 Justin Comans. All rights reserved.         ||
// -------------------------------------------------------------

#include "UAchievementRowData.h"
#include "AchievementPlugin.h"

FAchievementData UAchievementRowData::GetAchievementData() const
{
	const auto& Settings = UAchievementPluginSettings::Get();
	if (!Settings)
	{
		return FAchievementData();
	}

	if (const auto* Achievement = Settings->achievementsData.Find(AchievementId))
	{
		return *Achievement;
	}

	return FAchievementData();
}

FAchievementProgress UAchievementRowData::GetProgress() const
{
	// Adjust this to however you access your subsystem/progress map
	const auto& Settings = UAchievementPluginSettings::Get();
	if (!Settings)
	{
		return FAchievementProgress();
	}

	if (UAchievementManagerSubSystem* Subsystem = UAchievementManagerSubSystem::Get())
	{
		return Subsystem->GetAchievementProgress(AchievementId);
	}

	return FAchievementProgress();
}

float UAchievementRowData::GetProgressPercent() const
{
	const auto Data = GetAchievementData();
	if (Data.progressGoal <= 0) return 1.0f;

	const auto Progress = GetProgress();
	return FMath::Clamp(Progress.progress / static_cast<float>(Data.progressGoal), 0.0f, 1.0f);
}

bool UAchievementRowData::IsUnlocked() const
{
	const auto Data = GetAchievementData();
	const auto Progress = GetProgress();
	return Progress.progress >= Data.progressGoal;
}

UTexture2D* UAchievementRowData::GetIcon() const
{
	const auto Data = GetAchievementData();
	const TSoftObjectPtr<UTexture2D>& IconPtr = IsUnlocked()
		                                            ? Data.unlockedTexture
		                                            : Data.lockedTexture;
	return IconPtr.LoadSynchronous();
}
