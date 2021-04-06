# MKUHook
 A plugin for Mortal Kombat Unchained (PPSSPP).



# Features:
## NPC select screen

You can access all new select screen by pressing square + circle at any time.
You can select NPC characters there.

## Puzzle Modifier

Scales down characters in all game modes similarly to Puzzle Kombat

## Shujinko's Age Modifier

Allows to change model of Shujinko in Konquest mode.


#  Installation

MKUHook requires **ULUS10102** release of the game, it also requires
version 1.11.3 or later of PPSSPP emulator.

Drag the PSP folder onto PPSSPP folder, which is usually located in Documents folder on
Windows. On Android, it is usually in root memory card folder ("PSP").

# Configuration

MKUHook comes with a simple configuration file, which allows you to use extra features.
Open PSP\PLUGINS\mkuhook\settings.txt with any text editor.

Values are seperate by spaces, 100 means disabled (depends on setting)

Settings list (starting from first value):
-bUsePuzzleModifierInNormalGame - 0 by default, setting this value to 1 enables puzzle modifier everywhere
-iForceShujinkoModel - 100 by default, set this value to 0-4 to change Shujinko's model in Konquest


There's an extra log file - log.txt which can tell you if the plugin works or no.