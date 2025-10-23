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