// -------------------------------------------------------------
// Copyright 2025 Justin Comans. All rights reserved.         ||
// -------------------------------------------------------------


#include "UAchievementListWidget.h"
#include "UAchievementRowData.h"
#include "AchievementPlugin.h"
#include "Components/ListView.h"

void UAchievementListWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (const auto* settings = UAchievementPluginSettings::Get())
	{
		CurrentFilter = settings->defaultAchievementListFilter;
	}
}

void UAchievementListWidget::PopulateList()
{
	ClearList();

	TArray<FString> SortedIds = GetFilteredAndSortedIds();

	for (const FString& Id : SortedIds)
	{
		UAchievementRowData* RowData = NewObject<UAchievementRowData>(this);
		RowData->AchievementId = Id;

		RowDataObjects.Add(RowData);
		AchievementListView->AddItem(RowData);
	}
}

void UAchievementListWidget::RefreshDisplay() const
{
	if (AchievementListView)
	{
		AchievementListView->RegenerateAllEntries();
	}
}

void UAchievementListWidget::ClearList()
{
	if (AchievementListView)
	{
		AchievementListView->ClearListItems();
	}
	RowDataObjects.Empty();
}

void UAchievementListWidget::ApplyFilter(const FAchievementFilterSettings& NewFilter)
{
	CurrentFilter = NewFilter;
	PopulateList();
}

void UAchievementListWidget::SetSearchText(const FString& NewSearchText)
{
	PendingSearchText = NewSearchText;

	// Clear existing timer
	if (const UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(SearchDebounceTimer);

		// Wait x seconds before actually searching
		World->GetTimerManager().SetTimer(
			SearchDebounceTimer,
			[this]()
			{
				if (CurrentFilter.SearchText != PendingSearchText)
				{
					CurrentFilter.SearchText = PendingSearchText;
					PopulateList();
				}
			},
			WaitTime,
			false
		);
	}
}

TArray<FString> UAchievementListWidget::GetFilteredAndSortedIds() const
{
	TArray<FString> Result;

	const auto& Settings = UAchievementPluginSettings::Get();
	if (!Settings)
	{
		return Result;
	}

	UAchievementManagerSubSystem* Subsystem = UAchievementManagerSubSystem::Get();
	if (!Subsystem)
	{
		return Result;
	}

	// Prepare search text (lowercase for case-insensitive search)
	const FString searchLower = CurrentFilter.SearchText.ToLower().TrimStartAndEnd();
	const bool hasSearch = !searchLower.IsEmpty();

	// Gather and filter
	for (const auto& Pair : Settings->achievementsData)
	{
		const FString& Id = Pair.Key;
		const FAchievementData& Data = Pair.Value;

		const auto LinkId = Data.GetLinkID();
		const FAchievementProgress* Progress = Subsystem->GetAchievementProgressByLinkId(LinkId);

		const bool bUnlocked = Progress && Progress->progress >= Data.progressGoal;

		// Apply visibility filters
		if (CurrentFilter.hideUnlocked && bUnlocked) continue;
		if (CurrentFilter.hideLocked && !bUnlocked) continue;
		if (CurrentFilter.hideHidden && Data.isHidden) continue;

		// Apply search filter
		if (hasSearch)
		{
			const FString NameLower = Data.displayName.ToString().ToLower();
			const FString DescLower = Data.description.ToString().ToLower();

			if (!NameLower.Contains(searchLower) && !DescLower.Contains(searchLower))
			{
				continue;
			}
		}

		Result.Add(Id);
	}

	// Sort
	if (CurrentFilter.SortMode != EAchievementSortMode::Creator)
	{
		Result.Sort([&Settings, Subsystem, this](const FString& A, const FString& B)
		{
			// Null checks
			const auto* DataAPtr = Settings->achievementsData.Find(A);
			const auto* DataBPtr = Settings->achievementsData.Find(B);

			if (!DataAPtr || !DataBPtr)
			{
				return false; // Can't compare, keep original order
			}

			const auto& DataA = *DataAPtr;
			const auto& DataB = *DataBPtr;

			const FAchievementProgress* ProgressA = Subsystem
				                                        ? Subsystem->GetAchievementProgressByLinkId(DataA.GetLinkID())
				                                        : nullptr;
			const FAchievementProgress* ProgressB = Subsystem
				                                        ? Subsystem->GetAchievementProgressByLinkId(DataB.GetLinkID())
				                                        : nullptr;

			const bool UnlockedA = ProgressA && ProgressA->progress >= DataA.progressGoal;
			const bool UnlockedB = ProgressB && ProgressB->progress >= DataB.progressGoal;

			if (CurrentFilter.unlockedAtBottom && UnlockedA != UnlockedB)
			{
				return UnlockedB;
			}

			switch (CurrentFilter.SortMode)
			{
			case EAchievementSortMode::ProgressDescending:
				{
					const float PercentA = DataA.progressGoal > 0
						                       ? (ProgressA ? ProgressA->progress : 0.0f) / static_cast<float>(DataA.
							                       progressGoal)
						                       : 1.0f;
					const float PercentB = DataB.progressGoal > 0
						                       ? (ProgressB ? ProgressB->progress : 0.0f) / static_cast<float>(DataB.
							                       progressGoal)
						                       : 1.0f;
					return PercentA > PercentB;
				}

			case EAchievementSortMode::ProgressAscending:
				{
					const float PercentA = DataA.progressGoal > 0
						                       ? (ProgressA ? ProgressA->progress : 0.0f) / static_cast<float>(DataA.
							                       progressGoal)
						                       : 1.0f;
					const float PercentB = DataB.progressGoal > 0
						                       ? (ProgressB ? ProgressB->progress : 0.0f) / static_cast<float>(DataB.
							                       progressGoal)
						                       : 1.0f;
					return PercentA < PercentB;
				}

			case EAchievementSortMode::Alphabetical:
				return DataA.displayName.CompareTo(DataB.displayName) < 0;

			case EAchievementSortMode::AlphabeticalReverse:
				return DataA.displayName.CompareTo(DataB.displayName) > 0;

			default:
				return false;
			}
		});
	}
	else if (CurrentFilter.unlockedAtBottom)
	{
		Result.Sort([&Settings, Subsystem](const FString& A, const FString& B)
		{
			const auto& DataA = *Settings->achievementsData.Find(A);
			const auto& DataB = *Settings->achievementsData.Find(B);

			const FAchievementProgress* ProgressA = Subsystem->GetAchievementProgressByLinkId(DataA.GetLinkID());
			const FAchievementProgress* ProgressB = Subsystem->GetAchievementProgressByLinkId(DataB.GetLinkID());
			const bool UnlockedA = ProgressA && ProgressA->progress >= DataA.progressGoal;
			const bool UnlockedB = ProgressB && ProgressB->progress >= DataB.progressGoal;

			if (UnlockedA != UnlockedB)
			{
				return UnlockedB;
			}

			return false;
		});
	}

	return Result;
}
