// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AchievementPlatformsEnum.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ACHIEVEMENTPLUGIN_AchievementPlatformsEnum_generated_h
#error "AchievementPlatformsEnum.generated.h already included, missing '#pragma once' in AchievementPlatformsEnum.h"
#endif
#define ACHIEVEMENTPLUGIN_AchievementPlatformsEnum_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ChievPluginZone_Plugins_AchievementPlugin_Source_AchievementPlugin_Public_AchievementPlatformsEnum_h


#define FOREACH_ENUM_EACHIEVEMENTPLATFORMS(op) \
	op(LOCALONLY) \
	op(STEAM) \
	op(EOS) 

enum EAchievementPlatforms : uint8;
template<> ACHIEVEMENTPLUGIN_API UEnum* StaticEnum<EAchievementPlatforms>();

#define FOREACH_ENUM_EACHIEVEMENTUPLOADTYPES(op) \
	op(Float) \
	op(Int32) 

enum EAchievementUploadTypes : uint8;
template<> ACHIEVEMENTPLUGIN_API UEnum* StaticEnum<EAchievementUploadTypes>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
