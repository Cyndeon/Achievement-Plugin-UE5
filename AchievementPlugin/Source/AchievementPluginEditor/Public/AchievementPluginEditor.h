// -------------------------------------------------------------
// Copyright 2025 Justin Comans. Licensed under CC BY 4.0.    ||
// -------------------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FAchievementPluginEditorModule : public IModuleInterface
{
public:
	static FAchievementPluginEditorModule* Get()
	{
		return FModuleManager::GetModulePtr<FAchievementPluginEditorModule>("AchievementPluginEditor");
	}

	/** IModuleInterface implementation */
	virtual void StartupModule() override;

	virtual void ShutdownModule() override;
};