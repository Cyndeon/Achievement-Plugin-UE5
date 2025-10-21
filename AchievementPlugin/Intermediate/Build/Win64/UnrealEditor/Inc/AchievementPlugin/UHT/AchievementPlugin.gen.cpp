// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AchievementPlugin/Public/AchievementPlugin.h"
#include "AchievementPlugin/Public/AchievementStructs.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAchievementPlugin() {}

// Begin Cross Module References
ACHIEVEMENTPLUGIN_API UClass* Z_Construct_UClass_UAchievementManagerSubSystem();
ACHIEVEMENTPLUGIN_API UClass* Z_Construct_UClass_UAchievementManagerSubSystem_NoRegister();
ACHIEVEMENTPLUGIN_API UClass* Z_Construct_UClass_UAchievementPluginSettings();
ACHIEVEMENTPLUGIN_API UClass* Z_Construct_UClass_UAchievementPluginSettings_NoRegister();
ACHIEVEMENTPLUGIN_API UClass* Z_Construct_UClass_UAchievementSaveManager_NoRegister();
ACHIEVEMENTPLUGIN_API UEnum* Z_Construct_UEnum_AchievementPlugin_EAchievementPlatforms();
ACHIEVEMENTPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAchievementData();
ACHIEVEMENTPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAchievementProgress();
ACHIEVEMENTPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAchievementWidgetSettings();
ACHIEVEMENTPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FEpicGamesInfo();
ACHIEVEMENTPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FSaveSlotSettings();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ENGINE_API UClass* Z_Construct_UClass_UEngineSubsystem();
ENGINE_API UClass* Z_Construct_UClass_UWorld_NoRegister();
UPackage* Z_Construct_UPackage__Script_AchievementPlugin();
// End Cross Module References

// Begin Class UAchievementPluginSettings Function IsEpicPlatform
struct Z_Construct_UFunction_UAchievementPluginSettings_IsEpicPlatform_Statics
{
	struct AchievementPluginSettings_eventIsEpicPlatform_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UAchievementPluginSettings_IsEpicPlatform_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((AchievementPluginSettings_eventIsEpicPlatform_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAchievementPluginSettings_IsEpicPlatform_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AchievementPluginSettings_eventIsEpicPlatform_Parms), &Z_Construct_UFunction_UAchievementPluginSettings_IsEpicPlatform_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAchievementPluginSettings_IsEpicPlatform_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAchievementPluginSettings_IsEpicPlatform_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginSettings_IsEpicPlatform_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAchievementPluginSettings_IsEpicPlatform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAchievementPluginSettings, nullptr, "IsEpicPlatform", nullptr, nullptr, Z_Construct_UFunction_UAchievementPluginSettings_IsEpicPlatform_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginSettings_IsEpicPlatform_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAchievementPluginSettings_IsEpicPlatform_Statics::AchievementPluginSettings_eventIsEpicPlatform_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginSettings_IsEpicPlatform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAchievementPluginSettings_IsEpicPlatform_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UAchievementPluginSettings_IsEpicPlatform_Statics::AchievementPluginSettings_eventIsEpicPlatform_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAchievementPluginSettings_IsEpicPlatform()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAchievementPluginSettings_IsEpicPlatform_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAchievementPluginSettings::execIsEpicPlatform)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsEpicPlatform();
	P_NATIVE_END;
}
// End Class UAchievementPluginSettings Function IsEpicPlatform

// Begin Class UAchievementPluginSettings Function IsSteamPlatform
struct Z_Construct_UFunction_UAchievementPluginSettings_IsSteamPlatform_Statics
{
	struct AchievementPluginSettings_eventIsSteamPlatform_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// used for hiding variables\n" },
#endif
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "used for hiding variables" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UAchievementPluginSettings_IsSteamPlatform_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((AchievementPluginSettings_eventIsSteamPlatform_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAchievementPluginSettings_IsSteamPlatform_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AchievementPluginSettings_eventIsSteamPlatform_Parms), &Z_Construct_UFunction_UAchievementPluginSettings_IsSteamPlatform_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAchievementPluginSettings_IsSteamPlatform_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAchievementPluginSettings_IsSteamPlatform_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginSettings_IsSteamPlatform_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAchievementPluginSettings_IsSteamPlatform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAchievementPluginSettings, nullptr, "IsSteamPlatform", nullptr, nullptr, Z_Construct_UFunction_UAchievementPluginSettings_IsSteamPlatform_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginSettings_IsSteamPlatform_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAchievementPluginSettings_IsSteamPlatform_Statics::AchievementPluginSettings_eventIsSteamPlatform_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginSettings_IsSteamPlatform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAchievementPluginSettings_IsSteamPlatform_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UAchievementPluginSettings_IsSteamPlatform_Statics::AchievementPluginSettings_eventIsSteamPlatform_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAchievementPluginSettings_IsSteamPlatform()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAchievementPluginSettings_IsSteamPlatform_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAchievementPluginSettings::execIsSteamPlatform)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsSteamPlatform();
	P_NATIVE_END;
}
// End Class UAchievementPluginSettings Function IsSteamPlatform

// Begin Class UAchievementPluginSettings
void UAchievementPluginSettings::StaticRegisterNativesUAchievementPluginSettings()
{
	UClass* Class = UAchievementPluginSettings::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "IsEpicPlatform", &UAchievementPluginSettings::execIsEpicPlatform },
		{ "IsSteamPlatform", &UAchievementPluginSettings::execIsSteamPlatform },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAchievementPluginSettings);
UClass* Z_Construct_UClass_UAchievementPluginSettings_NoRegister()
{
	return UAchievementPluginSettings::StaticClass();
}
struct Z_Construct_UClass_UAchievementPluginSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "Achievement System" },
		{ "IncludePath", "AchievementPlugin.h" },
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_defaultSaveSlotSettings_MetaData[] = {
		{ "Category", "Save Slot Settings" },
		{ "DisplayName", "Default Save Slot Settings" },
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
#if !UE_BUILD_SHIPPING
		{ "Tooltip", "The defaults used for the saved profiles for achievementsData. Modifying this can cause old achievement progress to break" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_achievementsData_MetaData[] = {
		{ "Category", "Achievements" },
		{ "DisplayName", "AchievementsData" },
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Key: Name used for modifying achievementsData in Blueprint Nodes, Value: Achievement settings" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCleanupAchievements_MetaData[] = {
		{ "Category", "Achievement Settings" },
		{ "DisplayName", "Cleanup Achievements on Load" },
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If enabled, will delete any achievement progress for achievements that no longer exist" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_achievementWidgetSettings_MetaData[] = {
		{ "Category", "Achievement Widget Settings" },
		{ "DisplayName", "Achievement Widget Settings" },
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
	};
#if WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLoadRuntimeStatsButton_MetaData[] = {
		{ "Category", "Achievements Settings Buttons" },
		{ "DisplayName", "Load/Update Runtime Stats" },
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
#if !UE_BUILD_SHIPPING
		{ "Tooltip", "Enable this to update the runtime stats (progress) of the achievementsData" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bForceSaveAchievementProgress_MetaData[] = {
		{ "Category", "Achievements Settings Buttons" },
		{ "DisplayName", "Force Save Achievment Progress" },
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bForceLoadAchievementProgress_MetaData[] = {
		{ "Category", "Achievements Settings Buttons" },
		{ "DisplayName", "Force Load Achievement Progress" },
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bForceDownloadPlatformAchievements_MetaData[] = {
		{ "Category", "Achievements Platform Buttons" },
		{ "DisplayName", "Force Download Selected Platform Achievements" },
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
#if !UE_BUILD_SHIPPING
		{ "Tooltip", "This will override all your achievements with those from the selected platform. Please note that some variables will still have to be set manually!" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bForceDownloadPlatformAchievementsSafetyCheck_MetaData[] = {
		{ "Category", "Achievements Platform Buttons" },
		{ "DisplayName", "This cannot be undone unless you make a backup of your current DefaultGame.ini!" },
		{ "EditCondition", "bForceDownloadPlatformAchievements" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
#if !UE_BUILD_SHIPPING
		{ "Tooltip", "Start Download (might take a little bit depending on the amount of achievements and selected platform)!" },
#endif
	};
#endif // WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_nextLinkID_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// this is only used to \"generate\" the next ID for achievements\n" },
#endif
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "this is only used to \"generate\" the next ID for achievements" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_achievementPlatform_MetaData[] = {
		{ "Category", "Platform Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// platform specific data\n" },
#endif
		{ "DisplayName", "Achievement Platform" },
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "platform specific data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_initializePlatform_MetaData[] = {
		{ "Category", "Platform Settings" },
		{ "DisplayName", "Initialize Platform" },
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
#if !UE_BUILD_SHIPPING
		{ "Tooltip", "This will Initialize and Deinitialize the platform's API, disable this if you want to set it up yourself! If setting up manually, make sure to also call AchievementPlatformInitialized in your level blueprint!" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_steamAppID_MetaData[] = {
		{ "Category", "Platform Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Steam\n" },
#endif
		{ "DisplayName", "Steam App ID" },
		{ "EditCondition", "IsSteamPlatform" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Steam" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_EOSInfo_MetaData[] = {
		{ "Category", "Platform Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// EOS\n" },
#endif
		{ "DisplayName", "EOS Info" },
		{ "EditCondition", "IsEpicPlatform" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "EOS" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_defaultSaveSlotSettings;
	static const UECodeGen_Private::FStructPropertyParams NewProp_achievementsData_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_achievementsData_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_achievementsData;
	static void NewProp_bCleanupAchievements_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCleanupAchievements;
	static const UECodeGen_Private::FStructPropertyParams NewProp_achievementWidgetSettings;
#if WITH_EDITORONLY_DATA
	static void NewProp_bLoadRuntimeStatsButton_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLoadRuntimeStatsButton;
	static void NewProp_bForceSaveAchievementProgress_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceSaveAchievementProgress;
	static void NewProp_bForceLoadAchievementProgress_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceLoadAchievementProgress;
	static void NewProp_bForceDownloadPlatformAchievements_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceDownloadPlatformAchievements;
	static void NewProp_bForceDownloadPlatformAchievementsSafetyCheck_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceDownloadPlatformAchievementsSafetyCheck;
#endif // WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_m_nextLinkID;
	static const UECodeGen_Private::FBytePropertyParams NewProp_m_achievementPlatform;
	static void NewProp_m_initializePlatform_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_m_initializePlatform;
	static const UECodeGen_Private::FIntPropertyParams NewProp_m_steamAppID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_m_EOSInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAchievementPluginSettings_IsEpicPlatform, "IsEpicPlatform" }, // 2576177927
		{ &Z_Construct_UFunction_UAchievementPluginSettings_IsSteamPlatform, "IsSteamPlatform" }, // 3312598421
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAchievementPluginSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_defaultSaveSlotSettings = { "defaultSaveSlotSettings", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAchievementPluginSettings, defaultSaveSlotSettings), Z_Construct_UScriptStruct_FSaveSlotSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_defaultSaveSlotSettings_MetaData), NewProp_defaultSaveSlotSettings_MetaData) }; // 4192245414
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_achievementsData_ValueProp = { "achievementsData", nullptr, (EPropertyFlags)0x0000000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FAchievementData, METADATA_PARAMS(0, nullptr) }; // 3517175688
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_achievementsData_Key_KeyProp = { "achievementsData_Key", nullptr, (EPropertyFlags)0x0000000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_achievementsData = { "achievementsData", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAchievementPluginSettings, achievementsData), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_achievementsData_MetaData), NewProp_achievementsData_MetaData) }; // 3517175688
void Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bCleanupAchievements_SetBit(void* Obj)
{
	((UAchievementPluginSettings*)Obj)->bCleanupAchievements = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bCleanupAchievements = { "bCleanupAchievements", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAchievementPluginSettings), &Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bCleanupAchievements_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCleanupAchievements_MetaData), NewProp_bCleanupAchievements_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_achievementWidgetSettings = { "achievementWidgetSettings", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAchievementPluginSettings, achievementWidgetSettings), Z_Construct_UScriptStruct_FAchievementWidgetSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_achievementWidgetSettings_MetaData), NewProp_achievementWidgetSettings_MetaData) }; // 807818618
#if WITH_EDITORONLY_DATA
void Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bLoadRuntimeStatsButton_SetBit(void* Obj)
{
	((UAchievementPluginSettings*)Obj)->bLoadRuntimeStatsButton = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bLoadRuntimeStatsButton = { "bLoadRuntimeStatsButton", nullptr, (EPropertyFlags)0x0010000800002001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAchievementPluginSettings), &Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bLoadRuntimeStatsButton_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLoadRuntimeStatsButton_MetaData), NewProp_bLoadRuntimeStatsButton_MetaData) };
void Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bForceSaveAchievementProgress_SetBit(void* Obj)
{
	((UAchievementPluginSettings*)Obj)->bForceSaveAchievementProgress = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bForceSaveAchievementProgress = { "bForceSaveAchievementProgress", nullptr, (EPropertyFlags)0x0010000800002001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAchievementPluginSettings), &Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bForceSaveAchievementProgress_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bForceSaveAchievementProgress_MetaData), NewProp_bForceSaveAchievementProgress_MetaData) };
void Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bForceLoadAchievementProgress_SetBit(void* Obj)
{
	((UAchievementPluginSettings*)Obj)->bForceLoadAchievementProgress = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bForceLoadAchievementProgress = { "bForceLoadAchievementProgress", nullptr, (EPropertyFlags)0x0010000800002001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAchievementPluginSettings), &Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bForceLoadAchievementProgress_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bForceLoadAchievementProgress_MetaData), NewProp_bForceLoadAchievementProgress_MetaData) };
void Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bForceDownloadPlatformAchievements_SetBit(void* Obj)
{
	((UAchievementPluginSettings*)Obj)->bForceDownloadPlatformAchievements = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bForceDownloadPlatformAchievements = { "bForceDownloadPlatformAchievements", nullptr, (EPropertyFlags)0x0010000800002001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAchievementPluginSettings), &Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bForceDownloadPlatformAchievements_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bForceDownloadPlatformAchievements_MetaData), NewProp_bForceDownloadPlatformAchievements_MetaData) };
void Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bForceDownloadPlatformAchievementsSafetyCheck_SetBit(void* Obj)
{
	((UAchievementPluginSettings*)Obj)->bForceDownloadPlatformAchievementsSafetyCheck = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bForceDownloadPlatformAchievementsSafetyCheck = { "bForceDownloadPlatformAchievementsSafetyCheck", nullptr, (EPropertyFlags)0x0010000800002001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAchievementPluginSettings), &Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bForceDownloadPlatformAchievementsSafetyCheck_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bForceDownloadPlatformAchievementsSafetyCheck_MetaData), NewProp_bForceDownloadPlatformAchievementsSafetyCheck_MetaData) };
#endif // WITH_EDITORONLY_DATA
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_m_nextLinkID = { "m_nextLinkID", nullptr, (EPropertyFlags)0x0040000000004000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAchievementPluginSettings, m_nextLinkID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_nextLinkID_MetaData), NewProp_m_nextLinkID_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_m_achievementPlatform = { "m_achievementPlatform", nullptr, (EPropertyFlags)0x0040000000004001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAchievementPluginSettings, m_achievementPlatform), Z_Construct_UEnum_AchievementPlugin_EAchievementPlatforms, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_achievementPlatform_MetaData), NewProp_m_achievementPlatform_MetaData) }; // 2394143095
void Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_m_initializePlatform_SetBit(void* Obj)
{
	((UAchievementPluginSettings*)Obj)->m_initializePlatform = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_m_initializePlatform = { "m_initializePlatform", nullptr, (EPropertyFlags)0x0040000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAchievementPluginSettings), &Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_m_initializePlatform_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_initializePlatform_MetaData), NewProp_m_initializePlatform_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_m_steamAppID = { "m_steamAppID", nullptr, (EPropertyFlags)0x0040000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAchievementPluginSettings, m_steamAppID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_steamAppID_MetaData), NewProp_m_steamAppID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_m_EOSInfo = { "m_EOSInfo", nullptr, (EPropertyFlags)0x0040000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAchievementPluginSettings, m_EOSInfo), Z_Construct_UScriptStruct_FEpicGamesInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_EOSInfo_MetaData), NewProp_m_EOSInfo_MetaData) }; // 1048789805
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAchievementPluginSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_defaultSaveSlotSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_achievementsData_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_achievementsData_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_achievementsData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bCleanupAchievements,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_achievementWidgetSettings,
#if WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bLoadRuntimeStatsButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bForceSaveAchievementProgress,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bForceLoadAchievementProgress,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bForceDownloadPlatformAchievements,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_bForceDownloadPlatformAchievementsSafetyCheck,
#endif // WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_m_nextLinkID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_m_achievementPlatform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_m_initializePlatform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_m_steamAppID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPluginSettings_Statics::NewProp_m_EOSInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementPluginSettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UAchievementPluginSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_AchievementPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementPluginSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAchievementPluginSettings_Statics::ClassParams = {
	&UAchievementPluginSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UAchievementPluginSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementPluginSettings_Statics::PropPointers),
	0,
	0x000000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementPluginSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UAchievementPluginSettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAchievementPluginSettings()
{
	if (!Z_Registration_Info_UClass_UAchievementPluginSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAchievementPluginSettings.OuterSingleton, Z_Construct_UClass_UAchievementPluginSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAchievementPluginSettings.OuterSingleton;
}
template<> ACHIEVEMENTPLUGIN_API UClass* StaticClass<UAchievementPluginSettings>()
{
	return UAchievementPluginSettings::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAchievementPluginSettings);
UAchievementPluginSettings::~UAchievementPluginSettings() {}
// End Class UAchievementPluginSettings

// Begin Class UAchievementManagerSubSystem Function OnWorldCleanup
struct Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics
{
	struct AchievementManagerSubSystem_eventOnWorldCleanup_Parms
	{
		const UWorld* world;
		bool bSessionEnded;
		bool bCleanupResources;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_world_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_world;
	static void NewProp_bSessionEnded_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSessionEnded;
	static void NewProp_bCleanupResources_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCleanupResources;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics::NewProp_world = { "world", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AchievementManagerSubSystem_eventOnWorldCleanup_Parms, world), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_world_MetaData), NewProp_world_MetaData) };
void Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics::NewProp_bSessionEnded_SetBit(void* Obj)
{
	((AchievementManagerSubSystem_eventOnWorldCleanup_Parms*)Obj)->bSessionEnded = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics::NewProp_bSessionEnded = { "bSessionEnded", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AchievementManagerSubSystem_eventOnWorldCleanup_Parms), &Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics::NewProp_bSessionEnded_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics::NewProp_bCleanupResources_SetBit(void* Obj)
{
	((AchievementManagerSubSystem_eventOnWorldCleanup_Parms*)Obj)->bCleanupResources = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics::NewProp_bCleanupResources = { "bCleanupResources", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AchievementManagerSubSystem_eventOnWorldCleanup_Parms), &Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics::NewProp_bCleanupResources_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics::NewProp_world,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics::NewProp_bSessionEnded,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics::NewProp_bCleanupResources,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAchievementManagerSubSystem, nullptr, "OnWorldCleanup", nullptr, nullptr, Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics::AchievementManagerSubSystem_eventOnWorldCleanup_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics::AchievementManagerSubSystem_eventOnWorldCleanup_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAchievementManagerSubSystem::execOnWorldCleanup)
{
	P_GET_OBJECT(UWorld,Z_Param_world);
	P_GET_UBOOL(Z_Param_bSessionEnded);
	P_GET_UBOOL(Z_Param_bCleanupResources);
	P_FINISH;
	P_NATIVE_BEGIN;
	UAchievementManagerSubSystem::OnWorldCleanup(Z_Param_world,Z_Param_bSessionEnded,Z_Param_bCleanupResources);
	P_NATIVE_END;
}
// End Class UAchievementManagerSubSystem Function OnWorldCleanup

// Begin Class UAchievementManagerSubSystem Function OnWorldInitialized
struct Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldInitialized_Statics
{
	struct AchievementManagerSubSystem_eventOnWorldInitialized_Parms
	{
		const UWorld* world;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_world_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_world;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldInitialized_Statics::NewProp_world = { "world", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AchievementManagerSubSystem_eventOnWorldInitialized_Parms, world), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_world_MetaData), NewProp_world_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldInitialized_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldInitialized_Statics::NewProp_world,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldInitialized_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldInitialized_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAchievementManagerSubSystem, nullptr, "OnWorldInitialized", nullptr, nullptr, Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldInitialized_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldInitialized_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldInitialized_Statics::AchievementManagerSubSystem_eventOnWorldInitialized_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldInitialized_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldInitialized_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldInitialized_Statics::AchievementManagerSubSystem_eventOnWorldInitialized_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldInitialized()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldInitialized_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAchievementManagerSubSystem::execOnWorldInitialized)
{
	P_GET_OBJECT(UWorld,Z_Param_world);
	P_FINISH;
	P_NATIVE_BEGIN;
	UAchievementManagerSubSystem::OnWorldInitialized(Z_Param_world);
	P_NATIVE_END;
}
// End Class UAchievementManagerSubSystem Function OnWorldInitialized

// Begin Class UAchievementManagerSubSystem
void UAchievementManagerSubSystem::StaticRegisterNativesUAchievementManagerSubSystem()
{
	UClass* Class = UAchievementManagerSubSystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnWorldCleanup", &UAchievementManagerSubSystem::execOnWorldCleanup },
		{ "OnWorldInitialized", &UAchievementManagerSubSystem::execOnWorldInitialized },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAchievementManagerSubSystem);
UClass* Z_Construct_UClass_UAchievementManagerSubSystem_NoRegister()
{
	return UAchievementManagerSubSystem::StaticClass();
}
struct Z_Construct_UClass_UAchievementManagerSubSystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AchievementPlugin.h" },
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_achievementsProgress_MetaData[] = {
		{ "Category", "Achievements" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// the 'Key' is the LinkID that the achievementData has\n" },
#endif
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "the 'Key' is the LinkID that the achievementData has" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_saveManager_MetaData[] = {
		{ "ModuleRelativePath", "Public/AchievementPlugin.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_achievementsProgress_ValueProp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_achievementsProgress_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_achievementsProgress;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_saveManager;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldCleanup, "OnWorldCleanup" }, // 1960008105
		{ &Z_Construct_UFunction_UAchievementManagerSubSystem_OnWorldInitialized, "OnWorldInitialized" }, // 2937053686
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAchievementManagerSubSystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAchievementManagerSubSystem_Statics::NewProp_achievementsProgress_ValueProp = { "achievementsProgress", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FAchievementProgress, METADATA_PARAMS(0, nullptr) }; // 2518374241
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UAchievementManagerSubSystem_Statics::NewProp_achievementsProgress_Key_KeyProp = { "achievementsProgress_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UAchievementManagerSubSystem_Statics::NewProp_achievementsProgress = { "achievementsProgress", nullptr, (EPropertyFlags)0x0010000001000014, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAchievementManagerSubSystem, achievementsProgress), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_achievementsProgress_MetaData), NewProp_achievementsProgress_MetaData) }; // 2518374241
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAchievementManagerSubSystem_Statics::NewProp_m_saveManager = { "m_saveManager", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAchievementManagerSubSystem, m_saveManager), Z_Construct_UClass_UAchievementSaveManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_saveManager_MetaData), NewProp_m_saveManager_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAchievementManagerSubSystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementManagerSubSystem_Statics::NewProp_achievementsProgress_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementManagerSubSystem_Statics::NewProp_achievementsProgress_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementManagerSubSystem_Statics::NewProp_achievementsProgress,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementManagerSubSystem_Statics::NewProp_m_saveManager,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementManagerSubSystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UAchievementManagerSubSystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEngineSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_AchievementPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementManagerSubSystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAchievementManagerSubSystem_Statics::ClassParams = {
	&UAchievementManagerSubSystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UAchievementManagerSubSystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementManagerSubSystem_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementManagerSubSystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UAchievementManagerSubSystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAchievementManagerSubSystem()
{
	if (!Z_Registration_Info_UClass_UAchievementManagerSubSystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAchievementManagerSubSystem.OuterSingleton, Z_Construct_UClass_UAchievementManagerSubSystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAchievementManagerSubSystem.OuterSingleton;
}
template<> ACHIEVEMENTPLUGIN_API UClass* StaticClass<UAchievementManagerSubSystem>()
{
	return UAchievementManagerSubSystem::StaticClass();
}
UAchievementManagerSubSystem::UAchievementManagerSubSystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAchievementManagerSubSystem);
UAchievementManagerSubSystem::~UAchievementManagerSubSystem() {}
// End Class UAchievementManagerSubSystem

// Begin Registration
struct Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAchievementPluginSettings, UAchievementPluginSettings::StaticClass, TEXT("UAchievementPluginSettings"), &Z_Registration_Info_UClass_UAchievementPluginSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAchievementPluginSettings), 1639801817U) },
		{ Z_Construct_UClass_UAchievementManagerSubSystem, UAchievementManagerSubSystem::StaticClass, TEXT("UAchievementManagerSubSystem"), &Z_Registration_Info_UClass_UAchievementManagerSubSystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAchievementManagerSubSystem), 1496062328U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h_3605967846(TEXT("/Script/AchievementPlugin"),
	Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
