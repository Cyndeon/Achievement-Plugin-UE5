// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AchievementPlugin/Public/AchievementPlatforms.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAchievementPlatforms() {}

// Begin Cross Module References
ACHIEVEMENTPLUGIN_API UClass* Z_Construct_UClass_UAchievementPlatformsClass();
ACHIEVEMENTPLUGIN_API UClass* Z_Construct_UClass_UAchievementPlatformsClass_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
UPackage* Z_Construct_UPackage__Script_AchievementPlugin();
// End Cross Module References

// Begin Class UAchievementPlatformsClass
void UAchievementPlatformsClass::StaticRegisterNativesUAchievementPlatformsClass()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAchievementPlatformsClass);
UClass* Z_Construct_UClass_UAchievementPlatformsClass_NoRegister()
{
	return UAchievementPlatformsClass::StaticClass();
}
struct Z_Construct_UClass_UAchievementPlatformsClass_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AchievementPlatforms.h" },
		{ "ModuleRelativePath", "Public/AchievementPlatforms.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAchievementPlatformsClass>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UAchievementPlatformsClass_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_AchievementPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementPlatformsClass_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAchievementPlatformsClass_Statics::ClassParams = {
	&UAchievementPlatformsClass::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementPlatformsClass_Statics::Class_MetaDataParams), Z_Construct_UClass_UAchievementPlatformsClass_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAchievementPlatformsClass()
{
	if (!Z_Registration_Info_UClass_UAchievementPlatformsClass.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAchievementPlatformsClass.OuterSingleton, Z_Construct_UClass_UAchievementPlatformsClass_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAchievementPlatformsClass.OuterSingleton;
}
template<> ACHIEVEMENTPLUGIN_API UClass* StaticClass<UAchievementPlatformsClass>()
{
	return UAchievementPlatformsClass::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAchievementPlatformsClass);
UAchievementPlatformsClass::~UAchievementPlatformsClass() {}
// End Class UAchievementPlatformsClass

// Begin Registration
struct Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlatforms_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAchievementPlatformsClass, UAchievementPlatformsClass::StaticClass, TEXT("UAchievementPlatformsClass"), &Z_Registration_Info_UClass_UAchievementPlatformsClass, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAchievementPlatformsClass), 3966297003U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlatforms_h_1249587753(TEXT("/Script/AchievementPlugin"),
	Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlatforms_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlatforms_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
