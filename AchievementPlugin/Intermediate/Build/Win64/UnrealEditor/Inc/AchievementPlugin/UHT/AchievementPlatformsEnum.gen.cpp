// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AchievementPlugin/Public/AchievementPlatformsEnum.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAchievementPlatformsEnum() {}

// Begin Cross Module References
ACHIEVEMENTPLUGIN_API UEnum* Z_Construct_UEnum_AchievementPlugin_EAchievementPlatforms();
ACHIEVEMENTPLUGIN_API UEnum* Z_Construct_UEnum_AchievementPlugin_EAchievementUploadTypes();
UPackage* Z_Construct_UPackage__Script_AchievementPlugin();
// End Cross Module References

// Begin Enum EAchievementPlatforms
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAchievementPlatforms;
static UEnum* EAchievementPlatforms_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EAchievementPlatforms.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EAchievementPlatforms.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_AchievementPlugin_EAchievementPlatforms, (UObject*)Z_Construct_UPackage__Script_AchievementPlugin(), TEXT("EAchievementPlatforms"));
	}
	return Z_Registration_Info_UEnum_EAchievementPlatforms.OuterSingleton;
}
template<> ACHIEVEMENTPLUGIN_API UEnum* StaticEnum<EAchievementPlatforms>()
{
	return EAchievementPlatforms_StaticEnum();
}
struct Z_Construct_UEnum_AchievementPlugin_EAchievementPlatforms_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "EOS.DisplayName", "EOS" },
		{ "EOS.Name", "EOS" },
		{ "LOCALONLY.DisplayName", "Local Only" },
		{ "LOCALONLY.Name", "LOCALONLY" },
		{ "ModuleRelativePath", "Public/AchievementPlatformsEnum.h" },
		{ "STEAM.DisplayName", "Steam" },
		{ "STEAM.Name", "STEAM" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "LOCALONLY", (int64)LOCALONLY },
		{ "STEAM", (int64)STEAM },
		{ "EOS", (int64)EOS },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_AchievementPlugin_EAchievementPlatforms_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_AchievementPlugin,
	nullptr,
	"EAchievementPlatforms",
	"EAchievementPlatforms",
	Z_Construct_UEnum_AchievementPlugin_EAchievementPlatforms_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_AchievementPlugin_EAchievementPlatforms_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::Regular,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_AchievementPlugin_EAchievementPlatforms_Statics::Enum_MetaDataParams), Z_Construct_UEnum_AchievementPlugin_EAchievementPlatforms_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_AchievementPlugin_EAchievementPlatforms()
{
	if (!Z_Registration_Info_UEnum_EAchievementPlatforms.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAchievementPlatforms.InnerSingleton, Z_Construct_UEnum_AchievementPlugin_EAchievementPlatforms_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EAchievementPlatforms.InnerSingleton;
}
// End Enum EAchievementPlatforms

// Begin Enum EAchievementUploadTypes
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAchievementUploadTypes;
static UEnum* EAchievementUploadTypes_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EAchievementUploadTypes.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EAchievementUploadTypes.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_AchievementPlugin_EAchievementUploadTypes, (UObject*)Z_Construct_UPackage__Script_AchievementPlugin(), TEXT("EAchievementUploadTypes"));
	}
	return Z_Registration_Info_UEnum_EAchievementUploadTypes.OuterSingleton;
}
template<> ACHIEVEMENTPLUGIN_API UEnum* StaticEnum<EAchievementUploadTypes>()
{
	return EAchievementUploadTypes_StaticEnum();
}
struct Z_Construct_UEnum_AchievementPlugin_EAchievementUploadTypes_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Float.Comment", "// cannot use capitals because of the typedef conflict\n" },
		{ "Float.DisplayName", "Float" },
		{ "Float.Name", "Float" },
		{ "Float.ToolTip", "cannot use capitals because of the typedef conflict" },
		{ "Int32.DisplayName", "Int32" },
		{ "Int32.Name", "Int32" },
		{ "ModuleRelativePath", "Public/AchievementPlatformsEnum.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "Float", (int64)Float },
		{ "Int32", (int64)Int32 },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_AchievementPlugin_EAchievementUploadTypes_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_AchievementPlugin,
	nullptr,
	"EAchievementUploadTypes",
	"EAchievementUploadTypes",
	Z_Construct_UEnum_AchievementPlugin_EAchievementUploadTypes_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_AchievementPlugin_EAchievementUploadTypes_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::Regular,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_AchievementPlugin_EAchievementUploadTypes_Statics::Enum_MetaDataParams), Z_Construct_UEnum_AchievementPlugin_EAchievementUploadTypes_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_AchievementPlugin_EAchievementUploadTypes()
{
	if (!Z_Registration_Info_UEnum_EAchievementUploadTypes.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAchievementUploadTypes.InnerSingleton, Z_Construct_UEnum_AchievementPlugin_EAchievementUploadTypes_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EAchievementUploadTypes.InnerSingleton;
}
// End Enum EAchievementUploadTypes

// Begin Registration
struct Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlatformsEnum_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EAchievementPlatforms_StaticEnum, TEXT("EAchievementPlatforms"), &Z_Registration_Info_UEnum_EAchievementPlatforms, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2394143095U) },
		{ EAchievementUploadTypes_StaticEnum, TEXT("EAchievementUploadTypes"), &Z_Registration_Info_UEnum_EAchievementUploadTypes, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 921294432U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlatformsEnum_h_1798896491(TEXT("/Script/AchievementPlugin"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlatformsEnum_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlatformsEnum_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
