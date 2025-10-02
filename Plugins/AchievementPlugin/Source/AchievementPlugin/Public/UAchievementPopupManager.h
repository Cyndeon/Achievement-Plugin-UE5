#pragma once

#include "UAchievementPopupManager.generated.h"

USTRUCT()
struct FAchievementNameAndIcon
{
	GENERATED_BODY()
public:
	FAchievementNameAndIcon() = default;
	FAchievementNameAndIcon(const FText& newName, const TSoftObjectPtr<UTexture2D>& newIcon, 
							const float newProgress = 0.f) : name(newName), image(newIcon), progress(newProgress)
	{}

	FText name = FText::FromString("");
	TSoftObjectPtr<UTexture2D> image = nullptr;
	float progress = 0.f;
};

class UWorld;
UCLASS()
class UAchievementPopupManager : public UWorldSubsystem, public FTickableGameObject
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	static UAchievementPopupManager* Get();
#if WITH_EDITOR
	// this is to update the cached values if it is edited in the dev settings
	void OverrideCachedMaxToShow(const int32 newVal)
	{
		m_maxPopupsCachedValue = newVal;
	}
	void OverrideCachedDistance(const float newVal)
	{
		m_distanceBetweenPopupsCachedValue = newVal;
	}
#endif

	void QueuePopup(const FText& name, const TSoftObjectPtr<UTexture2D>& icon, const float progress);

	virtual void Tick(float deltaTime) override;
	// we need this in order to retrieve achievements stats in the editor
	virtual bool IsTickableInEditor() const override
	{
		return false;
	}
	virtual TStatId GetStatId() const override
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(UAchievementPopup, STATGROUP_Tickables);
	}

	bool DeleteFirstWidgetInstance();
private:
	UUserWidget* CreateWidgetInstance();
	void PositionWidget(int32 index);
	void RepositionAllWidgets();

	UPROPERTY()
	TArray<TObjectPtr<UUserWidget>> m_widgetInstances;

	UPROPERTY()
	TArray<FAchievementNameAndIcon> m_queuedPopups;

	// used for achievements that are currently "on cooldown". Progress achievements only show up once every x seconds
	// this map keeps track of the ones that have been shown before and currently cannot be shown again
	UPROPERTY()
	TMap<FName, float> m_progressCooldowns;

	UPROPERTY()
	int m_maxPopupsCachedValue = 0;
	UPROPERTY()
	float m_distanceBetweenPopupsCachedValue = 0;

	static UWorld* m_cachedWorld;
};
