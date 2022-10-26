#include "eSettingsMgr.h"


#include <pspsdk.h>
#include <pspkernel.h>
#include "mkdeception.h"
#include <stdio.h>
#include <string.h>
#include "eLog.h"

#include "..\minIni.h"


struct settings TheSettings;

void SettingsMgr_Init()
{
	const char* path = "ms0:/PSP/PLUGINS/mkuhook/settings.ini";

	TheSettings.bUsePuzzleModifierInNormalGame = ini_getbool("Settings", "bUsePuzzleModifierInNormalGame", 0, path);
	TheSettings.bHideFighterFaceInLifebar =		ini_getbool("Settings", "bHideFighterFaceInLifebar", 0, path);
	TheSettings.iForceShujinkoModel =			 ini_getl("Settings", "iForceShujinkoModel", -1, path);
	TheSettings.bUseImagesForExtraSelectScreen = ini_getbool("Settings", "bUseImagesExtraSelect", 0, path);

	LOG_Message("INFO: SettingsMgr_Init()\n");
}

struct settings SettingsMgr_Get()
{
	return TheSettings;
}
