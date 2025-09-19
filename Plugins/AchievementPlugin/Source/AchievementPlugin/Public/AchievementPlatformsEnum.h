// ReSharper disable CppInconsistentNaming
#pragma once

UENUM()
enum EAchievementPlatforms : uint8
{
	LOCALONLY = 0,
	STEAM,
	EOS
};

UENUM()
enum EAchievementUploadTypes : uint8
{
	// cannot use capitals because of the typedef conflict
	Float = 0,
	Int32
};