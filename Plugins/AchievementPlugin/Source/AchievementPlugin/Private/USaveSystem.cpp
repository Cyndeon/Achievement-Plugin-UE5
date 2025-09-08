#include "USaveSystem.h"
#include "Kismet/GameplayStatics.h"
#include "AchievementLogCategory.h"

bool UAchievementSaveManager::SaveProgressAsync(const TArray<FAchievementProgress>& achievements, const FString& slotName, const int32 userIndex)
{
    if (m_bIsSaving == true)
    {
        UE_LOG(AchievementLog, Warning, TEXT("SaveProgressAsync called, but it was still busy saving!"));
        return false;
    }

    m_bIsSaving = true;

    UAchievementSave* saveGameInstance = NewObject<UAchievementSave>();
    saveGameInstance->SetData(achievements);

    // Save asynchronously
    UGameplayStatics::AsyncSaveGameToSlot(
        saveGameInstance,
        slotName,
        userIndex,
        FAsyncSaveGameToSlotDelegate::CreateUObject(this, &UAchievementSaveManager::OnAsyncSaveComplete)
    );

    return true;
}

TArray<FAchievementProgress> UAchievementSaveManager::LoadProgress()
{
	return TArray<FAchievementProgress>();
}

void UAchievementSaveManager::OnAsyncSaveComplete(const FString& slotName, const int32 userIndex, bool bSuccess)
{
	m_bIsSaving = false;
	if (bSuccess)
	{
		UE_LOG(AchievementLog, Log, TEXT("Successfully saved achievements to slot '%s' for user %d"), *slotName, userIndex);
	}
	else
	{
		UE_LOG(AchievementLog, Error, TEXT("Failed to save achievements to slot '%s' for user %d"), *slotName, userIndex);
	}
}
