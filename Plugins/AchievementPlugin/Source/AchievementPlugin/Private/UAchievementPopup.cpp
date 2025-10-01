#include "UAchievementPopup.h"

#include "Blueprint/UserWidget.h"
#include "AchievementLogCategory.h"
#include "AchievementPlugin.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

bool UAchievementPopup::CreatePopup(const FText& achievementId, const TSoftObjectPtr<UTexture2D> icon)
{
	if (!m_widgetInstance)
	{
		CreateWidgetInstance();
	}

	// find the name variable
	if (UTextBlock* textBlock = Cast<UTextBlock>(m_widgetInstance->GetWidgetFromName(TEXT("AchievementName"))))
	{
		textBlock->SetText(achievementId);
	}
	// find the image variable
	if (UImage* image = Cast<UImage>(m_widgetInstance->GetWidgetFromName(TEXT("AchievementImage"))))
	{
		image->SetBrushFromTexture(icon.LoadSynchronous());
	}

	return true;
}

bool UAchievementPopup::CreateWidgetInstance()
{
	// we first need to get the settings and widget

	if (const UAchievementPluginSettings* settings = UAchievementPluginSettings::Get())
	{
		m_widgetInstance = CreateWidget<UUserWidget>(m_cachedWorld, settings->achievementWidget);
		if (!m_widgetInstance)
		{
			UE_LOG(AchievementUILog, Error, TEXT("Could not create achievement widget!"));
			return false;
		}
		m_widgetInstance->AddToViewport();
		return true;
	}
	return false;
}

bool UAchievementPopup::DeleteWidgetInstance()
{
	if (!m_widgetInstance) return false;
	// according to the UE5 API, RemoveFromViewport is deprecated, and they recommend using RemoveFromParent instead
	m_widgetInstance->RemoveFromParent();
	m_widgetInstance = nullptr;
	return true;
}
