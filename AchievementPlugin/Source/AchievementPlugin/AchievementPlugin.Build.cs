// Some copyright should be here...

using System.IO;
using UnrealBuildTool;
public class AchievementPlugin : ModuleRules
{
    public AchievementPlugin(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        IWYUSupport = IWYUSupport.Full;

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
                "EngineSettings",
                "DeveloperSettings",
                "EOSSDK",
                "UMG"
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

        // only works for win64, Steam
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
	        // Add include path for Steam headers
	        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "ThirdParty/steamworks_sdk_162/sdk/public"));

	        // Link the Steam library
	        var SteamLibPath = Path.Combine(ModuleDirectory, "ThirdParty/steamworks_sdk_162/sdk/redistributable_bin/win64/steam_api64.lib");
	        PublicAdditionalLibraries.Add(SteamLibPath);

	        // Copy DLL to Binaries folder
	        var SteamDllPath = Path.Combine(ModuleDirectory, "ThirdParty/steamworks_sdk_162/sdk/redistributable_bin/win64/steam_api64.dll");
	        RuntimeDependencies.Add("$(BinaryOutputDir)/steam_api64.dll", SteamDllPath);

	        // Delay-load the DLL
	        PublicDelayLoadDLLs.Add("steam_api64.dll");
        }
    }
}