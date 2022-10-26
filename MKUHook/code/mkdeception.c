#include "mkdeception.h"
#include "pspmem.h"
#include "eSettingsMgr.h"
#include "eLog.h"
#include "mkuhook.h"
#include <string.h>
#include <stdio.h>

char msgBuff[256];


int get_game_tick()
{
	return ReadInt(0x58EEC4);
}

void MKDeception_Init(unsigned int addr)
{
	mk_sprintf =				(void *)(addr + 0x248048);
	load_hero_model =			(void *)(addr + 0x1C0380);
	create_plr =				(void *)(addr + 0x153960);
	p_game_loop =		    	(void *)(addr + 0x5FC1C);
	string_right_xy =		    (void *)(addr + 0x796A4);
	string_left_xy =			(void *)(addr + 0x79624);
	load_font=				    (void *)(addr + 0x7941C);
	wait_for_screen_close =     (void *)(addr + 0x1335EC);
	gamelogic_jump =			(void *)(addr + 0x7F924);
	p_pselect =					(void *)(addr + 0x162C6C);
	fire_screen_event =			(void*)(addr + 0x1343B0);
	is_char_locked =			(void*)(addr + 0x16167C);
	is_bgnd_locked =			(void*)(addr + 0x24CD8);
	create_mkproc=				(void*)(addr + 0x15FA4C);
	refresh_screen =			(void*)(addr + 0x1338B4);
	load_ssf =					(void*)(addr + 0x10FB08);
	load_named_2d_pfxobj_xy =	 (void*)(addr + 0x84B04);
	impale_player =				(void*)(addr + 0x64378);
	translate_id_from_pz =      (void*)(addr + 0x15F87C);
	func_6F388 = (void*)(addr + 0x6F388);
	load_script_data = (void*)(addr + 0x10E438);
	render = (void*)(addr + 0x62460);
	get_game_state = (void*)(addr + 0x1AA794);
	snd_req = (void*)(addr + 0x1A5A68);
	get_string_by_id = (void*)(addr + 0x10F4B4);
	RwRasterCreate = (void*)(addr + 0x294A98);
	set_music = (void*)(addr + 0x9FD1C);
	sub_7F050 = (void*)(addr + 0x7F050);
	randu = (void*)(addr + 0x1AA9F0);
	bgnd_unhide_sobj = (void*)(addr + 0x18630);
	pressed_button = (void*)(addr + 0x8739C);
}

int hook_load_hero_model(int ptr)
{
	int p_konquest_info = ReadInt(KONQUEST_INFO);

	if (!(SettingsMgr_Get().iForceShujinkoModel == -1))
	{
		if (SettingsMgr_Get().iForceShujinkoModel <= 4)
			*(char*)(p_konquest_info + 92) = SettingsMgr_Get().iForceShujinkoModel;
	}


	mk_sprintf(msgBuff, "INFO: Loading player konquest model: %d\n", *(char*)(p_konquest_info + 92));

	LOG_Message(msgBuff);

	return load_hero_model(ptr);
}

int hook_create_player(int plr, struct player_info* obj)
{
	mk_sprintf(msgBuff, "INFO: Loading player %d character %d alt: %x\n", plr,obj->characterID, ReadInt(0x4173CC));
	LOG_Message(msgBuff);
	if (plr == PLAYER1 && toggle_palette)
	{
		int is_alt = 0;
		if (ReadInt(0x4173CC))
			is_alt = 1;
		obj->flags |= is_alt | 2;
	}

	return create_plr(plr, obj);
}

