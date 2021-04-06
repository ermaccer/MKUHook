#include "eSettingsMgr.h"


#include <pspsdk.h>
#include <pspkernel.h>
#include "mkdeception.h"
#include <stdio.h>
#include <string.h>
#include "eLog.h"
#include "helper.h"


struct settings TheSettings;

void SettingsMgr_Init()
{
	int file_uid;

	TheSettings.bUsePuzzleModifierInNormalGame = 0;
	TheSettings.iForceShujinkoModel = -1;

	char settingsData[1024];
	memset(&settingsData, 0, 1024);


	file_uid = sceIoOpen("ms0:/PSP/PLUGINS/mkuhook/settings.txt", PSP_O_RDONLY, 0777);
	if (file_uid >= 0)
	{
		SceIoStat info;
		sceIoGetstat("ms0:/PSP/PLUGINS/mkuhook/settings.txt", &info);

		sceIoRead(file_uid, &settingsData, info.st_size);
		char* puzzle = settingsData;
		char* konq = settingsData + 2;
		char msg[256];
		memset(&msg, 0, 256);

		mk_sprintf(msg, settingsData);
		TheSettings.bUsePuzzleModifierInNormalGame = str_to_int(msg);

		TheSettings.iForceShujinkoModel = str_to_int(settingsData + 2);

		mk_sprintf(msg, "bUsePuzzleModifierInNormalGame = %d\n", TheSettings.bUsePuzzleModifierInNormalGame);
		LOG_Message(msg);
		mk_sprintf(msg, "iForceShujinkoModel  = %d\n", TheSettings.iForceShujinkoModel);
		LOG_Message(msg);

		sceIoClose(file_uid);
	}
}

struct settings SettingsMgr_Get()
{
	return  TheSettings;
}
