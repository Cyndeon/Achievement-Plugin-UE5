Here's some common issues that may occur when using the plugin.
# Troubleshooting

### **Plugin won't load / "Module could not be loaded"/Engine won't start error:**
- Make sure `steam_api64.dll` is in `Plugins/AchievementPlugin/Binaries/Win64/`

### **Steam achievements not syncing:**
- Check your Steam App ID is correct in Project Settings
- Check your selected Platform in the Project Settings, this must be set to Steam
- Ensure Steam client is running
- Check to see if Steam sees your account as "Playing" your game when you press play in the editor
- Verify achievements are set up in Steamworks Partner portal
- If using Stats (for progress achievements), make sure to check that you are uploading the correct type to Steam. It expects either int32 or float, so your achievement needs to use the same type (found in the Platform Settings of the achievement)

### **Epic achievements not syncing:**
- Check your Epic Games data is correct in Project Settings (The starting guide has tips on how to fill it in, [[Basic Starting Guide]])
- Check your selected Platform in the Project Settings, this must be set to EOS
- Verify achievements are set up in Epic Games Dev portal

### **Epic achievements progress way too quickly**
- Check your Stats in the Epic Games Dev Portal to see what the Aggregation type is. I'd recommend MAX or LATEST. Setting it to SUM will count up the values which will make it progress insanely fast because it counts up the current value + what it receives, which is not how the plugin works, the plugin will keep track of the values and then send the latest value to the platform every time
### **The engine keeps telling me it was made for x but it works just fine on the version I am using, how do I disable this popup?**
- You can manually change the version number in the plugin's .uplugin
- Look for the `"EngineVersion": "x",`  and replace x with your version number, for example 5.6.1  

**Note: The plugin's creator will not be held responsible for any issues that may arise from using the plugin on a version it wasn't built for. While it likely will work fine for some earlier versions, make sure that if you build it for an earlier or later version, that you test it in a clean testing environment before adding it to your project**

### **I want to initialize a non-local platform myself or just disable initializing the platform I chose, how do I do this?**
- I have created a page for that as well, please look there: [[Platform Initialization]]

### **When trying to download achievements from platforms (Steam/EOS), nothing happens!**
- Make sure that your plugin's selected platform isn't set to `Local Only`, it has to be set to the platform you want to download from.
- Otherwise it is because the plugin will first attempt to connect to the platform, which means it might take a couple of tries before it is set up properly. This mostly seems to be an issue with EOS, it might take up to 3 attempts to download it but it should work regardless
- Make sure you have a proper internet connection to connect to the platform of choice
- Make sure the data (SteamAppId, Epic Games Store Data, etc.) is configured properly

### **My blueprint-only project, after being packaged, tells me that the plugin "AchievementPlugin" is missing!**
- This may happen for unknown reasons, but there is a very simple solution for it.
  NOTE: You will need an IDE (Integrated Development Environment) for this to work, in case you do not have one already, I would recommend Visual Studio Community 2022 as this is the one I used the most. If you want to work with C++ more, I'd recommend Rider, which has a lot of useful features specifically for UE5 C++ development and it is free for students (such as myself).
- Open up your blueprint-only project, click on the "Edit" button in the top-left and click "Add new C++ class", don't worry, you won't have to code or even touch this file at all!
- Don't open up the file or anything, just close the Unreal Editor
- Open the .uproject again, it will not prompt you to rebuild your project, this is fine, just do that and it will open the editor for you afterwards.
- Try packaging your project again, this time, it should work!

In case you, by any chance, are a programmer with C++ UE5 experience and know why this is happening, please reach out to me at: justingamedeveloperbusiness@gmail.com or use the Github Repo's Issues tab, as I would like to fix this issue, but haven't found a way outside of creating the C++ class.