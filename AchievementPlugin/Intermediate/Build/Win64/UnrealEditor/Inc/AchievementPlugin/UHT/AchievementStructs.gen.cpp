// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AchievementPlugin/Public/AchievementStructs.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAchievementStructs() {}

// Begin Cross Module References
ACHIEVEMENTPLUGIN_API UEnum* Z_Construct_UEnum_AchievementPlugin_EAchievementUploadTypes();
ACHIEVEMENTPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAchievementData();
ACHIEVEMENTPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAchievementPlatformData();
ACHIEVEMENTPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAchievementProgress();
ACHIEVEMENTPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAchievementWidgetSettings();
ACHIEVEMENTPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FEpicGamesInfo();
ACHIEVEMENTPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FLinkedStruct();
ACHIEVEMENTPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FSaveSlotSettings();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_AchievementPlugin();
// End Cross Module References

// Begin ScriptStruct FLinkedStruct
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_LinkedStruct;
class UScriptStruct* FLinkedStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_LinkedStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_LinkedStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FLinkedStruct, (UObject*)Z_Construct_UPackage__Script_AchievementPlugin(), TEXT("LinkedStruct"));
	}
	return Z_Registration_Info_UScriptStruct_LinkedStruct.OuterSingleton;
}
template<> ACHIEVEMENTPLUGIN_API UScriptStruct* StaticStruct<FLinkedStruct>()
{
	return FLinkedStruct::StaticStruct();
}
struct Z_Construct_UScriptStruct_FLinkedStruct_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// this will allow the achievement structs to be \"linked\", only inherited by the data version\n" },
#endif
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "this will allow the achievement structs to be \"linked\", only inherited by the data version" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_linkID_MetaData[] = {
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_m_linkID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLinkedStruct>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FLinkedStruct_Statics::NewProp_m_linkID = { "m_linkID", nullptr, (EPropertyFlags)0x0040000000004000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLinkedStruct, m_linkID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_linkID_MetaData), NewProp_m_linkID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FLinkedStruct_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLinkedStruct_Statics::NewProp_m_linkID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLinkedStruct_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLinkedStruct_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_AchievementPlugin,
	nullptr,
	&NewStructOps,
	"LinkedStruct",
	Z_Construct_UScriptStruct_FLinkedStruct_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLinkedStruct_Statics::PropPointers),
	sizeof(FLinkedStruct),
	alignof(FLinkedStruct),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLinkedStruct_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FLinkedStruct_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FLinkedStruct()
{
	if (!Z_Registration_Info_UScriptStruct_LinkedStruct.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_LinkedStruct.InnerSingleton, Z_Construct_UScriptStruct_FLinkedStruct_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_LinkedStruct.InnerSingleton;
}
// End ScriptStruct FLinkedStruct

// Begin ScriptStruct FAchievementProgress
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AchievementProgress;
class UScriptStruct* FAchievementProgress::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AchievementProgress.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AchievementProgress.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAchievementProgress, (UObject*)Z_Construct_UPackage__Script_AchievementPlugin(), TEXT("AchievementProgress"));
	}
	return Z_Registration_Info_UScriptStruct_AchievementProgress.OuterSingleton;
}
template<> ACHIEVEMENTPLUGIN_API UScriptStruct* StaticStruct<FAchievementProgress>()
{
	return FAchievementProgress::StaticStruct();
}
struct Z_Construct_UScriptStruct_FAchievementProgress_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// this struct has all the data that can be changed during runtime, ReadWrite for blueprints\n" },
#endif
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "this struct has all the data that can be changed during runtime, ReadWrite for blueprints" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_progress_MetaData[] = {
		{ "Category", "Achievement Progress" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsAchievementUnlocked_MetaData[] = {
		{ "Category", "Achievement Progress" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_unlockedTime_MetaData[] = {
		{ "Category", "Achievement Progress" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_progress;
	static void NewProp_bIsAchievementUnlocked_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsAchievementUnlocked;
	static const UECodeGen_Private::FStrPropertyParams NewProp_unlockedTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAchievementProgress>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAchievementProgress_Statics::NewProp_progress = { "progress", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAchievementProgress, progress), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_progress_MetaData), NewProp_progress_MetaData) };
void Z_Construct_UScriptStruct_FAchievementProgress_Statics::NewProp_bIsAchievementUnlocked_SetBit(void* Obj)
{
	((FAchievementProgress*)Obj)->bIsAchievementUnlocked = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAchievementProgress_Statics::NewProp_bIsAchievementUnlocked = { "bIsAchievementUnlocked", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAchievementProgress), &Z_Construct_UScriptStruct_FAchievementProgress_Statics::NewProp_bIsAchievementUnlocked_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsAchievementUnlocked_MetaData), NewProp_bIsAchievementUnlocked_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAchievementProgress_Statics::NewProp_unlockedTime = { "unlockedTime", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAchievementProgress, unlockedTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_unlockedTime_MetaData), NewProp_unlockedTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAchievementProgress_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementProgress_Statics::NewProp_progress,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementProgress_Statics::NewProp_bIsAchievementUnlocked,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementProgress_Statics::NewProp_unlockedTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAchievementProgress_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAchievementProgress_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_AchievementPlugin,
	nullptr,
	&NewStructOps,
	"AchievementProgress",
	Z_Construct_UScriptStruct_FAchievementProgress_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAchievementProgress_Statics::PropPointers),
	sizeof(FAchievementProgress),
	alignof(FAchievementProgress),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAchievementProgress_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAchievementProgress_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAchievementProgress()
{
	if (!Z_Registration_Info_UScriptStruct_AchievementProgress.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AchievementProgress.InnerSingleton, Z_Construct_UScriptStruct_FAchievementProgress_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_AchievementProgress.InnerSingleton;
}
// End ScriptStruct FAchievementProgress

// Begin ScriptStruct FAchievementPlatformData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AchievementPlatformData;
class UScriptStruct* FAchievementPlatformData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AchievementPlatformData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AchievementPlatformData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAchievementPlatformData, (UObject*)Z_Construct_UPackage__Script_AchievementPlugin(), TEXT("AchievementPlatformData"));
	}
	return Z_Registration_Info_UScriptStruct_AchievementPlatformData.OuterSingleton;
}
template<> ACHIEVEMENTPLUGIN_API UScriptStruct* StaticStruct<FAchievementPlatformData>()
{
	return FAchievementPlatformData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FAchievementPlatformData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_uploadType_MetaData[] = {
		{ "Category", "Platforms" },
		{ "DisplayName", "Platform Upload Type" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_steamAchievementID_MetaData[] = {
		{ "Category", "Steam" },
		{ "DisplayName", "Steam Achievement ID" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_steamStatID_MetaData[] = {
		{ "Category", "Steam" },
		{ "DisplayName", "Steam Stat ID" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "Tooltip", "For progressive achievements (using Stats), please enter the Stat name used for tracking progress!" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_epicAchievementID_MetaData[] = {
		{ "Category", "Epic" },
		{ "DisplayName", "Epic Achievement ID" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_epicStatID_MetaData[] = {
		{ "Category", "Epic" },
		{ "DisplayName", "Epic Stat ID" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "Tooltip", "For progressive achievements (using Stats), please enter the Stat name used for tracking progress!" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_uploadType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_steamAchievementID;
	static const UECodeGen_Private::FStrPropertyParams NewProp_steamStatID;
	static const UECodeGen_Private::FStrPropertyParams NewProp_epicAchievementID;
	static const UECodeGen_Private::FStrPropertyParams NewProp_epicStatID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAchievementPlatformData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAchievementPlatformData_Statics::NewProp_uploadType = { "uploadType", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAchievementPlatformData, uploadType), Z_Construct_UEnum_AchievementPlugin_EAchievementUploadTypes, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_uploadType_MetaData), NewProp_uploadType_MetaData) }; // 921294432
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAchievementPlatformData_Statics::NewProp_steamAchievementID = { "steamAchievementID", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAchievementPlatformData, steamAchievementID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_steamAchievementID_MetaData), NewProp_steamAchievementID_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAchievementPlatformData_Statics::NewProp_steamStatID = { "steamStatID", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAchievementPlatformData, steamStatID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_steamStatID_MetaData), NewProp_steamStatID_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAchievementPlatformData_Statics::NewProp_epicAchievementID = { "epicAchievementID", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAchievementPlatformData, epicAchievementID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_epicAchievementID_MetaData), NewProp_epicAchievementID_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAchievementPlatformData_Statics::NewProp_epicStatID = { "epicStatID", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAchievementPlatformData, epicStatID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_epicStatID_MetaData), NewProp_epicStatID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAchievementPlatformData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementPlatformData_Statics::NewProp_uploadType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementPlatformData_Statics::NewProp_steamAchievementID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementPlatformData_Statics::NewProp_steamStatID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementPlatformData_Statics::NewProp_epicAchievementID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementPlatformData_Statics::NewProp_epicStatID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAchievementPlatformData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAchievementPlatformData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_AchievementPlugin,
	nullptr,
	&NewStructOps,
	"AchievementPlatformData",
	Z_Construct_UScriptStruct_FAchievementPlatformData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAchievementPlatformData_Statics::PropPointers),
	sizeof(FAchievementPlatformData),
	alignof(FAchievementPlatformData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAchievementPlatformData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAchievementPlatformData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAchievementPlatformData()
{
	if (!Z_Registration_Info_UScriptStruct_AchievementPlatformData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AchievementPlatformData.InnerSingleton, Z_Construct_UScriptStruct_FAchievementPlatformData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_AchievementPlatformData.InnerSingleton;
}
// End ScriptStruct FAchievementPlatformData

// Begin ScriptStruct FAchievementData
static_assert(std::is_polymorphic<FAchievementData>() == std::is_polymorphic<FLinkedStruct>(), "USTRUCT FAchievementData cannot be polymorphic unless super FLinkedStruct is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AchievementData;
class UScriptStruct* FAchievementData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AchievementData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AchievementData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAchievementData, (UObject*)Z_Construct_UPackage__Script_AchievementPlugin(), TEXT("AchievementData"));
	}
	return Z_Registration_Info_UScriptStruct_AchievementData.OuterSingleton;
}
template<> ACHIEVEMENTPLUGIN_API UScriptStruct* StaticStruct<FAchievementData>()
{
	return FAchievementData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FAchievementData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// this struct has all the data that is inside the developer settings, ReadOnly for blueprints\n" },
#endif
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "this struct has all the data that is inside the developer settings, ReadOnly for blueprints" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_isHidden_MetaData[] = {
		{ "Category", "Developer" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_displayName_MetaData[] = {
		{ "Category", "Public" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_description_MetaData[] = {
		{ "Category", "Public" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_lockedTexture_MetaData[] = {
		{ "Category", "Public" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_unlockedTexture_MetaData[] = {
		{ "Category", "Public" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_progressGoal_MetaData[] = {
		{ "Category", "Public" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_platformData_MetaData[] = {
		{ "Category", "Platforms" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Platform-specific identifiers\n" },
#endif
		{ "DisplayName", "Platform Data" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Platform-specific identifiers" },
#endif
	};
#if WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_currentProgress_MetaData[] = {
		{ "Category", "Runtime Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Runtime data (visible only here but not editable, NOT saved to config)\n" },
#endif
		{ "DisplayName", "Current Progress (NOT LIVE)" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runtime data (visible only here but not editable, NOT saved to config)" },
#endif
	};
#endif // WITH_EDITORONLY_DATA
#endif // WITH_METADATA
	static void NewProp_isHidden_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_isHidden;
	static const UECodeGen_Private::FTextPropertyParams NewProp_displayName;
	static const UECodeGen_Private::FTextPropertyParams NewProp_description;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_lockedTexture;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_unlockedTexture;
	static const UECodeGen_Private::FIntPropertyParams NewProp_progressGoal;
	static const UECodeGen_Private::FStructPropertyParams NewProp_platformData;
#if WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_m_currentProgress;
#endif // WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAchievementData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FAchievementData_Statics::NewProp_isHidden_SetBit(void* Obj)
{
	((FAchievementData*)Obj)->isHidden = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAchievementData_Statics::NewProp_isHidden = { "isHidden", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAchievementData), &Z_Construct_UScriptStruct_FAchievementData_Statics::NewProp_isHidden_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_isHidden_MetaData), NewProp_isHidden_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FAchievementData_Statics::NewProp_displayName = { "displayName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAchievementData, displayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_displayName_MetaData), NewProp_displayName_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FAchievementData_Statics::NewProp_description = { "description", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAchievementData, description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_description_MetaData), NewProp_description_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FAchievementData_Statics::NewProp_lockedTexture = { "lockedTexture", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAchievementData, lockedTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_lockedTexture_MetaData), NewProp_lockedTexture_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FAchievementData_Statics::NewProp_unlockedTexture = { "unlockedTexture", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAchievementData, unlockedTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_unlockedTexture_MetaData), NewProp_unlockedTexture_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAchievementData_Statics::NewProp_progressGoal = { "progressGoal", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAchievementData, progressGoal), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_progressGoal_MetaData), NewProp_progressGoal_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAchievementData_Statics::NewProp_platformData = { "platformData", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAchievementData, platformData), Z_Construct_UScriptStruct_FAchievementPlatformData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_platformData_MetaData), NewProp_platformData_MetaData) }; // 3300766894
#if WITH_EDITORONLY_DATA
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAchievementData_Statics::NewProp_m_currentProgress = { "m_currentProgress", nullptr, (EPropertyFlags)0x0040000800022001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAchievementData, m_currentProgress), Z_Construct_UScriptStruct_FAchievementProgress, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_currentProgress_MetaData), NewProp_m_currentProgress_MetaData) }; // 2518374241
#endif // WITH_EDITORONLY_DATA
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAchievementData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementData_Statics::NewProp_isHidden,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementData_Statics::NewProp_displayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementData_Statics::NewProp_description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementData_Statics::NewProp_lockedTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementData_Statics::NewProp_unlockedTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementData_Statics::NewProp_progressGoal,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementData_Statics::NewProp_platformData,
#if WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementData_Statics::NewProp_m_currentProgress,
#endif // WITH_EDITORONLY_DATA
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAchievementData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAchievementData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_AchievementPlugin,
	Z_Construct_UScriptStruct_FLinkedStruct,
	&NewStructOps,
	"AchievementData",
	Z_Construct_UScriptStruct_FAchievementData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAchievementData_Statics::PropPointers),
	sizeof(FAchievementData),
	alignof(FAchievementData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAchievementData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAchievementData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAchievementData()
{
	if (!Z_Registration_Info_UScriptStruct_AchievementData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AchievementData.InnerSingleton, Z_Construct_UScriptStruct_FAchievementData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_AchievementData.InnerSingleton;
}
// End ScriptStruct FAchievementData

// Begin ScriptStruct FSaveSlotSettings
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SaveSlotSettings;
class UScriptStruct* FSaveSlotSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SaveSlotSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SaveSlotSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSaveSlotSettings, (UObject*)Z_Construct_UPackage__Script_AchievementPlugin(), TEXT("SaveSlotSettings"));
	}
	return Z_Registration_Info_UScriptStruct_SaveSlotSettings.OuterSingleton;
}
template<> ACHIEVEMENTPLUGIN_API UScriptStruct* StaticStruct<FSaveSlotSettings>()
{
	return FSaveSlotSettings::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSaveSlotSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_slotName_MetaData[] = {
		{ "Category", "Achievements" },
		{ "DisplayName", "Profile Name" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_slotIndex_MetaData[] = {
		{ "Category", "Achievements" },
		{ "DisplayName", "Save Slot" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_slotName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_slotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSaveSlotSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSaveSlotSettings_Statics::NewProp_slotName = { "slotName", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSaveSlotSettings, slotName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_slotName_MetaData), NewProp_slotName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSaveSlotSettings_Statics::NewProp_slotIndex = { "slotIndex", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSaveSlotSettings, slotIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_slotIndex_MetaData), NewProp_slotIndex_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSaveSlotSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSaveSlotSettings_Statics::NewProp_slotName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSaveSlotSettings_Statics::NewProp_slotIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSaveSlotSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSaveSlotSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_AchievementPlugin,
	nullptr,
	&NewStructOps,
	"SaveSlotSettings",
	Z_Construct_UScriptStruct_FSaveSlotSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSaveSlotSettings_Statics::PropPointers),
	sizeof(FSaveSlotSettings),
	alignof(FSaveSlotSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSaveSlotSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSaveSlotSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSaveSlotSettings()
{
	if (!Z_Registration_Info_UScriptStruct_SaveSlotSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SaveSlotSettings.InnerSingleton, Z_Construct_UScriptStruct_FSaveSlotSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SaveSlotSettings.InnerSingleton;
}
// End ScriptStruct FSaveSlotSettings

// Begin ScriptStruct FEpicGamesInfo
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_EpicGamesInfo;
class UScriptStruct* FEpicGamesInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_EpicGamesInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_EpicGamesInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FEpicGamesInfo, (UObject*)Z_Construct_UPackage__Script_AchievementPlugin(), TEXT("EpicGamesInfo"));
	}
	return Z_Registration_Info_UScriptStruct_EpicGamesInfo.OuterSingleton;
}
template<> ACHIEVEMENTPLUGIN_API UScriptStruct* StaticStruct<FEpicGamesInfo>()
{
	return FEpicGamesInfo::StaticStruct();
}
struct Z_Construct_UScriptStruct_FEpicGamesInfo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// the information needed to initialize EOS SDK\n" },
#endif
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "the information needed to initialize EOS SDK" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProductId_MetaData[] = {
		{ "Category", "Platforms" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The product id for the running application, found on the dev portal */" },
#endif
		{ "DisplayName", "Product ID" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The product id for the running application, found on the dev portal" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ApplicationId_MetaData[] = {
		{ "Category", "Platforms" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The application id for the running application, found on the dev portal */" },
#endif
		{ "DisplayName", "Application ID" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The application id for the running application, found on the dev portal" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SandboxId_MetaData[] = {
		{ "Category", "Platforms" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The sandbox id for the running application, found on the dev portal */" },
#endif
		{ "DisplayName", "Sandbox ID" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The sandbox id for the running application, found on the dev portal" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeploymentId_MetaData[] = {
		{ "Category", "Platforms" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The deployment id for the running application, found on the dev portal */" },
#endif
		{ "DisplayName", "Deployment ID" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The deployment id for the running application, found on the dev portal" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClientCredentialsId_MetaData[] = {
		{ "Category", "Platforms" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Client id of the service permissions entry, found on the dev portal */" },
#endif
		{ "DisplayName", "Client Credentials ID" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Client id of the service permissions entry, found on the dev portal" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClientCredentialsSecret_MetaData[] = {
		{ "Category", "Platforms" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Client secret for accessing the set of permissions, found on the dev portal */// Never explicitly share the client secret, especially when the client is used in a trusted server environment!!!!!\n" },
#endif
		{ "DisplayName", "Client Secret Credentials ID" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Client secret for accessing the set of permissions, found on the dev portal // Never explicitly share the client secret, especially when the client is used in a trusted server environment!!!!!" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameName_MetaData[] = {
		{ "Category", "Platforms" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Game name */" },
#endif
		{ "DisplayName", "Game Name" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Game name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EncryptionKey_MetaData[] = {
		{ "Category", "Platforms" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Encryption key */" },
#endif
		{ "DisplayName", "Encryption Key (Optional)" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Encryption key" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ProductId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ApplicationId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SandboxId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DeploymentId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ClientCredentialsId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ClientCredentialsSecret;
	static const UECodeGen_Private::FStrPropertyParams NewProp_GameName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_EncryptionKey;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEpicGamesInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::NewProp_ProductId = { "ProductId", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEpicGamesInfo, ProductId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProductId_MetaData), NewProp_ProductId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::NewProp_ApplicationId = { "ApplicationId", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEpicGamesInfo, ApplicationId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ApplicationId_MetaData), NewProp_ApplicationId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::NewProp_SandboxId = { "SandboxId", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEpicGamesInfo, SandboxId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SandboxId_MetaData), NewProp_SandboxId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::NewProp_DeploymentId = { "DeploymentId", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEpicGamesInfo, DeploymentId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeploymentId_MetaData), NewProp_DeploymentId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::NewProp_ClientCredentialsId = { "ClientCredentialsId", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEpicGamesInfo, ClientCredentialsId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClientCredentialsId_MetaData), NewProp_ClientCredentialsId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::NewProp_ClientCredentialsSecret = { "ClientCredentialsSecret", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEpicGamesInfo, ClientCredentialsSecret), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClientCredentialsSecret_MetaData), NewProp_ClientCredentialsSecret_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::NewProp_GameName = { "GameName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEpicGamesInfo, GameName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameName_MetaData), NewProp_GameName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::NewProp_EncryptionKey = { "EncryptionKey", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEpicGamesInfo, EncryptionKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EncryptionKey_MetaData), NewProp_EncryptionKey_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::NewProp_ProductId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::NewProp_ApplicationId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::NewProp_SandboxId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::NewProp_DeploymentId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::NewProp_ClientCredentialsId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::NewProp_ClientCredentialsSecret,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::NewProp_GameName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::NewProp_EncryptionKey,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_AchievementPlugin,
	nullptr,
	&NewStructOps,
	"EpicGamesInfo",
	Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::PropPointers),
	sizeof(FEpicGamesInfo),
	alignof(FEpicGamesInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FEpicGamesInfo()
{
	if (!Z_Registration_Info_UScriptStruct_EpicGamesInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_EpicGamesInfo.InnerSingleton, Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_EpicGamesInfo.InnerSingleton;
}
// End ScriptStruct FEpicGamesInfo

// Begin ScriptStruct FAchievementWidgetSettings
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AchievementWidgetSettings;
class UScriptStruct* FAchievementWidgetSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AchievementWidgetSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AchievementWidgetSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAchievementWidgetSettings, (UObject*)Z_Construct_UPackage__Script_AchievementPlugin(), TEXT("AchievementWidgetSettings"));
	}
	return Z_Registration_Info_UScriptStruct_AchievementWidgetSettings.OuterSingleton;
}
template<> ACHIEVEMENTPLUGIN_API UScriptStruct* StaticStruct<FAchievementWidgetSettings>()
{
	return FAchievementWidgetSettings::StaticStruct();
}
struct Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_usePopups_MetaData[] = {
		{ "Category", "Achievement UI Settings" },
		{ "DisplayName", "Use Popups" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If enabled, will use the built-in popups system for when achievements are unlocked" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_achievementWidget_MetaData[] = {
		{ "Category", "Achievement UI Settings" },
		{ "DisplayName", "Achievement User Widget" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The achievement widget to use for popups. If using a custom one, make sure to check the user guide to make sure it will work!" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_maxToShow_MetaData[] = {
		{ "Category", "Achievement UI Settings" },
		{ "DisplayName", "Max popups to show at once" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_distanceBetweenPopups_MetaData[] = {
		{ "Category", "Achievement UI Settings" },
		{ "DisplayName", "Distance Between Popups" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The distance in the y axis between multiple popups" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_delayBetweenSameProgressAchievementPopup_MetaData[] = {
		{ "Category", "Achievement UI Settings" },
		{ "DisplayName", "Progress Achievements Delay" },
		{ "ModuleRelativePath", "Public/AchievementStructs.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How long before the same progress achievement popup can be shown again" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_usePopups_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_usePopups;
	static const UECodeGen_Private::FClassPropertyParams NewProp_achievementWidget;
	static const UECodeGen_Private::FIntPropertyParams NewProp_maxToShow;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_distanceBetweenPopups;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_delayBetweenSameProgressAchievementPopup;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAchievementWidgetSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::NewProp_usePopups_SetBit(void* Obj)
{
	((FAchievementWidgetSettings*)Obj)->usePopups = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::NewProp_usePopups = { "usePopups", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAchievementWidgetSettings), &Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::NewProp_usePopups_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_usePopups_MetaData), NewProp_usePopups_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::NewProp_achievementWidget = { "achievementWidget", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAchievementWidgetSettings, achievementWidget), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_achievementWidget_MetaData), NewProp_achievementWidget_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::NewProp_maxToShow = { "maxToShow", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAchievementWidgetSettings, maxToShow), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_maxToShow_MetaData), NewProp_maxToShow_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::NewProp_distanceBetweenPopups = { "distanceBetweenPopups", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAchievementWidgetSettings, distanceBetweenPopups), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_distanceBetweenPopups_MetaData), NewProp_distanceBetweenPopups_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::NewProp_delayBetweenSameProgressAchievementPopup = { "delayBetweenSameProgressAchievementPopup", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAchievementWidgetSettings, delayBetweenSameProgressAchievementPopup), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_delayBetweenSameProgressAchievementPopup_MetaData), NewProp_delayBetweenSameProgressAchievementPopup_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::NewProp_usePopups,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::NewProp_achievementWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::NewProp_maxToShow,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::NewProp_distanceBetweenPopups,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::NewProp_delayBetweenSameProgressAchievementPopup,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_AchievementPlugin,
	nullptr,
	&NewStructOps,
	"AchievementWidgetSettings",
	Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::PropPointers),
	sizeof(FAchievementWidgetSettings),
	alignof(FAchievementWidgetSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAchievementWidgetSettings()
{
	if (!Z_Registration_Info_UScriptStruct_AchievementWidgetSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AchievementWidgetSettings.InnerSingleton, Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_AchievementWidgetSettings.InnerSingleton;
}
// End ScriptStruct FAchievementWidgetSettings

// Begin Registration
struct Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementStructs_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FLinkedStruct::StaticStruct, Z_Construct_UScriptStruct_FLinkedStruct_Statics::NewStructOps, TEXT("LinkedStruct"), &Z_Registration_Info_UScriptStruct_LinkedStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FLinkedStruct), 2861519513U) },
		{ FAchievementProgress::StaticStruct, Z_Construct_UScriptStruct_FAchievementProgress_Statics::NewStructOps, TEXT("AchievementProgress"), &Z_Registration_Info_UScriptStruct_AchievementProgress, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAchievementProgress), 2518374241U) },
		{ FAchievementPlatformData::StaticStruct, Z_Construct_UScriptStruct_FAchievementPlatformData_Statics::NewStructOps, TEXT("AchievementPlatformData"), &Z_Registration_Info_UScriptStruct_AchievementPlatformData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAchievementPlatformData), 3300766894U) },
		{ FAchievementData::StaticStruct, Z_Construct_UScriptStruct_FAchievementData_Statics::NewStructOps, TEXT("AchievementData"), &Z_Registration_Info_UScriptStruct_AchievementData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAchievementData), 3517175688U) },
		{ FSaveSlotSettings::StaticStruct, Z_Construct_UScriptStruct_FSaveSlotSettings_Statics::NewStructOps, TEXT("SaveSlotSettings"), &Z_Registration_Info_UScriptStruct_SaveSlotSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSaveSlotSettings), 4192245414U) },
		{ FEpicGamesInfo::StaticStruct, Z_Construct_UScriptStruct_FEpicGamesInfo_Statics::NewStructOps, TEXT("EpicGamesInfo"), &Z_Registration_Info_UScriptStruct_EpicGamesInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEpicGamesInfo), 1048789805U) },
		{ FAchievementWidgetSettings::StaticStruct, Z_Construct_UScriptStruct_FAchievementWidgetSettings_Statics::NewStructOps, TEXT("AchievementWidgetSettings"), &Z_Registration_Info_UScriptStruct_AchievementWidgetSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAchievementWidgetSettings), 807818618U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementStructs_h_3664371678(TEXT("/Script/AchievementPlugin"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementStructs_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementStructs_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
