#include "ssf.h"
#include "mkdeception.h"
#include "pspmem.h"
#include "eLog.h"

#include <pspsdk.h>
#include <pspkernel.h>

char ssfLogBuffer[256];

void hook_load_ssf(struct mem_ssf_header* ptr)
{
	struct mem_ssf_entry ent;
	mk_sprintf(ssfLogBuffer, "INFO: Loading SSF %s Files:\n", (char*)*(int*)(ptr->fileName));
	LOG_Message(ssfLogBuffer);

	{
		int dmp_uid = 0;

		char newName[120];

		mk_sprintf(newName, "%s", (char*)*(int*)(ptr->fileName));

		newName[strlen(newName) - 4] = 0x00;

		mk_sprintf(ssfLogBuffer, "ms0:/PSP/PLUGINS/mkuhook/ssf/%s.txt", newName);


		SceIoStat info;
		int status = sceIoGetstat(ssfLogBuffer, &info);


		if (status < 0)
			dmp_uid = sceIoOpen(ssfLogBuffer, PSP_O_WRONLY | PSP_O_CREAT | PSP_O_APPEND, 0777);

		for (int i = 0; i < 250; i++)
		{
			if (ptr->files[i].fileName == 0 && ptr->files[i].fileSize == 0)
				break;
			mk_sprintf(ssfLogBuffer, "%s\n", (char*)*(int*)(ptr->files[i].fileName), ptr->files[i].fileSize, ptr->files[i].totalFileSize);
			if (dmp_uid >= 0)
				sceIoWrite(dmp_uid, ssfLogBuffer, strlen(ssfLogBuffer));
		}
		if (dmp_uid >= 0) sceIoClose(dmp_uid);
	}
	
	load_ssf(ptr);
}
