#include "UAchievementPopup.h"

#include "Blueprint/UserWidget.h"
#include "AchievementLogCategory.h"
#include "AchievementPlugin.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Engine/World.h"

UWorld* UAchievementPopup::m_cachedWorld = nullptr;

void UAchievementPopup::Initialize(FSubsystemCollectionBase& Collection)
{
	m_maxPopupsCachedValue = UAchievementPluginSettings::Get()->achievementWidgetSettings.maxToShow;
	m_distanceBetweenPopupsCachedValue = UAchievementPluginSettings::Get()->achievementWidgetSettings.distanceBetweenPopups;

	m_widgetInstances.Empty();
	m_queuedPopups.Empty();
	m_cachedWorld = GetWorld();

	Super::Initialize(Collection);
}

void UAchievementPopup::Deinitialize()
{
	for (const auto& widget : m_widgetInstances)
	{
		if (IsValid(widget))
		{
			widget->RemoveFromParent();
		}
	}
	Super::Deinitialize();
}

UAchievementPopup* UAchievementPopup::Get()
{
	return m_cachedWorld->GetSubsystem<UAchievementPopup>();
}

void UAchievementPopup::QueuePopup(const FText& name, const TSoftObjectPtr<UTexture2D>& icon)
{
	m_queuedPopups.Add(FAchievementNameAndIcon(name, icon));
}

void UAchievementPopup::Tick(float deltaTime)
{
	if (m_queuedPopups.Num() > 0)
	{
		// if there are less popups than we can have
		if (m_widgetInstances.Num() < m_maxPopupsCachedValue)
		{
			const auto data = m_queuedPopups[0];
			m_queuedPopups.RemoveAt(0);

			// create the new Popup (widget)
			const auto* widget = CreateWidgetInstance();

			// if it didn't work, put it back and try again
			if (!widget)
			{
				m_queuedPopups.Insert(data, 0);
				return;
			}

			// find the name variable
			if (UTextBlock* textBlock = Cast<UTextBlock>(widget->GetWidgetFromName(TEXT("AchievementName"))))
			{
				textBlock->SetText(data.name);
			}
			// find the image variable
			if (UImage* image = Cast<UImage>(widget->GetWidgetFromName(TEXT("AchievementImage"))))
			{
				image->SetBrushFromTexture(data.icon.LoadSynchronous());
			}
			const int widgetInstanceIndex = m_widgetInstances.Num() - 1;
			PositionWidget(widgetInstanceIndex);
		}
	}
	if (m_widgetInstances.Num() > 0)
	{
		// backup check to remove invalid widgets
		while (!IsValid(m_widgetInstances[0]))
		{
			m_widgetInstances.RemoveAt(0);
		}

		RepositionAllWidgets();
	}
}

UUserWidget* UAchievementPopup::CreateWidgetInstance()
{
	if (const UAchievementPluginSettings* settings = UAchievementPluginSettings::Get())
	{
		auto* widget = CreateWidget<UUserWidget>(m_cachedWorld, settings->achievementWidgetSettings.achievementWidget);
		if (!widget)
		{
			UE_LOG(AchievementUILog, Error, TEXT("Could not create achievement widget!"));
			return nullptr;
		}
		m_widgetInstances.Add(widget);
		widget->AddToViewport();
		return widget;
	}
	return nullptr;
}

bool UAchievementPopup::DeleteFirstWidgetInstance()
{
	if (m_widgetInstances.Num() == 0) return false;

	const auto widgetToRemove = m_widgetInstances[0];

	m_widgetInstances.RemoveAt(0);

	if (widgetToRemove)
	{
		// according to the UE5 API, RemoveFromViewport is deprecated, and they recommend using RemoveFromParent instead
		widgetToRemove->RemoveFromParent();
	}
	UE_LOG(AchievementUILog, Log, TEXT("Deleting current Widget instance"));

	RepositionAllWidgets();

	return true;
}

void UAchievementPopup::PositionWidget(const int32 index)
{
	const auto& widget = m_widgetInstances[index];

	if (auto* rootWidget = widget->GetRootWidget())
	{
		const FVector2D translation(0.0f, -(index * m_distanceBetweenPopupsCachedValue));
		rootWidget->SetRenderTranslation(translation);
	}
}

void UAchievementPopup::RepositionAllWidgets()
{
	const auto amount = m_widgetInstances.Num();
	for (int i = 0; i < amount; i++)
	{
		if (IsValid(m_widgetInstances[i]))
		{
			PositionWidget(i);
		}
	}
}
