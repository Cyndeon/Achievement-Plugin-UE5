using UnrealBuildTool;
using System.Collections.Generic;

public class AchievementPluginGameTarget : TargetRules
{
	public AchievementPluginGameTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

		// CRITICAL: Force modular build (separate DLLs)
		bBuildInMonolithicMode = false;
		bCompileAgainstEngine = true;

		ExtraModuleNames.AddRange(new string[] { "AchievementPlugin" });
	}
}