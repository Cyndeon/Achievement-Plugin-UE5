#pragma once

#include "AchievementStructs.h"
#include "GameFramework/SaveGame.h"

#include "USaveSystem.generated.h"

UCLASS(BlueprintType)
class ACHIEVEMENTPLUGIN_API UAchievementSave : public USaveGame
{
	GENERATED_BODY()

public:
	// Constructor that takes reference to avoid copying
	void SetData(const TArray<FAchievementProgress>& inData)
	{
		achievementsData = inData;
	}
	UPROPERTY(SaveGame)
	TArray<FAchievementProgress> achievementsData;
};

UCLASS(BlueprintType, Blueprintable)
class ACHIEVEMENTPLUGIN_API UAchievementSaveManager : public UObject
{
	GENERATED_BODY()
public:

	// returns whether the save was successful
	bool SaveProgressAsync(const TArray<FAchievementProgress>& achievements, const FString& slotName, int32 userIndex);

	// returns the loaded achievements' progress
	TArray<FAchievementProgress> LoadProgress();

private:
	void OnAsyncSaveComplete(const FString& slotName, const int32 userIndex, bool bSuccess);

	bool m_bIsSaving = false;

	TArray<FAchievementProgress> m_currentAchievements;
};