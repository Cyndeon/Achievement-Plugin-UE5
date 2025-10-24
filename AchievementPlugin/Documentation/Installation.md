How to install the Achievement Plugin for Unreal Engine 5:

# Installation

## Requirements
- Unreal Engine 5.6
- For Steam support: Steamworks SDK (V162 for Win64 comes with the plugin)
- For Epic support: Built-in EOS (no additional downloads)

## Installing the Plugin
1. Download the plugin from FAB
2. Extract to your project's `Plugins` folder: `YourProject/Plugins/AchievementPlugin/`
3. (Re-)Start Unreal Editor
4. Enable the plugin: Edit → Plugins → Search "Achievement" → Check the box

## Alternate install (without FAB), requires C++
1. Download the plugin from [Github here](https://github.com/Cyndeon/Achievement-Plugin-UE5)
2. Extract the plugin folder to your project's `Plugins` folder: `YourProject/Plugins/AchievementPlugin/`
3. (Re-)Start Unreal Editor
4. Enable the plugin: Edit → Plugins → Search "Achievement" → Check the box
### Using the alternate install in Blueprint-only engine versions
1. Follow the above steps for Alternate install
2. Go to your Plugins
3. On the Achievement Plugin, press package and package it somewhere where you can find it
4. Go to the plugin's folder (in your C++ project)->Binaries->Win64 and copy-paste the `steam_api64.dll` into your packaged project's Binaries->Win64
   OR
   Follow the steps below for Update Steam SDK Setup (Optional) to get other versions of the SDK
5. Extract the new packaged plugin's folder to your new Blueprint-only project's `Plugins` folder: `YourProject/Plugins/AchievementPlugin/`
6. 3. (Re-)Start Unreal Editor
7. Enable the plugin: Edit → Plugins → Search "Achievement" → Check the box
## Update Steam SDK Setup (Optional)
If using Steam achievements:
1. Close the Editor if it is open
2. Download Steamworks SDK from [Steamworks Partner Site](https://partner.steamgames.com/)
3. Extract the SDK
4. Copy `steam_api64.dll` from `redistributable_bin/win64/` 
5. Paste into: `YourProject/Plugins/AchievementPlugin/Binaries/Win64/`

The plugin includes `steam_api64.dll` using SDK V162 by default, but you may need to update it.