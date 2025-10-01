#pragma once

#include "UAchievementPopup.generated.h"

UCLASS()
class UAchievementPopup : public UObject
{
	GENERATED_BODY()
public:
	static UAchievementPopup* Get()
	{
		return GetMutableDefault<UAchievementPopup>();
	}
	void SetWorld(const UWorld* world)
	{
		m_cachedWorld = const_cast<UWorld*>(world);
	}

	bool CreatePopup(const FText& achievementId, const TSoftObjectPtr<UTexture2D> icon);

private:
	bool CreateWidgetInstance();
	bool DeleteWidgetInstance();

	UPROPERTY()
	UUserWidget* m_widgetInstance = nullptr;

	// we need this for creating the UI
	UPROPERTY()
	UWorld* m_cachedWorld = nullptr;
};
