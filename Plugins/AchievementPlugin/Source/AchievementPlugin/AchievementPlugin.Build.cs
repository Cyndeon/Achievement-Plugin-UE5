// Some copyright should be here...

using System.IO;
using UnrealBuildTool;
public class AchievementPlugin : ModuleRules
{
    public AchievementPlugin(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        IWYUSupport = IWYUSupport.Full;
        bUseUnity = false;

        PublicIncludePaths.AddRange(
            new string[] {
                // ... add public include paths required here ...
            }
        );

        PrivateIncludePaths.AddRange(
            new string[] {
                // ... add other private include paths required here ...
            }
        );

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "DeveloperSettings"
                // Removed PropertyEditor and ToolMenus - they're editor-only!
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore"
            }
        );

        // Editor-only modules
        if (Target.bBuildEditor)
        {
            PrivateDependencyModuleNames.AddRange(new string[]
            {
                "PropertyEditor",
                "ToolMenus",     
                "DetailCustomizations",
                "Settings",
                "EditorSettingsViewer",
            });
        }

        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
                // ... add any modules that your module loads dynamically here ...
            }
        );

        // only works for win64, add more options later!
        string SteamPath = Path.Combine(ModuleDirectory, "ThirdParty", "steamworks_sdk_162", "sdk");

        PublicIncludePaths.Add(Path.Combine(SteamPath, "sdk", "public"));
        PublicAdditionalLibraries.Add(Path.Combine(SteamPath, "redistributable_bin", "win64", "steam_api64.lib"));

        RuntimeDependencies.Add("$(TargetOutputDir)/steam_api64.dll",
	        Path.Combine(SteamPath, "redistributable_bin", "win64", "steam_api64.dll"));
    }
}