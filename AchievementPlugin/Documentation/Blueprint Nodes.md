## Introduction
As with any new plugin, it is understandable that there is a lot of content that any new user will be unfamiliar with. For that reason, this page exists as a way to help introduce all the Blueprint nodes accessible in the Plugin with explanations as to what the nodes actually do, need (Parameters) and return.

The Nodes themselves do have Tooltips as well as a clear naming convention, so these should hopefully be easy to remember once you worked with it for a little bit.

## Settings
**Returns:** A pointer to UAchievementPluginSettings
## Achievement Progress
### Change Achievement Progress
**Function:** Increases the achievement's progress by *Change*
**Parameters:**  
- *Local Achievement Id:* The Local Achievement's Id, which is the name set in the AchievementsData's map as the Key
- *Change:* The value to increase the achievement's progress by, negative values will lead to a reduction in progress instead  
**Returns:** Whether the function was called successfully
### Get Achievement Unlocked Status
**Function:** Will return whether an achievement has been unlocked
**Parameters:**  
- *Local Achievement Id:* The Local Achievement's Id, which is the name set in the AchievementsData's map as the Key
**Returns:** Whether the achievement has been unlocked (locally)
### Get Achievement Progress By Id
**Function:** Gets a copy of the achievement progress based on the *Local Achievement Id* given
**Parameters:**  
- *Local Achievement Id:* The Local Achievement's Id, which is the name set in the AchievementsData's map as the Key
**Returns:** A copy of the achievement's progress
### Get Achievement Progress ByData
**Function:** Gets a copy of the achievement progress based on the achievement data given
**Parameters:**  
- *Achievement Data:* The achievement data for which the progress should be received
**Returns:** A copy of the achievement's progress
### Delete Single Achievement Progress
**Function:** Delete's the progress for a single achievement
**Parameters:**  
- *Local Achievement Id:* The Local Achievement's Id, which is the name set in the AchievementsData's map as the Key
- *Platforms Too:* Whether to delete the progress on the currently selected platform (Steam/EOS) too. Does not work for EOS.
**Returns:** Whether the achievement's progress was successfully deleted
### Delete All Achievement Progress
**Function:** Delete's the progress for a all achievements
**Parameters:**  
- *Platforms Too:* Whether to delete the progress on the currently selected platform (Steam/EOS) too. Does not work for EOS.
**Returns:** Whether all achievements' progress was successfully deleted

## Achievement Data
### Get Achievement Data
**Function:** Gets a copy of the achievement data based on the *Local Achievement Id* given
**Parameters:**  
- *Local Achievement Id:* The Local Achievement's Id, which is the name set in the AchievementsData's map as the Key
**Returns:** A copy of the Achievement's data

## Saving and Loading
### Save Achievement Progress Async
**Function:** Saves the current achievements' progress Asynchronously using UE5's AsyncSaveGameToSlot(...)
**Returns:** Whether it started saving (will return false if it was still busy saving from a previous call)
### Save Achievement Progress
**Function:** Saves the current achievements' progress using UE5's SaveGameToSlot(...)
**Returns:** Whether the saving was successful
### Load Achievement Progress
**Function:** Loads the achievement progress using UE5's LoadGameFromSlot, then Cleans up any outdated achievements and creates empty progress ones for newly added achievements
**Returns:** Whether the loading was successful
### Set Save Slot Index
**Function:** Sets the save slot index for UE5's saving system
**Parameters:**  
- *New Index*: The new index to use

## Platforms
### Retroactviely Update Achievements On Platforms
**Function:** This will update the progress for all achievements on the selected Platform. Helpful for if the user played the game offline and then connects to Steam/EOS
### Achievement Platform Initialized
**Function:** This will force-set the "initialized" boolean to *init*, making the Plugin believe that the platform has been successfully initialized. Only used for if the user wants to start the Platform somewhere else. This can also be used to unset the initialization, if the user wants that.
**Parameters:**  
- *Platform*: Which platform should be set to being "Initialized"
- *Init*: Whether to count the platform as being initialized  
### Has Platform Flag
**Function:** It checks whether the EUnlockedPlatformFlags given contains the flag given
**Parameters:**  
- *Flags*: The Enum that is being checked whether it contains *FlagToCheck*
- *FlagToCheck*: The flag that is being checked for
**Returns:** Whether the Flags contains FlagToCheck

## Achievement Popup
### Remove Achievement Widget
**Function:** This will delete the oldest popup. By default only used in the Popup Widget


## Achievement List
### Create Achievement List Widget
**Function:** Creates the Achievement List Widget
**Returns:** Whether the Achievement List Widget was successfully created
### Show Achievement List Widget
**Function:** Refreshes the Achievement List Widget's Display and then sets the Visibility to Visible
**Returns:** Whether the Achievement List was successfully set to Visible
### Hide Achievement List Widget
**Function:** Sets the Achievement List's Visibility to Collapsed
**Returns:** Whether the Achievement List was successfully set to Collapsed
### Change Filter For Achievement List Widget
**Function:** Sets the Filter for the Achievement List to those given in the parameters. Usually combined with Get Filter For Achievement List Widget to get the current Filter, then modify it
**Parameters:**  
- *Filter*: The new Filter to use
**Returns:** Whether the Filter was successfully applied
### Get Filter For Achievement List Widget 
**Function:** Returns the currently active Filter for the Achievement List Widget
**Returns:** The currently active Filter for the Achievement List Widget
### Get Default Filter For Achievement List Widget 
**Function:** Returns the Default Filter for the Achievement List Widget, set in the Achievement Plugin's Settings
**Returns:** The Default Filter for the Achievement List Widget
### Format Number With Suffix
**Function:** Formats the float value given using a letter or scientific notation based on the current active Filter. The amount of decimals to use is also decided by the currently active Filter
**Parameters:**  
- *Value*: The float value to format
**Returns:** The formatted *Value*.
### Set Search Text
**Function:** Sets the Filter's search text to that given as *Text*. It has a timer that updates the Filter only once every 0.2 seconds (to prevent it from being spammed too much during typing), after that timer goes off, the Achievement List will be refreshed using the *Text* to Filter which achievements get shown. The Filter will search in both the achievement's name and description
**Parameters:**  
- *Text*: The text the player has typed into the search bar that will be used to filter the achievements
**Returns:** Whether the search text has been set successfully