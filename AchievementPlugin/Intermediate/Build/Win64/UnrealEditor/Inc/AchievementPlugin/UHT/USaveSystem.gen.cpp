// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AchievementPlugin/Public/USaveSystem.h"
#include "AchievementPlugin/Public/AchievementStructs.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUSaveSystem() {}

// Begin Cross Module References
ACHIEVEMENTPLUGIN_API UClass* Z_Construct_UClass_UAchievementSave();
ACHIEVEMENTPLUGIN_API UClass* Z_Construct_UClass_UAchievementSave_NoRegister();
ACHIEVEMENTPLUGIN_API UClass* Z_Construct_UClass_UAchievementSaveManager();
ACHIEVEMENTPLUGIN_API UClass* Z_Construct_UClass_UAchievementSaveManager_NoRegister();
ACHIEVEMENTPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAchievementProgress();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ENGINE_API UClass* Z_Construct_UClass_USaveGame();
UPackage* Z_Construct_UPackage__Script_AchievementPlugin();
// End Cross Module References

// Begin Class UAchievementSave
void UAchievementSave::StaticRegisterNativesUAchievementSave()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAchievementSave);
UClass* Z_Construct_UClass_UAchievementSave_NoRegister()
{
	return UAchievementSave::StaticClass();
}
struct Z_Construct_UClass_UAchievementSave_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// only used when saving/loading the data\n" },
#endif
		{ "IncludePath", "USaveSystem.h" },
		{ "ModuleRelativePath", "Public/USaveSystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "only used when saving/loading the data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_achievementProgressSave_MetaData[] = {
		{ "ModuleRelativePath", "Public/USaveSystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_achievementProgressSave_ValueProp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_achievementProgressSave_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_achievementProgressSave;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAchievementSave>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAchievementSave_Statics::NewProp_achievementProgressSave_ValueProp = { "achievementProgressSave", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FAchievementProgress, METADATA_PARAMS(0, nullptr) }; // 2518374241
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UAchievementSave_Statics::NewProp_achievementProgressSave_Key_KeyProp = { "achievementProgressSave_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UAchievementSave_Statics::NewProp_achievementProgressSave = { "achievementProgressSave", nullptr, (EPropertyFlags)0x0010000001000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAchievementSave, achievementProgressSave), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_achievementProgressSave_MetaData), NewProp_achievementProgressSave_MetaData) }; // 2518374241
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAchievementSave_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementSave_Statics::NewProp_achievementProgressSave_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementSave_Statics::NewProp_achievementProgressSave_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAchievementSave_Statics::NewProp_achievementProgressSave,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementSave_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UAchievementSave_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USaveGame,
	(UObject* (*)())Z_Construct_UPackage__Script_AchievementPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementSave_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAchievementSave_Statics::ClassParams = {
	&UAchievementSave::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UAchievementSave_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementSave_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementSave_Statics::Class_MetaDataParams), Z_Construct_UClass_UAchievementSave_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAchievementSave()
{
	if (!Z_Registration_Info_UClass_UAchievementSave.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAchievementSave.OuterSingleton, Z_Construct_UClass_UAchievementSave_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAchievementSave.OuterSingleton;
}
template<> ACHIEVEMENTPLUGIN_API UClass* StaticClass<UAchievementSave>()
{
	return UAchievementSave::StaticClass();
}
UAchievementSave::UAchievementSave(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAchievementSave);
UAchievementSave::~UAchievementSave() {}
// End Class UAchievementSave

// Begin Class UAchievementSaveManager
void UAchievementSaveManager::StaticRegisterNativesUAchievementSaveManager()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAchievementSaveManager);
UClass* Z_Construct_UClass_UAchievementSaveManager_NoRegister()
{
	return UAchievementSaveManager::StaticClass();
}
struct Z_Construct_UClass_UAchievementSaveManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// note: this class only exists in UAchievementManagerSubSystem (by default)\n" },
#endif
		{ "IncludePath", "USaveSystem.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/USaveSystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "note: this class only exists in UAchievementManagerSubSystem (by default)" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAchievementSaveManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UAchievementSaveManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_AchievementPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementSaveManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAchievementSaveManager_Statics::ClassParams = {
	&UAchievementSaveManager::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementSaveManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UAchievementSaveManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAchievementSaveManager()
{
	if (!Z_Registration_Info_UClass_UAchievementSaveManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAchievementSaveManager.OuterSingleton, Z_Construct_UClass_UAchievementSaveManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAchievementSaveManager.OuterSingleton;
}
template<> ACHIEVEMENTPLUGIN_API UClass* StaticClass<UAchievementSaveManager>()
{
	return UAchievementSaveManager::StaticClass();
}
UAchievementSaveManager::UAchievementSaveManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAchievementSaveManager);
UAchievementSaveManager::~UAchievementSaveManager() {}
// End Class UAchievementSaveManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_USaveSystem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAchievementSave, UAchievementSave::StaticClass, TEXT("UAchievementSave"), &Z_Registration_Info_UClass_UAchievementSave, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAchievementSave), 3594554928U) },
		{ Z_Construct_UClass_UAchievementSaveManager, UAchievementSaveManager::StaticClass, TEXT("UAchievementSaveManager"), &Z_Registration_Info_UClass_UAchievementSaveManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAchievementSaveManager), 3356875787U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_USaveSystem_h_2996294103(TEXT("/Script/AchievementPlugin"),
	Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_USaveSystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_USaveSystem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
