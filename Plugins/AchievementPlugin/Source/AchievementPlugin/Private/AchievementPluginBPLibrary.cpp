// Copyright Epic Games, Inc. All Rights Reserved.

#include "AchievementPluginBPLibrary.h"

#include "AchievementLogCategory.h"
#include "AchievementPlugin.h"

UAchievementPluginBPLibrary::UAchievementPluginBPLibrary(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
{

}

TArray<FString> UAchievementPluginBPLibrary::GetAchievementNames()
{
	const auto* settings = UAchievementPluginSettings::Get();
	if (settings != nullptr)
	{
		return UAchievementPluginSettings::Get()->GetAchievementNames();
	}
	UE_LOG(AchievementLog, Fatal, TEXT("FATAL: Could not find UAchievementPluginSettings!"));
	return TArray<FString>();
}

bool UAchievementPluginBPLibrary::SetAchievementProgress(FString& achievementName, int32 increase)
{
	const auto* settings = UAchievementPluginSettings::Get();
	if (settings != nullptr)
	{
		 settings->achievementsData[achievementName].GetLinkID();
	}
}
