How to install the Achievement Plugin for Unreal Engine 5:

# Installation

## Requirements
- Unreal Engine 5.x (there are multiple versions on FAB, for 5.5, 5.6 and 5.7)
- For Steam support: Steamworks SDK (V162 or potentially later)
- For Epic support: Built-in EOS (no additional downloads or setups required aside from setting the data in the plugin's Developer Settings)

## Installing the Plugin
1. Download the plugin from FAB
2. (Re-)Start Unreal Editor
3. Enable the plugin: Edit → Plugins → Search "Achievement" → Check the box

## Installing Steamworks SDK (For Steam achievements)
The Steamworks SDK is not included by default since the software isn't allowed to be shared.  
**Please keep in mind that if you do end up modifying and sharing my code, that you remove the Steamworks SDK again and re-package the plugin**

For this plugin, I tested it with the Steamworks version 162 (1.62). You are free to try newer versions at the risk of it potentially not working properly.

**Also if you installed the plugin via FAB, make sure you create a copy for your project!** For more information, please look below at [Creating a copy of the FAB version for installing Steamworks](#creating-a-copy-of-the-fab-version-for-installing-steamworks)

### Downloading and placing the Steamworks SDK
First, you'll actually need to get the Steamworks SDK, you will need to remove some files from it as well.  
There is a very specific folder structure required for the SDK to be recognized, so you'll have to put it exactly where this guide tells you to.

1. Download Steamworks SDK from https://partner.steamgames.com/downloads/list
2. Extract the SDK (there is a folder just called "sdk")
3. From the extracted sdk, remove the folders called "glmgr", "steamworksexample" and "tools" (these will break packaging if you do not delete them!)
4. Go to the plugin -> Source -> AchievementPlugin (there should be 2 folders in there, "Private" and "Public" as well as a file called "AchievementPlugin.Build.cs")
5. Create a new folder called "ThirdParty"
6. In that folder, create a folder called "Steamworks"
7. Paste the "sdk" folder from earlier into this "Steamworks" folder
8. Make sure that this "sdk" folder only contains the folders named "public" and "redistributable_bin" as well as a file called "Readme.txt"

Now what you will need to do depends on whether or not you are using an IDE (like Rider, Visual Studio etc.).
If you **do not use an IDE**, just continue reading below on [how to repackage the plugin](#repackaging-with-steamworks-sdk).  
If you **are using an IDE**, you can skip repackaging and instead just build the binaries and [just rebuild the binaries](#using-steamworks-sdk-with-an-ide).  


### Repackaging with Steamworks SDK
1. Open your project (that includes this plugin)
2. Open Edit (top left) -> Plugins
3. Head to the Achievement Plugin (it has a separate category called "Achievements")
4. Press "Package" and package it somewhere where you can find it. This version of the plugin will be the one you are going to be using.
5. If the packaging ends up successful, check if inside of the newly packaged plugin's folder's Binaries/Win64 folder, there is a file called steam_api64.dll, if not, go back to step 4 and make sure you get the names **exactly** the same!
6. Close the Unreal Editor
7. Delete the old AchievementPlugin
8. Put the entire new plugin into your plugins folder

This has been tested to work as long as you get all the names exactly as stated here, now you should be free to use Steam achievements!

**Note: When the plugin updates, you will have to do this process again with the updated plugin if you'd like to receive the latest features.**  
Not to worry though, all your progress such as Achievements and Blueprint Nodes will work just fine across updates, but please still make sure to create backups of your project just in case!

### Using Steamworks SDK with an IDE
Assuming you have followed the previous steps in [Downloading and placing the Steamworks SDK](#downloading-and-placing-the-steamworks-sdk), you should be able to just build the binaries and it should work with Steamworks.  
Make sure to check the output log to see whether or not the plugin can see the variables, if it cannot, there will be a lot of logs stating that the SDK has not been found.  
If this happens and you have gone through the correct steps, try cleaning the binaries before making the build instead.

## Creating a copy of the FAB version for installing Steamworks
Due to FAB installing plugins Engine-wide rather than just to a specific project, you will have to create a copy of the plugin so you can repackage it with the Steamworks SDK included.
First of all, you'll have to go here (replace the x in UE_5.x with your version number):  
```C:\Program Files\Epic Games\UE_5.x\Engine\Plugins\Marketplace\```
In there, you should find a folder called something like this:  
```Achievemebd812214c8dV3```  
Copy that folder, then go to your project, and create a ```Plugins``` folder (if it doesn't exist yet).  
Then, paste the Achievement Plugin's folder into that folder.  
If you open your Project and check your Plugins, you should now see a "Package" button below the Achievement Plugin. This means that you can now repackage the Plugin with the Steamworks SDK included [as explained above](#installing-steamworks-sdk-for-steam-achievements)