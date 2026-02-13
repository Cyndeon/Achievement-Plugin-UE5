// -------------------------------------------------------------
// Copyright 2026 Justin Comans. Licensed under CC BY 4.0.    ||
// -------------------------------------------------------------


#include "UAchievementListWidget.h"
#include "UAchievementRowData.h"
#include "AchievementPlugin.h"
#include "Components/ListView.h"

void UAchievementListWidget::PopulateList()
{
	ClearList();
    
	const auto& Settings = UAchievementPluginSettings::Get();
	if (!Settings)
	{
		return;
	}
    
	for (const auto& Pair : Settings->achievementsData)
	{
		UAchievementRowData* RowData = NewObject<UAchievementRowData>(this);
		RowData->AchievementId = Pair.Key;
        
		RowDataObjects.Add(RowData);
		AchievementListView->AddItem(RowData);
	}
}

void UAchievementListWidget::RefreshDisplay() const
{
	if (AchievementListView)
	{
		AchievementListView->RequestRefresh();
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