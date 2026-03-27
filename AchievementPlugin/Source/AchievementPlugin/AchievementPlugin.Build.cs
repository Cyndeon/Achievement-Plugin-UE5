// -------------------------------------------------------------
// Copyright 2025 Justin Comans. All rights reserved.         ||
// -------------------------------------------------------------

using System;
using System.IO;
using UnrealBuildTool;
public class AchievementPlugin : ModuleRules
{
    public AchievementPlugin(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        IWYUSupport = IWYUSupport.Full;

        System.Console.WriteLine(Target.Type);

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "EngineSettings",
                "EOSSDK",
                "UMG"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Projects",
            }
        );
        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
                // ... add any modules that your module loads dynamically here ...
            }
        );

        // Fix Steam warnings first
        PublicDefinitions.Add("_CRT_SECURE_NO_WARNINGS");

        // Try to find and setup Steamworks SDK
        var bSteamworksAvailable = TrySetupSteamworks(Target);

        if (bSteamworksAvailable)
        {
            PublicDefinitions.Add("STEAMWORKS_INCLUDED=1");
            System.Console.WriteLine("Steamworks SDK found and configured");
        }
        else
        {
            PublicDefinitions.Add("STEAMWORKS_INCLUDED=0");
            System.Console.WriteLine("Steamworks SDK not found - plugin will compile without Steam support");
            System.Console.WriteLine("To enable Steam support, please follow the documentation's guide!");
        }
    }

    private bool TrySetupSteamworks(ReadOnlyTargetRules Target)
    {
        if (Target.Platform != UnrealTargetPlatform.Win64)
        {
            return false;
        }

        var SteamworksSdkPath = Path.Combine(ModuleDirectory, "ThirdParty", "Steamworks", "sdk");
        var SteamIncludePath = Path.Combine(SteamworksSdkPath, "public");
        var SteamHeaderPath = Path.Combine(SteamIncludePath, "steam", "steam_api.h");
        var SteamLibPath = Path.Combine(SteamworksSdkPath, "redistributable_bin", "win64", "steam_api64.lib");
        var SteamDllPath = Path.Combine(SteamworksSdkPath, "redistributable_bin", "win64", "steam_api64.dll");

        var bHeaderExists = File.Exists(SteamHeaderPath);
        var bLibExists = File.Exists(SteamLibPath);
        var bDllExists = File.Exists(SteamDllPath);

        System.Console.WriteLine("Checking for Steamworks SDK:");
        System.Console.WriteLine($"  Header: {SteamHeaderPath} - {(bHeaderExists ? "FOUND" : "NOT FOUND")}");
        System.Console.WriteLine($"  Library: {SteamLibPath} - {(bLibExists ? "FOUND" : "NOT FOUND")}");
        System.Console.WriteLine($"  DLL: {SteamDllPath} - {(bDllExists ? "FOUND" : "NOT FOUND")}");

        if (!bHeaderExists || !bLibExists || !bDllExists) return false;

        PublicIncludePaths.Add(SteamIncludePath);
        PublicAdditionalLibraries.Add(SteamLibPath);
        RuntimeDependencies.Add("$(BinaryOutputDir)/steam_api64.dll", SteamDllPath);
        PublicDefinitions.Add("STEAM_API_EXPORTS");

        // Copy DLL to plugin's Binaries folder so it gets packaged
        var targetBinariesDir = Path.Combine(PluginDirectory, "Binaries", "Win64");
        var targetDllPath = Path.Combine(targetBinariesDir, "steam_api64.dll");

        try
        {
            Directory.CreateDirectory(targetBinariesDir);

            // Only copy if source is newer or target doesn't exist
            if (!File.Exists(targetDllPath) ||
                File.GetLastWriteTime(SteamDllPath) > File.GetLastWriteTime(targetDllPath))
            {
                File.Copy(SteamDllPath, targetDllPath, true);
                System.Console.WriteLine($"Copied steam_api64.dll to: {targetDllPath}");
            }
        }
        catch (Exception ex)
        {
            System.Console.WriteLine($"Warning: Failed to copy DLL: {ex.Message}");
        }

        return true;
    }
}