#include "eLog.h"
#include <string.h>

#include <pspsdk.h>
#include <pspkernel.h>

char log_path[260];
int log_uid;

void LOG_Initialise()
{
	log_uid = sceIoOpen("ms0:/PSP/PLUGINS/mkuhook/log.txt", PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 0777);
	if (log_uid >= 0) sceIoClose(log_uid);

	LOG_Message("INFO: MKUHook 0.1 by ermaccer init!\n");


}

void LOG_Message(char * message)
{
	log_uid = sceIoOpen("ms0:/PSP/PLUGINS/mkuhook/log.txt", PSP_O_WRONLY | PSP_O_CREAT | PSP_O_APPEND, 0777);


	sceIoWrite(log_uid, message, strlen(message));
	if (log_uid >= 0) sceIoClose(log_uid);
}
