How to install the Achievement Plugin for Unreal Engine 5:

# Installation

## Requirements
- Unreal Engine 5.6
- For Steam support: Steamworks SDK (V162 or potentially later)
- For Epic support: Built-in EOS (no additional downloads)

## Installing the Plugin
1. Download the plugin from FAB
2. Extract to your project's `Plugins` folder: `YourProject/Plugins/AchievementPlugin/`
3. (Re-)Start Unreal Editor
4. Enable the plugin: Edit → Plugins → Search "Achievement" → Check the box

## Installing Steamworks SDK (For Steam achievements)
The Steamworks SDK is not included by default since the software isn't allowed to be shared.  
**Please keep in mind that if you do end up modifying and sharing my code, that you remove the Steamworks SDK again and re-package the plugin**

For this plugin, I tested it with the Steamworks version 162 (1.62). You are free to try newer versions at the risk of it potentially not working properly.

1. Download Steamworks SDK from https://partner.steamgames.com/downloads/list
2. Extract the SDK (there is a folder just called "sdk")
3. From the extracted sdk, remove the folders called "glmgr", "steamworksexample" and "tools" (these will break packaging if you do not delete them!)
4. Go to the plugin -> Source -> AchievementPlugin (there should be 2 folders in there, "Private" and "Public" as well as a file called "AchievementPlugin.Build.cs")
5. Create a new folder called "ThirdParty"
6. In that folder, create a folder called "Steamworks"
7. Paste the "sdk" folder from earlier into this "Steamworks" folder
8. Make sure that this "sdk" folder only contains the folders named "public" and "redistributable_bin" as well as a file called "Readme.txt"
9. Open your project (that includes this plugin)
10. Open Edit (top left) -> Plugins
11. Head to the Achievement Plugin (it has a separate category called "Achievements")
12. Press "Package" and package it somewhere where you can find it. This version of the plugin will be the one you are going to be using.
13. If the packaging ends up successful, check if inside of the newly packaged plugin's folder's Binaries/Win64 folder, there is a file called steam_api64.dll, if not, go back to step 4 and make sure you get the names **exactly** the same!
14. Close the Unreal Editor
15. Delete the old AchievementPlugin
16. Put the entire new plugin into your plugins folder

This has been tested to work as long as you get all the names exactly as stated here, now you should be free to use Steam achievements!