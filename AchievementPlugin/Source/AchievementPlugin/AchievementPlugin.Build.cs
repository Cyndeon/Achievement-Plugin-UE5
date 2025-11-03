// -------------------------------------------------------------
// Copyright 2025 Justin Comans. Licensed under CC BY 4.0.    ||
// -------------------------------------------------------------

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

//// Some copyright should be here...

//using System.IO;
//using UnrealBuildTool;
//public class AchievementPlugin : ModuleRules
//{
//    public AchievementPlugin(ReadOnlyTargetRules Target) : base(Target)
//    {
//        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
//        IWYUSupport = IWYUSupport.Full;

//        PublicIncludePaths.AddRange(
//            new string[] {
//                // ... add public include paths required here ...
//            }
//        );

//        PrivateIncludePaths.AddRange(
//            new string[] {
//                // ... add other private include paths required here ...
//            }
//        );

//        PublicDependencyModuleNames.AddRange(
//            new string[]
//            {
//                "Core",
//                "CoreUObject",
//                "Engine",
//                "EngineSettings",
//                "DeveloperSettings",
//                "EOSSDK",
//                "UMG"
//            }
//        );

//        PrivateDependencyModuleNames.AddRange(
//            new string[]
//            {
//                "CoreUObject",
//                "Engine",
//                "Slate",
//                "SlateCore"
//            }
//        );

//        // Editor-only modules
//        if (Target.bBuildEditor)
//        {
//            PrivateDependencyModuleNames.AddRange(new string[]
//            {
//                "PropertyEditor",
//                "ToolMenus",
//                "DetailCustomizations",
//                "Settings",
//                "EditorSettingsViewer",
//            });
//        }

//        DynamicallyLoadedModuleNames.AddRange(
//            new string[]
//            {
//                // ... add any modules that your module loads dynamically here ...
//            }
//        );

//        // Fix Steam warnings first
//        PublicDefinitions.Add("_CRT_SECURE_NO_WARNINGS");

//        // Try to find and setup Steamworks SDK
//        var bSteamworksAvailable = TrySetupSteamworks(Target);

//        if (bSteamworksAvailable)
//        {
//            PublicDefinitions.Add("STEAMWORKS_INCLUDED=1");
//            System.Console.WriteLine("Steamworks SDK found and configured");
//        }
//        else
//        {
//            PublicDefinitions.Add("STEAMWORKS_INCLUDED=0");
//            System.Console.WriteLine("Steamworks SDK not found - plugin will compile without Steam support");
//            System.Console.WriteLine("To enable Steam support, please follow the documentation's guide!");
//        }
//    }

//    private bool TrySetupSteamworks(ReadOnlyTargetRules Target)
//    {
//        // Only support Win64 for now
//        if (Target.Platform != UnrealTargetPlatform.Win64)
//        {
//            return false;
//        }

//        // Define paths - matching your "../ThirdParty/Steamworks/sdk/" structure
//        var SteamworksSdkPath = Path.Combine(ModuleDirectory, "ThirdParty", "Steamworks", "sdk");
//        var SteamIncludePath = Path.Combine(SteamworksSdkPath, "public");
//        var SteamHeaderPath = Path.Combine(SteamIncludePath, "steam", "steam_api.h");
//        var SteamLibPath = Path.Combine(SteamworksSdkPath, "redistributable_bin", "win64", "steam_api64.lib");
//        var SteamDllPath = Path.Combine(SteamworksSdkPath, "redistributable_bin", "win64", "steam_api64.dll");

//        // Check if the SDK exists
//        var bHeaderExists = File.Exists(SteamHeaderPath);
//        var bLibExists = File.Exists(SteamLibPath);
//        var bDllExists = File.Exists(SteamDllPath);

//        System.Console.WriteLine("Checking for Steamworks SDK:");
//        System.Console.WriteLine($"  Header: {SteamHeaderPath} - {(bHeaderExists ? "FOUND" : "NOT FOUND")}");
//        System.Console.WriteLine($"  Library: {SteamLibPath} - {(bLibExists ? "FOUND" : "NOT FOUND")}");
//        System.Console.WriteLine($"  DLL: {SteamDllPath} - {(bDllExists ? "FOUND" : "NOT FOUND")}");

//        // Only setup if all required files exist
//        if (!bHeaderExists || !bLibExists || !bDllExists) return false;

//        // Add include path for Steam headers
//        PublicIncludePaths.Add(SteamIncludePath);

//        // Link the Steam library
//        PublicAdditionalLibraries.Add(SteamLibPath);

//        // Copy DLL to Binaries folder
//        RuntimeDependencies.Add("$(BinaryOutputDir)/steam_api64.dll", SteamDllPath);

//        // Delay-load the DLL
//        PublicDelayLoadDLLs.Add("steam_api64.dll");

//        // Add Steam-specific definitions
//        PublicDefinitions.Add("STEAM_API_EXPORTS");

//        return true;

//    }
//}