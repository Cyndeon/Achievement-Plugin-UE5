// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "USaveSystem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ACHIEVEMENTPLUGIN_USaveSystem_generated_h
#error "USaveSystem.generated.h already included, missing '#pragma once' in USaveSystem.h"
#endif
#define ACHIEVEMENTPLUGIN_USaveSystem_generated_h

#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_USaveSystem_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAchievementSave(); \
	friend struct Z_Construct_UClass_UAchievementSave_Statics; \
public: \
	DECLARE_CLASS(UAchievementSave, USaveGame, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AchievementPlugin"), NO_API) \
	DECLARE_SERIALIZER(UAchievementSave)


#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_USaveSystem_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAchievementSave(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UAchievementSave(UAchievementSave&&); \
	UAchievementSave(const UAchievementSave&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAchievementSave); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAchievementSave); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAchievementSave) \
	NO_API virtual ~UAchievementSave();


#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_USaveSystem_h_9_PROLOG
#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_USaveSystem_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_USaveSystem_h_12_INCLASS_NO_PURE_DECLS \
	FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_USaveSystem_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ACHIEVEMENTPLUGIN_API UClass* StaticClass<class UAchievementSave>();

#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_USaveSystem_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAchievementSaveManager(); \
	friend struct Z_Construct_UClass_UAchievementSaveManager_Statics; \
public: \
	DECLARE_CLASS(UAchievementSaveManager, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AchievementPlugin"), NO_API) \
	DECLARE_SERIALIZER(UAchievementSaveManager)


#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_USaveSystem_h_28_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAchievementSaveManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UAchievementSaveManager(UAchievementSaveManager&&); \
	UAchievementSaveManager(const UAchievementSaveManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAchievementSaveManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAchievementSaveManager); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAchievementSaveManager) \
	NO_API virtual ~UAchievementSaveManager();


#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_USaveSystem_h_25_PROLOG
#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_USaveSystem_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_USaveSystem_h_28_INCLASS_NO_PURE_DECLS \
	FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_USaveSystem_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ACHIEVEMENTPLUGIN_API UClass* StaticClass<class UAchievementSaveManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_USaveSystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
