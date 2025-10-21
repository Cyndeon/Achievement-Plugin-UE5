// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AchievementPlugin/Public/UAchievementPopupManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUAchievementPopupManager() {}

// Begin Cross Module References
ACHIEVEMENTPLUGIN_API UClass* Z_Construct_UClass_UAchievementPopupManager();
ACHIEVEMENTPLUGIN_API UClass* Z_Construct_UClass_UAchievementPopupManager_NoRegister();
ACHIEVEMENTPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAchievementNameAndIcon();
ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_AchievementPlugin();
// End Cross Module References

// Begin ScriptStruct FAchievementNameAndIcon
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AchievementNameAndIcon;
class UScriptStruct* FAchievementNameAndIcon::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AchievementNameAndIcon.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AchievementNameAndIcon.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAchievementNameAndIcon, (UObject*)Z_Construct_UPackage__Script_AchievementPlugin(), TEXT("AchievementNameAndIcon"));
	}
	return Z_Registration_Info_UScriptStruct_AchievementNameAndIcon.OuterSingleton;
}
template<> ACHIEVEMENTPLUGIN_API UScriptStruct* StaticStruct<FAchievementNameAndIcon>()
{
	return FAchievementNameAndIcon::StaticStruct();
}
struct Z_Construct_UScriptStruct_FAchievementNameAndIcon_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UAchievementPopupManager.h" },
	};
#endif // WITH_METADATA
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAchievementNameAndIcon>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAchievementNameAndIcon_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_AchievementPlugin,
	nullptr,
	&NewStructOps,
	"AchievementNameAndIcon",
	nullptr,
	0,
	sizeof(FAchievementNameAndIcon),
	alignof(FAchievementNameAndIcon),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAchievementNameAndIcon_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAchievementNameAndIcon_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAchievementNameAndIcon()
{
	if (!Z_Registration_Info_UScriptStruct_AchievementNameAndIcon.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AchievementNameAndIcon.InnerSingleton, Z_Construct_UScriptStruct_FAchievementNameAndIcon_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_AchievementNameAndIcon.InnerSingleton;
}
// End ScriptStruct FAchievementNameAndIcon

// Begin Class UAchievementPopupManager
void UAchievementPopupManager::StaticRegisterNativesUAchievementPopupManager()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAchievementPopupManager);
UClass* Z_Construct_UClass_UAchievementPopupManager_NoRegister()
{
	return UAchievementPopupManager::StaticClass();
}
struct Z_Construct_UClass_UAchievementPopupManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "UAchievementPopupManager.h" },
		{ "ModuleRelativePath", "Public/UAchievementPopupManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_widgetInstances_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UAchievementPopupManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_queuedPopups_MetaData[] = {
		{ "ModuleRelativePath", "Public/UAchievementPopupManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_progressCooldowns_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// used for achievements that are currently \"on cooldown\". Progress achievements only show up once every x seconds\n// this map keeps track of the ones that have been shown before and currently cannot be shown again\n" },
#endif
		{ "ModuleRelativePath", "Public/UAchievementPopupManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "used for achievements that are currently \"on cooldown\". Progress achievements only show up once every x seconds\nthis map keeps track of the ones that have been shown before and currently cannot be shown again" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_maxPopupsCachedValue_MetaData[] = {
		{ "ModuleRelativePath", "Public/UAchievementPopupManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_distanceBetweenPopupsCachedValue_MetaData[] = {
		{ "ModuleRelativePath", "Public/UAchievementPopupManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_widgetInstances_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_m_widgetInstances;
	static const UECodeGen_Private::FStructPropertyParams NewProp_m_queuedPopups_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_m_queuedPopups;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_m_progressCooldowns_ValueProp;
	static const UECodeGen_Private::FNamePropertyParams NewProp_m_progressCooldowns_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_m_progressCooldowns;
	static const UECodeGen_Private::FIntPropertyParams NewProp_m_maxPopupsCachedValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_m_distanceBetweenPopupsCachedValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAchievementPopupManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAchievementPopupManager_Statics::NewProp_m_widgetInstances_Inner = { "m_widgetInstances", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UAchievementPopupManager_Statics::NewProp_m_widgetInstances = { "m_widgetInstances", nullptr, (EPropertyFlags)0x0144008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAchievementPopupManager, m_widgetInstances), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_widgetInstances_MetaData), NewProp_m_widgetInstances_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAchievementPopupManager_Statics::NewProp_m_queuedPopups_Inner = { "m_queuedPopups", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FAchievementNameAndIcon, METADATA_PARAMS(0, nullptr) }; // 3737719844
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UAchievementPopupManager_Statics::NewProp_m_queuedPopups = { "m_queuedPopups", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAchievementPopupManager, m_queuedPopups), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_queuedPopups_MetaData), NewProp_m_queuedPopups_MetaData) }; // 3737719844
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAchievementPopupManager_Statics::NewProp_m_progressCooldowns_ValueProp = { "m_progressCooldowns", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UAchievementPopupManager_Statics::NewProp_m_progressCooldowns_Key_KeyProp = { "m_progressCooldowns_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UAchievementPopupManager_Statics::NewProp_m_progressCooldowns = { "m_progressCooldowns", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAchievementPopupManager, m_progressCooldowns), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_progressCooldowns_MetaData), NewProp_m_progressCooldowns_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UAchievementPopupManager_Statics::NewProp_m_maxPopupsCachedValue = { "m_maxPopupsCachedValue", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAchievementPopupManager, m_maxPopupsCachedValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_maxPopupsCachedValue_MetaData), NewProp_m_maxPopupsCachedValue_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAchievementPopupManager_Statics::NewProp_m_distanceBetweenPopupsCachedValue = { "m_distanceBetweenPopupsCachedValue", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAchievementPopupManager, m_distanceBetweenPopupsCachedValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_distanceBetweenPopupsCachedValue_MetaData), NewProp_m_distanceBetweenPopupsCachedValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAchievementPopupManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPopupManager_Statics::NewProp_m_widgetInstances_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPopupManager_Statics::NewProp_m_widgetInstances,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPopupManager_Statics::NewProp_m_queuedPopups_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPopupManager_Statics::NewProp_m_queuedPopups,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPopupManager_Statics::NewProp_m_progressCooldowns_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPopupManager_Statics::NewProp_m_progressCooldowns_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPopupManager_Statics::NewProp_m_progressCooldowns,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPopupManager_Statics::NewProp_m_maxPopupsCachedValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementPopupManager_Statics::NewProp_m_distanceBetweenPopupsCachedValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementPopupManager_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UAchievementPopupManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_AchievementPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementPopupManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAchievementPopupManager_Statics::ClassParams = {
	&UAchievementPopupManager::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UAchievementPopupManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementPopupManager_Statics::PropPointers),
	0,
	0x008000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementPopupManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UAchievementPopupManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAchievementPopupManager()
{
	if (!Z_Registration_Info_UClass_UAchievementPopupManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAchievementPopupManager.OuterSingleton, Z_Construct_UClass_UAchievementPopupManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAchievementPopupManager.OuterSingleton;
}
template<> ACHIEVEMENTPLUGIN_API UClass* StaticClass<UAchievementPopupManager>()
{
	return UAchievementPopupManager::StaticClass();
}
UAchievementPopupManager::UAchievementPopupManager() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAchievementPopupManager);
UAchievementPopupManager::~UAchievementPopupManager() {}
// End Class UAchievementPopupManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_UAchievementPopupManager_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FAchievementNameAndIcon::StaticStruct, Z_Construct_UScriptStruct_FAchievementNameAndIcon_Statics::NewStructOps, TEXT("AchievementNameAndIcon"), &Z_Registration_Info_UScriptStruct_AchievementNameAndIcon, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAchievementNameAndIcon), 3737719844U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAchievementPopupManager, UAchievementPopupManager::StaticClass, TEXT("UAchievementPopupManager"), &Z_Registration_Info_UClass_UAchievementPopupManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAchievementPopupManager), 396574824U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_UAchievementPopupManager_h_717943296(TEXT("/Script/AchievementPlugin"),
	Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_UAchievementPopupManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_UAchievementPopupManager_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_UAchievementPopupManager_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_UAchievementPopupManager_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
