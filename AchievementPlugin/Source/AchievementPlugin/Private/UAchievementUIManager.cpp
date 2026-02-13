// -------------------------------------------------------------
// Copyright 2025 Justin Comans. Licensed under CC BY 4.0.    ||
// -------------------------------------------------------------


#include "UAchievementUIManager.h"

#include "AchievementLogCategory.h"
#include "AchievementPlugin.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/ProgressBar.h"
#include "Engine/World.h"

UWorld* UAchievementUIManager::m_cachedWorld = nullptr;

void UAchievementUIManager::Initialize(FSubsystemCollectionBase& Collection)
{
	const auto settings = UAchievementPluginSettings::Get();
	m_maxPopupsCachedValue = settings->achievementWidgetSettings.maxToShow;
	m_distanceBetweenPopupsCachedValue = settings->achievementWidgetSettings.distanceBetweenPopups;

	m_popupInstances.Empty();
	m_queuedPopups.Empty();
	m_progressCooldowns.Empty();
	m_cachedWorld = GetWorld();

	Super::Initialize(Collection);
}

void UAchievementUIManager::Deinitialize()
{
	for (const auto& widget : m_popupInstances)
	{
		if (IsValid(widget))
		{
			widget->RemoveFromParent();
		}
	}
	Super::Deinitialize();
}

UAchievementUIManager* UAchievementUIManager::Get()
{
	return m_cachedWorld->GetSubsystem<UAchievementUIManager>();
}

void UAchievementUIManager::QueuePopup(const FText& name, const TSoftObjectPtr<UTexture2D>& icon, const float progress = 0.f)
{
	const FName achievementName = FName(*name.ToString());
	if (!FMath::IsNearlyZero(progress))
	{
		// if achievement is on cooldown, don't queue it
		if (m_progressCooldowns.Contains(achievementName))
		{
			UE_LOG(AchievementUILog, Log, TEXT("Achievement '%s' is on cooldown"), *name.ToString());
			return;
		}

		m_progressCooldowns.Add(achievementName, 0.f);
	}

	m_queuedPopups.Add(FAchievementNameAndIcon(name, icon, progress));
}

bool UAchievementUIManager::CreateAchievementList()
{
	const auto settings = UAchievementPluginSettings::Get();
	if (settings->achievementListWidget)
	{
		AchievementListWidget = CreateWidget<UAchievementListWidget>(GetWorld(), settings->achievementListWidget);
		if (AchievementListWidget)
		{
			AchievementListWidget->AddToViewport();
			AchievementListWidget->SetVisibility(ESlateVisibility::Collapsed);
			AchievementListWidget->PopulateList();
			return true;
		}
	}
	return false;
}

bool UAchievementUIManager::ShowAchievementList() const
{
	if (AchievementListWidget)
	{
		AchievementListWidget->RefreshDisplay();
		AchievementListWidget->SetVisibility(ESlateVisibility::Visible);
		return true;
	}
	return false;
}

bool UAchievementUIManager::HideAchievementList() const
{
	if (AchievementListWidget)
	{
		AchievementListWidget->SetVisibility(ESlateVisibility::Collapsed);
		return true;
	}
	return false;
}

bool UAchievementUIManager::ForceUpdateAchievementList() const
{
	if (AchievementListWidget)
	{
		AchievementListWidget->RefreshDisplay();
		return true;
	}
	return false;
}

bool UAchievementUIManager::ChangeAchievementListFilters(const FAchievementFilterSettings& filter)
{
	if (AchievementListWidget)
	{
		AchievementListWidget->ApplyFilter(filter);
		return true;
	}
	return false;
}

void UAchievementUIManager::Tick(const float deltaTime)
{
		// progress cooldowns
		if (m_progressCooldowns.Num() > 0)
		{
			const auto& cooldownTime = UAchievementPluginSettings::Get()->achievementWidgetSettings.delayBetweenSameProgressAchievementPopup;
			// iterate through all elements, increase cooldown timer and remove if timer is more than or equal to the cooldown time
			for (auto it = m_progressCooldowns.CreateIterator(); it; ++it)
			{
				it.Value() += deltaTime;

				if (it.Value() >= cooldownTime)
				{
					it.RemoveCurrent();
				}
			}
		}

	if (m_queuedPopups.Num() > 0)
	{
		// if there are less popups than we can have
		if (m_popupInstances.Num() < m_maxPopupsCachedValue)
		{
			const auto data = m_queuedPopups[0];
			m_queuedPopups.RemoveAt(0);

			// create the new Popup (widget)
			auto* widget = CreateWidgetInstance();

			if (!widget)
			{
				UE_LOG(AchievementUILog, Error, TEXT("Something went wrong creating a Widget, please restart the engine if this occurs more!"));
				return;
			}

			// find the name variable
			if (auto* textBlock = Cast<UTextBlock>(widget->GetWidgetFromName(TEXT("AchievementName"))))
			{
				FText name = data.name;
				if (name.IsEmpty())
				{
					name = FText::FromString("ERROR, Empty name!");
					UE_LOG(AchievementUILog, Warning, TEXT("Popup didn't get a name!"))
				}
				textBlock->SetText(data.name);
			}
			else UE_LOG(AchievementUILog, Warning, TEXT("Could not find TextBlock on Widget. Use the name AchievementName and set it to IsVariable!"));
			// find the image variable
			if (auto* image = Cast<UImage>(widget->GetWidgetFromName(TEXT("AchievementImage"))))
			{
				if (!data.image.IsNull())
				{
					image->SetBrushFromTexture(data.image.LoadSynchronous());
				}
				else UE_LOG(AchievementUILog, Warning, TEXT("Popup didn't get a texture!"));
			}
			else UE_LOG(AchievementUILog, Warning, TEXT("Could not find Image on Widget. Use the name AchievementImage and set it to IsVariable!"));
			// if progress is used, also enable progress bar
			if (auto* progressBar = Cast<UProgressBar>(widget->GetWidgetFromName(TEXT("AchievementProgressBar"))))
			{
				if (!FMath::IsNearlyZero(data.progress))
				{
					progressBar->SetVisibility(ESlateVisibility::Visible);
					progressBar->SetPercent(data.progress);
				}

				else
				{
					progressBar->SetVisibility(ESlateVisibility::Collapsed);
				}

			}
			else UE_LOG(AchievementUILog, Warning, TEXT("Could not find ProgressBar on Widget. Use the name AchievementProgressBar and set it to IsVariable!"));

			widget->AddToViewport();

			const int widgetInstanceIndex = m_popupInstances.Num() - 1;
			PositionWidget(widgetInstanceIndex);
		}
	}
}

UUserWidget* UAchievementUIManager::CreateWidgetInstance()
{
	if (const UAchievementPluginSettings* settings = UAchievementPluginSettings::Get())
	{
		auto* widget = CreateWidget<UUserWidget>(m_cachedWorld, settings->achievementWidgetSettings.achievementWidget);
		if (!widget)
		{
			UE_LOG(AchievementUILog, Error, TEXT("Could not create achievement widget!"));
			return nullptr;
		}
		m_popupInstances.Add(widget);
		return widget;
	}
	return nullptr;
}

bool UAchievementUIManager::DeleteFirstWidgetInstance()
{
	if (m_popupInstances.Num() == 0) return false;

	const auto widgetToRemove = m_popupInstances[0];

	m_popupInstances.RemoveAt(0);

	if (widgetToRemove)
	{
		// according to the UE5 API, RemoveFromViewport is deprecated, and they recommend using RemoveFromParent instead
		widgetToRemove->RemoveFromParent();
	}
	UE_LOG(AchievementUILog, Log, TEXT("Deleting current Widget instance"));

	RepositionAllWidgets();

	return true;
}

void UAchievementUIManager::PositionWidget(const int32 index)
{
	const auto& widget = m_popupInstances[index];

	if (auto* rootWidget = widget->GetRootWidget())
	{
		const FVector2D translation(0.0f, -(index * m_distanceBetweenPopupsCachedValue));
		rootWidget->SetRenderTranslation(translation);
	}
}

void UAchievementUIManager::RepositionAllWidgets()
{
	const auto amount = m_popupInstances.Num();
	for (int i = 0; i < amount; i++)
	{
		if (IsValid(m_popupInstances[i]))
		{
			PositionWidget(i);
		}
	}
}
