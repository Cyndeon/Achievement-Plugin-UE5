#include "USaveSystem.h"
#include "Kismet/GameplayStatics.h"
#include "AchievementLogCategory.h"
#include "AchievementPlugin.h"

bool UAchievementSaveManager::SaveProgressAsync(const TArray<FAchievementProgress>& achievements)
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
		m_saveSlotSettings.slotName,
		m_saveSlotSettings.slotIndex,
		FAsyncSaveGameToSlotDelegate::CreateUObject(this, &UAchievementSaveManager::OnAsyncSaveComplete)
	);

	return true;
}

bool UAchievementSaveManager::SaveProgress(const TArray<FAchievementProgress>& achievements) const
{
	if (m_bIsSaving)
	{
		UE_LOG(AchievementLog, Warning, TEXT("Already saving Async, blocking save!"));
		return false;
	}

	UAchievementSave* saveGameInstance = NewObject<UAchievementSave>();
	saveGameInstance->SetData(achievements);
	// Use synchronous save
	const bool bSaveSuccess = UGameplayStatics::SaveGameToSlot(saveGameInstance, m_saveSlotSettings.slotName, m_saveSlotSettings.slotIndex);

	if (bSaveSuccess)
	{
		UE_LOG(AchievementLog, Log, TEXT("Synchronously saved %d achievementsData to slot: %s"),
			   achievements.Num(), *m_saveSlotSettings.slotName);
	}
	else
	{
		UE_LOG(AchievementLog, Error, TEXT("Failed to save achievementsData to slot: %s"), *m_saveSlotSettings.slotName);
	}

	return bSaveSuccess;
}

TArray<FAchievementProgress> UAchievementSaveManager::LoadProgress() const
{
	TArray<FAchievementProgress> loadedAchievements = TArray<FAchievementProgress>();

	// Check if save file exists first
	if (!UGameplayStatics::DoesSaveGameExist(m_saveSlotSettings.slotName, m_saveSlotSettings.slotIndex))
	{
		UE_LOG(AchievementLog, Warning, TEXT("Save file doesn't exist: %s (User %d)"), *m_saveSlotSettings.slotName, m_saveSlotSettings.slotIndex);
		return loadedAchievements;
	}
	// Load the save game (casting is required here)
	const UAchievementSave* loadedSave = Cast<UAchievementSave>(UGameplayStatics::LoadGameFromSlot(m_saveSlotSettings.slotName, m_saveSlotSettings.slotIndex));

	if (!loadedSave)
	{
		UE_LOG(AchievementLog, Error, TEXT("Loaded save game is not of type USaveAchievement"));
		return loadedAchievements;
	}

	// copy over the loaded achievementsData
	loadedAchievements = loadedSave->achievementsData;

	UE_LOG(AchievementLog, Log, TEXT("Successfully loaded %d achievementProgress"), loadedAchievements.Num());

	return loadedAchievements;
}

void UAchievementSaveManager::SetSaveSlotSettings(const FSaveSlotSettings& newSettings)
{
	m_saveSlotSettings = newSettings;

#if WITH_EDITOR
	// in case the stats get set while editor is active, also set the developer settings to the same values
	UAchievementPluginSettings* settings = UAchievementPluginSettings::Get();
	if (settings->defaultSaveSlotSettings.slotName != newSettings.slotName || settings->defaultSaveSlotSettings.slotIndex != newSettings.slotIndex)
		settings->defaultSaveSlotSettings = newSettings;
#endif

	UE_LOG(AchievementLog, Log, TEXT("Set save slot name to '%s' and Index to %d"), *newSettings.slotName, newSettings.slotIndex);
}

void UAchievementSaveManager::OnAsyncSaveComplete(const FString& slotName, const int32 userIndex, const bool bSuccess)
{
	m_bIsSaving = false;
	if (bSuccess)
	{
		UE_LOG(AchievementLog, Log, TEXT("Successfully saved achievementsData to slot '%s' for user %d"), *slotName, userIndex);
	}
	else
	{
		UE_LOG(AchievementLog, Error, TEXT("Failed to save achievementsData to slot '%s' for user %d"), *slotName, userIndex);
	}
}
