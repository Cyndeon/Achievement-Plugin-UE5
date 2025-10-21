// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AchievementPlugin.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UWorld;
#ifdef ACHIEVEMENTPLUGIN_AchievementPlugin_generated_h
#error "AchievementPlugin.generated.h already included, missing '#pragma once' in AchievementPlugin.h"
#endif
#define ACHIEVEMENTPLUGIN_AchievementPlugin_generated_h

#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execIsEpicPlatform); \
	DECLARE_FUNCTION(execIsSteamPlatform);


#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h_37_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAchievementPluginSettings(); \
	friend struct Z_Construct_UClass_UAchievementPluginSettings_Statics; \
public: \
	DECLARE_CLASS(UAchievementPluginSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/AchievementPlugin"), NO_API) \
	DECLARE_SERIALIZER(UAchievementPluginSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h_37_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UAchievementPluginSettings(UAchievementPluginSettings&&); \
	UAchievementPluginSettings(const UAchievementPluginSettings&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAchievementPluginSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAchievementPluginSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UAchievementPluginSettings) \
	NO_API virtual ~UAchievementPluginSettings();


#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h_34_PROLOG
#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h_37_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h_37_INCLASS_NO_PURE_DECLS \
	FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h_37_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ACHIEVEMENTPLUGIN_API UClass* StaticClass<class UAchievementPluginSettings>();

#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h_155_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnWorldCleanup); \
	DECLARE_FUNCTION(execOnWorldInitialized);


#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h_155_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAchievementManagerSubSystem(); \
	friend struct Z_Construct_UClass_UAchievementManagerSubSystem_Statics; \
public: \
	DECLARE_CLASS(UAchievementManagerSubSystem, UEngineSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AchievementPlugin"), NO_API) \
	DECLARE_SERIALIZER(UAchievementManagerSubSystem)


#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h_155_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAchievementManagerSubSystem(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UAchievementManagerSubSystem(UAchievementManagerSubSystem&&); \
	UAchievementManagerSubSystem(const UAchievementManagerSubSystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAchievementManagerSubSystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAchievementManagerSubSystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UAchievementManagerSubSystem) \
	NO_API virtual ~UAchievementManagerSubSystem();


#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h_151_PROLOG
#define FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h_155_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h_155_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h_155_INCLASS_NO_PURE_DECLS \
	FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h_155_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ACHIEVEMENTPLUGIN_API UClass* StaticClass<class UAchievementManagerSubSystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlugin_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
