#pragma once

#include "AchievementStructs.h"
#include "GameFramework/SaveGame.h"

#include "USaveSystem.generated.h"

// only used when saving/loading the data
UCLASS()
class ACHIEVEMENTPLUGIN_API UAchievementSave : public USaveGame
{
	GENERATED_BODY()

public:
	// Constructor that takes reference to avoid copying
	void SetData(const TMap<int32, FAchievementProgress>& inData)
	{
		achievementProgressSave = inData;
	}
	UPROPERTY(SaveGame)
	TMap<int32, FAchievementProgress> achievementProgressSave;
};

// note: this class only exists in UAchievementManager (by default)
UCLASS(BlueprintType, Blueprintable)
class ACHIEVEMENTPLUGIN_API UAchievementSaveManager : public UObject
{
	GENERATED_BODY()
public:
	static UAchievementSaveManager* Get()
	{
		return GetMutableDefault<UAchievementSaveManager>();
	}

	// returns whether the save was successful
	bool SaveProgressAsync(const TMap<int32, FAchievementProgress>& achievements);

	// returns whether the save was successful
	// Note: For saves during runtime, use SaveProgressAsync instead!
	bool SaveProgress(const TMap<int32, FAchievementProgress>& achievements) const;

	// returns the loaded achievementsData' progress
	TMap<int32, FAchievementProgress> LoadProgress() const;

	void SetSaveSlotSettings(const FSaveSlotSettings& newSettings);
	void SetSaveSlotIndex(const int32 newIndex);

private:
	void OnAsyncSaveComplete(const FString& slotName, const int32 userIndex, bool bSuccess);

	bool m_bIsSaving = false;
	FSaveSlotSettings m_saveSlotSettings;
};