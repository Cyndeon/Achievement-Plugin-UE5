// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AchievementPluginBPLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ACHIEVEMENTPLUGIN_AchievementPluginBPLibrary_generated_h
#error "AchievementPluginBPLibrary.generated.h already included, missing '#pragma once' in AchievementPluginBPLibrary.h"
#endif
#define ACHIEVEMENTPLUGIN_AchievementPluginBPLibrary_generated_h

#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPluginBPLibrary_h_13_RPC_WRAPPERS \
	DECLARE_FUNCTION(execRemoveAchievementWidget); \
	DECLARE_FUNCTION(execAchievementPlatformInitialized); \
	DECLARE_FUNCTION(execSetActiveSaveSlotIndex); \
	DECLARE_FUNCTION(execDeleteAllAchievementProgress); \
	DECLARE_FUNCTION(execDeleteSingleAchievementProgress); \
	DECLARE_FUNCTION(execLoadAchievementProgress); \
	DECLARE_FUNCTION(execSaveAchievementProgress); \
	DECLARE_FUNCTION(execSaveAchievementProgressAsync); \
	DECLARE_FUNCTION(execIncreaseAchievementProgress);


#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPluginBPLibrary_h_13_INCLASS \
private: \
	static void StaticRegisterNativesUAchievementPluginBPLibrary(); \
	friend struct Z_Construct_UClass_UAchievementPluginBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UAchievementPluginBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AchievementPlugin"), NO_API) \
	DECLARE_SERIALIZER(UAchievementPluginBPLibrary)


#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPluginBPLibrary_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAchievementPluginBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAchievementPluginBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAchievementPluginBPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAchievementPluginBPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UAchievementPluginBPLibrary(UAchievementPluginBPLibrary&&); \
	UAchievementPluginBPLibrary(const UAchievementPluginBPLibrary&); \
public: \
	NO_API virtual ~UAchievementPluginBPLibrary();


#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPluginBPLibrary_h_10_PROLOG
#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPluginBPLibrary_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPluginBPLibrary_h_13_RPC_WRAPPERS \
	FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPluginBPLibrary_h_13_INCLASS \
	FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPluginBPLibrary_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ACHIEVEMENTPLUGIN_API UClass* StaticClass<class UAchievementPluginBPLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPluginBPLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
