#include <pspsdk.h>
#include <pspkernel.h>
#include <systemctrl.h>
#include <string.h>

#include <stdio.h>
#include "code/pspmem.h"
#include "code/mkdeception.h"
#include "code/mkumenu.h"
#include "code/mkuhook.h"
#include "code/eLog.h"
#include "code/eSettingsMgr.h"

#define TARGET_GAME "MK6"
#define MODULE_NAME "MKUHook"

//#define REAL_PSP

PSP_MODULE_INFO(MODULE_NAME, 0, 0, 1);

int GenericTrueReturn() { return 1; }
int GenericFalseReturn() { return 0; }
void  GenericDummy() { }


void Init(unsigned int addr)
{
	LOG_Initialise();
	PSPPatcher_Init(addr);
	MKDeception_Init(addr);
	SettingsMgr_Init();


	if (SettingsMgr_Get().bUsePuzzleModifierInNormalGame)
		Nop(0x153DD4);



	MakeCall(0xA0DB4, (int)hook_load_hero_model);
	MakeCall(0x1C0710, (int)hook_load_hero_model);


	MakeCall(0x14EFAC, (int)hook_create_player);
	MakeCall(0x14EFC0, (int)hook_create_player);
	MakeCall(0x15FEA0, (int)hook_restore_select_screen);
	// this allows npcs to be selectable
	MakeCall(0x6F7F4, (int)hook_character_lock_status);
	MakeCall(0xBD370, (int)hook_character_lock_status);
	MakeCall(0xBEADC, (int)hook_character_lock_status);
	MakeCall(0xCE368, (int)hook_character_lock_status);
	MakeCall(0xF0528, (int)hook_character_lock_status);
	MakeCall(0xF0748, (int)hook_character_lock_status);
	MakeCall(0x14EF30, (int)hook_character_lock_status);
	MakeCall(0x153A04, (int)hook_character_lock_status);
	MakeCall(0x15EE10, (int)hook_character_lock_status);
	MakeCall(0x15EE78, (int)hook_character_lock_status);
	MakeCall(0x15F1D0, (int)hook_character_lock_status);
	MakeCall(0x15F838, (int)hook_character_lock_status);
	MakeCall(0x15FDBC, (int)hook_character_lock_status);
	MakeCall(0x16072C, (int)hook_character_lock_status);
	MakeCall(0x1627F0, (int)hook_character_lock_status);
	MakeCall(0x163938, (int)hook_character_lock_status);





	sceKernelDcacheWritebackAll();
	sceKernelIcacheClearAll();
}


#ifndef REAL_PSP
// based on https://github.com/hrydgard/ppsspp/pull/13335#issuecomment-689026242
int module_start(SceSize args, void *argp) {
	if (sceIoDevctl("kemulator:", 0x00000003, NULL, 0, NULL, 0) == 0) {
		SceUID modules[10];
		int count = 0;
		if (sceKernelGetModuleIdList(modules, sizeof(modules), &count) >= 0) {
			int i;
			SceKernelModuleInfo info;
			for (i = 0; i < count; ++i) {
				info.size = sizeof(SceKernelModuleInfo);
				if (sceKernelQueryModuleInfo(modules[i], &info) < 0) {
					continue;
				}

				if (strcmp(info.name, TARGET_GAME) == 0) 
				{
					Init(info.text_addr);
					SceUID thid = sceKernelCreateThread("MKUHook menu", menu_thread, 0, 0x10000, 0, NULL);
					if (thid >= 0)
						sceKernelStartThread(thid, 0, argp);
				}
			}
		}
	}
	return 0;
}
#endif



#ifdef REAL_PSP

static STMOD_HANDLER previous;

int OnModuleStart(SceModule2 *mod) {
	if (strcmp(mod->modname, TARGET_GAME) == 0) 
	{
		Init(mod->text_addr);
		SceUID thid = sceKernelCreateThread("MKUHook menu", menu_thread, 0, 0x10000, 0, NULL);
		if (thid >= 0)
			sceKernelStartThread(thid, 0, NULL);
	}

	if (!previous)
		return 0;

	return previous(mod);
}

int module_start(SceSize args, void *argp) {
	previous = sctrlHENSetStartModuleHandler(OnModuleStart);
	return 0;
}
#endif