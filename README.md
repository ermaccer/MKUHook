# MKUHook
 A plugin for Mortal Kombat Unchained (PPSSPP).


# Features:
- **NPC Select Screen**
    - Adds an extra select screen with NPCs that can be accessed by pressing Square at the select screen
    - Kano & Mokap are also restored from leftover files as extra options
    - This feature benefits from additional select images which can be downloaded <a href="https://ermaccer.github.io/posts/mkuhook-select-screen-images/">here</a>. Note that after installation .ini file needs to be edited
    for them to appear.
- **Extra Stages**
    - Konquest stages are added to the stage select menu, they will also play randon game music
- **Alternate Color Toggle**
    - Press **Circle** at select screen to play with alternate colors
- **Shujinko Age Modifier**
    - Editing the .ini file allows to change current Konquest player model
- **Puzzle Modifier**
    - Editing the .ini file allows to play with puzzle mode scaling in any game mode

# Installation

MKUHook requires **ULUS10102** release of the game, it also requires
version 1.11.3 or later of PPSSPP emulator.

Drag the PSP folder onto PPSSPP folder, which is usually located in Documents folder on
Windows. On Android, it is usually in root memory card folder ("PSP").

If you use PPSSPP portable, the PSP folder is in memstick directory.



### If plugin crashes or doesn't load in your PPSSPP, disable "Fast Memory"!


# Screenshots

![Preview](https://raw.githubusercontent.com/ermaccer/ermaccer.github.io/gh-pages/assets/mods/mku/mkuhook/selectimages.jpg)
![Preview](https://raw.githubusercontent.com/ermaccer/ermaccer.github.io/gh-pages/assets/mods/mku/mkuhook/1.jpg)
![Preview](https://raw.githubusercontent.com/ermaccer/ermaccer.github.io/gh-pages/assets/mods/mku/mkuhook/2.jpg)

# Configuration

MKUHook comes with a simple configuration file, which allows you to use extra features.
Open PSP\PLUGINS\mkuhook\settings.ini with any text editor.

# Building
You will need PSPSDK set up, then simply execute the Makefile (or use Visual Studio solution).

# Used stuff
https://github.com/compuphase/minIni
