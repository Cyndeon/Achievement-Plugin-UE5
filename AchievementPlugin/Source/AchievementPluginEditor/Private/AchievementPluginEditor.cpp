// -------------------------------------------------------------
// Copyright 2025 Justin Comans. Licensed under CC BY 4.0.    ||
// -------------------------------------------------------------

#include "AchievementPluginEditor.h"
#include "AchievementPlugin.h"
#include "ISettingsModule.h"

#define LOCTEXT_NAMESPACE "FAchievementPluginEditorModule"


void FAchievementPluginEditorModule::StartupModule()
{
	if (ISettingsModule* settingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		settingsModule->RegisterSettings("Project", "Game", "AchievementPlugin",
										 LOCTEXT("RuntimeSettingsName", "Achievement Plugin"),
										 LOCTEXT("RuntimeSettingsDescription", "Configure Achievement Plugin settings"),
										 GetMutableDefault<UAchievementPluginSettings>()
		);
	}
}

void FAchievementPluginEditorModule::ShutdownModule()
{
	if (ISettingsModule* settingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		settingsModule->UnregisterSettings("Project", "Game", "AchievementPlugin");
	}
}

IMPLEMENT_MODULE(FAchievementPluginEditorModule, AchievementPluginEditor)