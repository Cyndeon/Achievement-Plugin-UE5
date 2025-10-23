// -------------------------------------------------------------
// Copyright 2025 Justin Comans. Licensed under CC BY 4.0.    ||
// -------------------------------------------------------------


// ReSharper disable CppInconsistentNaming
#pragma once
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "AchievementPlatformsEnum.generated.h"

UENUM()
enum EAchievementPlatforms : uint8
{
	LOCALONLY UMETA(DisplayName = "Local Only"),
	STEAM UMETA(DisplayName = "Steam"),
	EOS UMETA(DisplayName = "EOS")
};

UENUM()
enum EAchievementUploadTypes : uint8
{
	// cannot use capitals because of the typedef conflict
	Float UMETA(DisplayName = "Float"),
	Int32 UMETA(DisplayName = "Int32")
};

UENUM(BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class EUnlockedPlatforms : uint8
{
	None = 0,
	Local = 1 << 0,  // 1
	Steam = 1 << 1,  // 2
	Epic = 1 << 2,  // 4
};
ENUM_CLASS_FLAGS(EUnlockedPlatforms)  // This enables bitwise operations