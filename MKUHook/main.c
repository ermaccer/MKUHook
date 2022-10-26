#include <pspsdk.h>
#include <pspkernel.h>
#include <stdio.h>
#include <systemctrl.h>
#include <string.h>



#include "code/config.h"
#include "code/pspmem.h"
#include "code/mkdeception.h"
#include "code/mkuhook.h"
#include "code/ssf.h"
#include "code/eLog.h"
#include "code/mkuplrinfo.h"
#include "code/eSettingsMgr.h"
#include "code/stage.h"

#include "code/mips.h"

PSP_MODULE_INFO(MODULE_NAME, 0, 1, 0);
static STMOD_HANDLER previous;
SceUID thid;
u32 mod_text_addr;

int GenericTrueReturn() { return 1; }
int GenericFalseReturn() { return 0; }
void  GenericDummy() { }



int Init(u32 addr)
{
	LOG_Initialise();
	PSPPatcher_Init(addr);
	MKDeception_Init(addr);
	SettingsMgr_Init();
	//dump_char_table(addr);
	//dump_stage_table(addr);
	dump_select_stable(addr);
	calculate_custom_toc();
	
	
	if (SettingsMgr_Get().bUsePuzzleModifierInNormalGame)
		Nop(0x153DD4);
	
	if (SettingsMgr_Get().bHideFighterFaceInLifebar)
		PatchChar(0x2CECE0, 0x00);
	
	MakeCall(0xA0DB4, (int)hook_load_hero_model);
	MakeCall(0x1C0710, (int)hook_load_hero_model);
	
	//
	//


	//MakeCall(0x15FEA0, (int)hook_restore_select_screen);
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
	

	
	MakeCall(0x13FF04, (int)get_char_name);
	MakeCall(0x13FF14, (int)get_char_name);
	MakeCall(0x13FC38, (int)movelist_get_char_name);
	
	PatchShort(0x153994, TOTAL_CHARACTERS);
	PatchShort(0x1539C8, TOTAL_CHARACTERS);
	PatchShort(0x150698, TOTAL_CHARACTERS);
	PatchShort(0x1503A8, TOTAL_CHARACTERS);
	
	MakeCall(0x6F2A8, (int)hook_unk_func);
	MakeCall(0x6F2CC, (int)hook_unk_func);
	MakeCall(0x6F6A8, (int)hook_unk_func);
	MakeCall(0x6F584, (int)unk_load_ssf);
	MakeCall(0x6F3E8, (int)unk_load_ssf);
	MakeCall(0x6F3F4, (int)unk_load_script_data);
	
	
	MakeCall(0x153B00, (int)custom_load_ssf_alt);
	MakeCall(0x153B1C, (int)custom_load_ssf);
	MakeCall(0x1506A8, (int)custom_load_ssf_async);
	MakeCall(0x150730, (int)custom_load_ssf_async);
	
	MakeCall(0x70990, (int)custom_create_player);
	MakeCall(0xBCE4C, (int)custom_create_player);
	MakeCall(0x14EFAC, (int)custom_create_player);
	MakeCall(0x14EFC0, (int)custom_create_player);


	
	MakeCall(0x150424, (int)custom_load_script_data);
	MakeCall(0x1506B4, (int)custom_load_script_data_async);
	
	MakeCall(0x16824C, (int)player1_name);
	MakeCall(0x16836C, (int)player2_name);
	MakeCall(0x82B04,  (int)set_win_name);


	MakeCall(0xC0CFC, (int)hook_render);
	MakeCall(0xC0D2C, (int)hook_render);


	patch_stage_data();
	MakeCall(0x24BEC, (int)hook_stage_lock_status);
	MakeCall(0xBD318, (int)hook_stage_lock_status);
	MakeCall(0x160E4C, (int)hook_stage_lock_status);
	


	MakeCall(0x7F7FC, (int)play_kon_music);


	return 0;

}



int OnModuleStart(SceModule2* mod) {
	char* modname = mod->modname;

	if (strcmp(modname, TARGET_GAME) == 0) {
		mod_text_addr = mod->text_addr;

		int ret = Init(mod_text_addr);
		if (ret != 0)
			return -1;

		sceKernelDcacheWritebackAll();
		sceKernelIcacheClearAll();
	}
	if (!previous)
		return 0;

	return previous(mod);
}


int module_start(SceSize argc, void* argp) {

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
				if (strcmp(info.name, TARGET_GAME) == 0) {

					mod_text_addr = info.text_addr;

					int ret = Init(mod_text_addr);
					if (ret != 0)
						return;

					sceKernelDcacheWritebackAll();
					sceKernelIcacheClearAll();
					return;
				}
			}
		}
	}
	else {
		previous = sctrlHENSetStartModuleHandler(OnModuleStart); // PSP
	}


	return 0;
}