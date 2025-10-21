// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AchievementPlugin/Public/AchievementPluginBPLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAchievementPluginBPLibrary() {}

// Begin Cross Module References
ACHIEVEMENTPLUGIN_API UClass* Z_Construct_UClass_UAchievementPluginBPLibrary();
ACHIEVEMENTPLUGIN_API UClass* Z_Construct_UClass_UAchievementPluginBPLibrary_NoRegister();
ACHIEVEMENTPLUGIN_API UEnum* Z_Construct_UEnum_AchievementPlugin_EAchievementPlatforms();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
UPackage* Z_Construct_UPackage__Script_AchievementPlugin();
// End Cross Module References

// Begin Class UAchievementPluginBPLibrary Function AchievementPlatformInitialized
struct Z_Construct_UFunction_UAchievementPluginBPLibrary_AchievementPlatformInitialized_Statics
{
	struct AchievementPluginBPLibrary_eventAchievementPlatformInitialized_Parms
	{
		TEnumAsByte<EAchievementPlatforms> platform;
		bool init;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "AchievementPlugin" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// this function should only be called when the user manually initializes the platform\n" },
#endif
		{ "CPP_Default_init", "true" },
		{ "DisplayName", "Achievement Platform Initialized" },
		{ "Keywords", "Achievement Platform Initialized" },
		{ "ModuleRelativePath", "Public/AchievementPluginBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "this function should only be called when the user manually initializes the platform" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_platform;
	static void NewProp_init_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_init;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAchievementPluginBPLibrary_AchievementPlatformInitialized_Statics::NewProp_platform = { "platform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AchievementPluginBPLibrary_eventAchievementPlatformInitialized_Parms, platform), Z_Construct_UEnum_AchievementPlugin_EAchievementPlatforms, METADATA_PARAMS(0, nullptr) }; // 2394143095
void Z_Construct_UFunction_UAchievementPluginBPLibrary_AchievementPlatformInitialized_Statics::NewProp_init_SetBit(void* Obj)
{
	((AchievementPluginBPLibrary_eventAchievementPlatformInitialized_Parms*)Obj)->init = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAchievementPluginBPLibrary_AchievementPlatformInitialized_Statics::NewProp_init = { "init", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AchievementPluginBPLibrary_eventAchievementPlatformInitialized_Parms), &Z_Construct_UFunction_UAchievementPluginBPLibrary_AchievementPlatformInitialized_Statics::NewProp_init_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAchievementPluginBPLibrary_AchievementPlatformInitialized_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAchievementPluginBPLibrary_AchievementPlatformInitialized_Statics::NewProp_platform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAchievementPluginBPLibrary_AchievementPlatformInitialized_Statics::NewProp_init,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_AchievementPlatformInitialized_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAchievementPluginBPLibrary_AchievementPlatformInitialized_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAchievementPluginBPLibrary, nullptr, "AchievementPlatformInitialized", nullptr, nullptr, Z_Construct_UFunction_UAchievementPluginBPLibrary_AchievementPlatformInitialized_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_AchievementPlatformInitialized_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAchievementPluginBPLibrary_AchievementPlatformInitialized_Statics::AchievementPluginBPLibrary_eventAchievementPlatformInitialized_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_AchievementPlatformInitialized_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAchievementPluginBPLibrary_AchievementPlatformInitialized_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UAchievementPluginBPLibrary_AchievementPlatformInitialized_Statics::AchievementPluginBPLibrary_eventAchievementPlatformInitialized_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAchievementPluginBPLibrary_AchievementPlatformInitialized()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAchievementPluginBPLibrary_AchievementPlatformInitialized_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAchievementPluginBPLibrary::execAchievementPlatformInitialized)
{
	P_GET_PROPERTY(FByteProperty,Z_Param_platform);
	P_GET_UBOOL(Z_Param_init);
	P_FINISH;
	P_NATIVE_BEGIN;
	UAchievementPluginBPLibrary::AchievementPlatformInitialized(EAchievementPlatforms(Z_Param_platform),Z_Param_init);
	P_NATIVE_END;
}
// End Class UAchievementPluginBPLibrary Function AchievementPlatformInitialized

// Begin Class UAchievementPluginBPLibrary Function DeleteAllAchievementProgress
struct Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress_Statics
{
	struct AchievementPluginBPLibrary_eventDeleteAllAchievementProgress_Parms
	{
		bool platformsToo;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "AchievementPlugin" },
		{ "CPP_Default_platformsToo", "true" },
		{ "DisplayName", "Delete All Achievement Progress" },
		{ "Keywords", "Delete Achievement Progress" },
		{ "ModuleRelativePath", "Public/AchievementPluginBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "Tooltip", "Delete's ALL achievements progress. Will empty all progress but keep the file. This cannot be undone!" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_platformsToo_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_platformsToo;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress_Statics::NewProp_platformsToo_SetBit(void* Obj)
{
	((AchievementPluginBPLibrary_eventDeleteAllAchievementProgress_Parms*)Obj)->platformsToo = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress_Statics::NewProp_platformsToo = { "platformsToo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AchievementPluginBPLibrary_eventDeleteAllAchievementProgress_Parms), &Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress_Statics::NewProp_platformsToo_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((AchievementPluginBPLibrary_eventDeleteAllAchievementProgress_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AchievementPluginBPLibrary_eventDeleteAllAchievementProgress_Parms), &Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress_Statics::NewProp_platformsToo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAchievementPluginBPLibrary, nullptr, "DeleteAllAchievementProgress", nullptr, nullptr, Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress_Statics::AchievementPluginBPLibrary_eventDeleteAllAchievementProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress_Statics::AchievementPluginBPLibrary_eventDeleteAllAchievementProgress_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAchievementPluginBPLibrary::execDeleteAllAchievementProgress)
{
	P_GET_UBOOL(Z_Param_platformsToo);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UAchievementPluginBPLibrary::DeleteAllAchievementProgress(Z_Param_platformsToo);
	P_NATIVE_END;
}
// End Class UAchievementPluginBPLibrary Function DeleteAllAchievementProgress

// Begin Class UAchievementPluginBPLibrary Function DeleteSingleAchievementProgress
struct Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics
{
	struct AchievementPluginBPLibrary_eventDeleteSingleAchievementProgress_Parms
	{
		FString achievementID;
		bool platformsToo;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "AchievementPlugin" },
		{ "CPP_Default_platformsToo", "true" },
		{ "DisplayName", "Delete Single Achievement Progress" },
		{ "Keywords", "Delete Single Achievement Progress" },
		{ "ModuleRelativePath", "Public/AchievementPluginBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "Tooltip", "Delete's given achievement's progress. This cannot be undone!" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_achievementID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_achievementID;
	static void NewProp_platformsToo_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_platformsToo;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics::NewProp_achievementID = { "achievementID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AchievementPluginBPLibrary_eventDeleteSingleAchievementProgress_Parms, achievementID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_achievementID_MetaData), NewProp_achievementID_MetaData) };
void Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics::NewProp_platformsToo_SetBit(void* Obj)
{
	((AchievementPluginBPLibrary_eventDeleteSingleAchievementProgress_Parms*)Obj)->platformsToo = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics::NewProp_platformsToo = { "platformsToo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AchievementPluginBPLibrary_eventDeleteSingleAchievementProgress_Parms), &Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics::NewProp_platformsToo_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((AchievementPluginBPLibrary_eventDeleteSingleAchievementProgress_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AchievementPluginBPLibrary_eventDeleteSingleAchievementProgress_Parms), &Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics::NewProp_achievementID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics::NewProp_platformsToo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAchievementPluginBPLibrary, nullptr, "DeleteSingleAchievementProgress", nullptr, nullptr, Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics::AchievementPluginBPLibrary_eventDeleteSingleAchievementProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics::AchievementPluginBPLibrary_eventDeleteSingleAchievementProgress_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAchievementPluginBPLibrary::execDeleteSingleAchievementProgress)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_achievementID);
	P_GET_UBOOL(Z_Param_platformsToo);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UAchievementPluginBPLibrary::DeleteSingleAchievementProgress(Z_Param_achievementID,Z_Param_platformsToo);
	P_NATIVE_END;
}
// End Class UAchievementPluginBPLibrary Function DeleteSingleAchievementProgress

// Begin Class UAchievementPluginBPLibrary Function IncreaseAchievementProgress
struct Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress_Statics
{
	struct AchievementPluginBPLibrary_eventIncreaseAchievementProgress_Parms
	{
		FString localAchievementId;
		float change;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "AchievementPlugin" },
		{ "DisplayName", "Change Achievement Progress" },
		{ "Keywords", "Change Achievement Progress" },
		{ "ModuleRelativePath", "Public/AchievementPluginBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_localAchievementId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_localAchievementId;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_change;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress_Statics::NewProp_localAchievementId = { "localAchievementId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AchievementPluginBPLibrary_eventIncreaseAchievementProgress_Parms, localAchievementId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_localAchievementId_MetaData), NewProp_localAchievementId_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress_Statics::NewProp_change = { "change", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AchievementPluginBPLibrary_eventIncreaseAchievementProgress_Parms, change), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((AchievementPluginBPLibrary_eventIncreaseAchievementProgress_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AchievementPluginBPLibrary_eventIncreaseAchievementProgress_Parms), &Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress_Statics::NewProp_localAchievementId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress_Statics::NewProp_change,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAchievementPluginBPLibrary, nullptr, "IncreaseAchievementProgress", nullptr, nullptr, Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress_Statics::AchievementPluginBPLibrary_eventIncreaseAchievementProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress_Statics::AchievementPluginBPLibrary_eventIncreaseAchievementProgress_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAchievementPluginBPLibrary::execIncreaseAchievementProgress)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_localAchievementId);
	P_GET_PROPERTY(FFloatProperty,Z_Param_change);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UAchievementPluginBPLibrary::IncreaseAchievementProgress(Z_Param_localAchievementId,Z_Param_change);
	P_NATIVE_END;
}
// End Class UAchievementPluginBPLibrary Function IncreaseAchievementProgress

// Begin Class UAchievementPluginBPLibrary Function LoadAchievementProgress
struct Z_Construct_UFunction_UAchievementPluginBPLibrary_LoadAchievementProgress_Statics
{
	struct AchievementPluginBPLibrary_eventLoadAchievementProgress_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "AchievementPlugin" },
		{ "DisplayName", "Load Achievement Progress" },
		{ "Keywords", "Load Achievement Progress" },
		{ "ModuleRelativePath", "Public/AchievementPluginBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "Tooltip", "This is already done at the start of the game, however, this will force reload it without saving, be careful!" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UAchievementPluginBPLibrary_LoadAchievementProgress_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((AchievementPluginBPLibrary_eventLoadAchievementProgress_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAchievementPluginBPLibrary_LoadAchievementProgress_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AchievementPluginBPLibrary_eventLoadAchievementProgress_Parms), &Z_Construct_UFunction_UAchievementPluginBPLibrary_LoadAchievementProgress_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAchievementPluginBPLibrary_LoadAchievementProgress_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAchievementPluginBPLibrary_LoadAchievementProgress_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_LoadAchievementProgress_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAchievementPluginBPLibrary_LoadAchievementProgress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAchievementPluginBPLibrary, nullptr, "LoadAchievementProgress", nullptr, nullptr, Z_Construct_UFunction_UAchievementPluginBPLibrary_LoadAchievementProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_LoadAchievementProgress_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAchievementPluginBPLibrary_LoadAchievementProgress_Statics::AchievementPluginBPLibrary_eventLoadAchievementProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_LoadAchievementProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAchievementPluginBPLibrary_LoadAchievementProgress_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UAchievementPluginBPLibrary_LoadAchievementProgress_Statics::AchievementPluginBPLibrary_eventLoadAchievementProgress_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAchievementPluginBPLibrary_LoadAchievementProgress()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAchievementPluginBPLibrary_LoadAchievementProgress_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAchievementPluginBPLibrary::execLoadAchievementProgress)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UAchievementPluginBPLibrary::LoadAchievementProgress();
	P_NATIVE_END;
}
// End Class UAchievementPluginBPLibrary Function LoadAchievementProgress

// Begin Class UAchievementPluginBPLibrary Function RemoveAchievementWidget
struct Z_Construct_UFunction_UAchievementPluginBPLibrary_RemoveAchievementWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "AchievementPlugin" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// this function is required for the Widget to function properly\n" },
#endif
		{ "DisplayName", "Remove Achievement Widget" },
		{ "Keywords", "Achievement Widget Remove" },
		{ "ModuleRelativePath", "Public/AchievementPluginBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "this function is required for the Widget to function properly" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAchievementPluginBPLibrary_RemoveAchievementWidget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAchievementPluginBPLibrary, nullptr, "RemoveAchievementWidget", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_RemoveAchievementWidget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAchievementPluginBPLibrary_RemoveAchievementWidget_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UAchievementPluginBPLibrary_RemoveAchievementWidget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAchievementPluginBPLibrary_RemoveAchievementWidget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAchievementPluginBPLibrary::execRemoveAchievementWidget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	UAchievementPluginBPLibrary::RemoveAchievementWidget();
	P_NATIVE_END;
}
// End Class UAchievementPluginBPLibrary Function RemoveAchievementWidget

// Begin Class UAchievementPluginBPLibrary Function SaveAchievementProgress
struct Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgress_Statics
{
	struct AchievementPluginBPLibrary_eventSaveAchievementProgress_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "AchievementPlugin" },
		{ "DisplayName", "Save Achievement Progress" },
		{ "Keywords", "Save Achievement Progress" },
		{ "ModuleRelativePath", "Public/AchievementPluginBPLibrary.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgress_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((AchievementPluginBPLibrary_eventSaveAchievementProgress_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgress_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AchievementPluginBPLibrary_eventSaveAchievementProgress_Parms), &Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgress_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgress_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgress_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgress_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAchievementPluginBPLibrary, nullptr, "SaveAchievementProgress", nullptr, nullptr, Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgress_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgress_Statics::AchievementPluginBPLibrary_eventSaveAchievementProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgress_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgress_Statics::AchievementPluginBPLibrary_eventSaveAchievementProgress_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgress()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgress_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAchievementPluginBPLibrary::execSaveAchievementProgress)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UAchievementPluginBPLibrary::SaveAchievementProgress();
	P_NATIVE_END;
}
// End Class UAchievementPluginBPLibrary Function SaveAchievementProgress

// Begin Class UAchievementPluginBPLibrary Function SaveAchievementProgressAsync
struct Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgressAsync_Statics
{
	struct AchievementPluginBPLibrary_eventSaveAchievementProgressAsync_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "AchievementPlugin" },
		{ "DisplayName", "Save Achievement Progress Async" },
		{ "Keywords", "Save Achievement Progress Async" },
		{ "ModuleRelativePath", "Public/AchievementPluginBPLibrary.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgressAsync_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((AchievementPluginBPLibrary_eventSaveAchievementProgressAsync_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgressAsync_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AchievementPluginBPLibrary_eventSaveAchievementProgressAsync_Parms), &Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgressAsync_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgressAsync_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgressAsync_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgressAsync_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgressAsync_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAchievementPluginBPLibrary, nullptr, "SaveAchievementProgressAsync", nullptr, nullptr, Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgressAsync_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgressAsync_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgressAsync_Statics::AchievementPluginBPLibrary_eventSaveAchievementProgressAsync_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgressAsync_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgressAsync_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgressAsync_Statics::AchievementPluginBPLibrary_eventSaveAchievementProgressAsync_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgressAsync()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgressAsync_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAchievementPluginBPLibrary::execSaveAchievementProgressAsync)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UAchievementPluginBPLibrary::SaveAchievementProgressAsync();
	P_NATIVE_END;
}
// End Class UAchievementPluginBPLibrary Function SaveAchievementProgressAsync

// Begin Class UAchievementPluginBPLibrary Function SetActiveSaveSlotIndex
struct Z_Construct_UFunction_UAchievementPluginBPLibrary_SetActiveSaveSlotIndex_Statics
{
	struct AchievementPluginBPLibrary_eventSetActiveSaveSlotIndex_Parms
	{
		int32 newIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "AchievementPlugin" },
		{ "DisplayName", "Set Save Slot Index" },
		{ "Keywords", "Save Slot Index" },
		{ "ModuleRelativePath", "Public/AchievementPluginBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_newIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAchievementPluginBPLibrary_SetActiveSaveSlotIndex_Statics::NewProp_newIndex = { "newIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AchievementPluginBPLibrary_eventSetActiveSaveSlotIndex_Parms, newIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAchievementPluginBPLibrary_SetActiveSaveSlotIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAchievementPluginBPLibrary_SetActiveSaveSlotIndex_Statics::NewProp_newIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_SetActiveSaveSlotIndex_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAchievementPluginBPLibrary_SetActiveSaveSlotIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAchievementPluginBPLibrary, nullptr, "SetActiveSaveSlotIndex", nullptr, nullptr, Z_Construct_UFunction_UAchievementPluginBPLibrary_SetActiveSaveSlotIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_SetActiveSaveSlotIndex_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAchievementPluginBPLibrary_SetActiveSaveSlotIndex_Statics::AchievementPluginBPLibrary_eventSetActiveSaveSlotIndex_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAchievementPluginBPLibrary_SetActiveSaveSlotIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAchievementPluginBPLibrary_SetActiveSaveSlotIndex_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UAchievementPluginBPLibrary_SetActiveSaveSlotIndex_Statics::AchievementPluginBPLibrary_eventSetActiveSaveSlotIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAchievementPluginBPLibrary_SetActiveSaveSlotIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAchievementPluginBPLibrary_SetActiveSaveSlotIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAchievementPluginBPLibrary::execSetActiveSaveSlotIndex)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_newIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	UAchievementPluginBPLibrary::SetActiveSaveSlotIndex(Z_Param_newIndex);
	P_NATIVE_END;
}
// End Class UAchievementPluginBPLibrary Function SetActiveSaveSlotIndex

// Begin Class UAchievementPluginBPLibrary
void UAchievementPluginBPLibrary::StaticRegisterNativesUAchievementPluginBPLibrary()
{
	UClass* Class = UAchievementPluginBPLibrary::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AchievementPlatformInitialized", &UAchievementPluginBPLibrary::execAchievementPlatformInitialized },
		{ "DeleteAllAchievementProgress", &UAchievementPluginBPLibrary::execDeleteAllAchievementProgress },
		{ "DeleteSingleAchievementProgress", &UAchievementPluginBPLibrary::execDeleteSingleAchievementProgress },
		{ "IncreaseAchievementProgress", &UAchievementPluginBPLibrary::execIncreaseAchievementProgress },
		{ "LoadAchievementProgress", &UAchievementPluginBPLibrary::execLoadAchievementProgress },
		{ "RemoveAchievementWidget", &UAchievementPluginBPLibrary::execRemoveAchievementWidget },
		{ "SaveAchievementProgress", &UAchievementPluginBPLibrary::execSaveAchievementProgress },
		{ "SaveAchievementProgressAsync", &UAchievementPluginBPLibrary::execSaveAchievementProgressAsync },
		{ "SetActiveSaveSlotIndex", &UAchievementPluginBPLibrary::execSetActiveSaveSlotIndex },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAchievementPluginBPLibrary);
UClass* Z_Construct_UClass_UAchievementPluginBPLibrary_NoRegister()
{
	return UAchievementPluginBPLibrary::StaticClass();
}
struct Z_Construct_UClass_UAchievementPluginBPLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AchievementPluginBPLibrary.h" },
		{ "ModuleRelativePath", "Public/AchievementPluginBPLibrary.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAchievementPluginBPLibrary_AchievementPlatformInitialized, "AchievementPlatformInitialized" }, // 2779153875
		{ &Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteAllAchievementProgress, "DeleteAllAchievementProgress" }, // 3427535909
		{ &Z_Construct_UFunction_UAchievementPluginBPLibrary_DeleteSingleAchievementProgress, "DeleteSingleAchievementProgress" }, // 1122460843
		{ &Z_Construct_UFunction_UAchievementPluginBPLibrary_IncreaseAchievementProgress, "IncreaseAchievementProgress" }, // 3925018624
		{ &Z_Construct_UFunction_UAchievementPluginBPLibrary_LoadAchievementProgress, "LoadAchievementProgress" }, // 634770895
		{ &Z_Construct_UFunction_UAchievementPluginBPLibrary_RemoveAchievementWidget, "RemoveAchievementWidget" }, // 2648330779
		{ &Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgress, "SaveAchievementProgress" }, // 3122922263
		{ &Z_Construct_UFunction_UAchievementPluginBPLibrary_SaveAchievementProgressAsync, "SaveAchievementProgressAsync" }, // 3904647079
		{ &Z_Construct_UFunction_UAchievementPluginBPLibrary_SetActiveSaveSlotIndex, "SetActiveSaveSlotIndex" }, // 2686315532
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAchievementPluginBPLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UAchievementPluginBPLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_AchievementPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementPluginBPLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAchievementPluginBPLibrary_Statics::ClassParams = {
	&UAchievementPluginBPLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAchievementPluginBPLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UAchievementPluginBPLibrary_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAchievementPluginBPLibrary()
{
	if (!Z_Registration_Info_UClass_UAchievementPluginBPLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAchievementPluginBPLibrary.OuterSingleton, Z_Construct_UClass_UAchievementPluginBPLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAchievementPluginBPLibrary.OuterSingleton;
}
template<> ACHIEVEMENTPLUGIN_API UClass* StaticClass<UAchievementPluginBPLibrary>()
{
	return UAchievementPluginBPLibrary::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAchievementPluginBPLibrary);
UAchievementPluginBPLibrary::~UAchievementPluginBPLibrary() {}
// End Class UAchievementPluginBPLibrary

// Begin Registration
struct Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPluginBPLibrary_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAchievementPluginBPLibrary, UAchievementPluginBPLibrary::StaticClass, TEXT("UAchievementPluginBPLibrary"), &Z_Registration_Info_UClass_UAchievementPluginBPLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAchievementPluginBPLibrary), 3045379885U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPluginBPLibrary_h_3977326059(TEXT("/Script/AchievementPlugin"),
	Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPluginBPLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPluginBPLibrary_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
