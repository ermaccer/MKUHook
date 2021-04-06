#include "mkdeception.h"
#include "pspmem.h"
#include "eSettingsMgr.h"
#include "eLog.h"
#include <string.h>
#include <stdio.h>

char msgBuff[256];


void MKDeception_Init(unsigned int addr)
{

	mk_sprintf =				(void *)(addr + 0x248048);
	load_hero_model =			(void *)(addr + 0x1C0380);
	create_plr =				(void *)(addr + 0x153960);
	p_game_loop =		    	(void *)(addr + 0x5FC1C);
	string_right_xy =		    (void *)(addr + 0x796A4);
	load_font=				    (void *)(addr + 0x7941C);
	wait_for_screen_close =     (void *)(addr + 0x1335EC);
	gamelogic_jump =			(void *)(addr + 0x7F924);
	p_pselect =					(void *)(addr + 0x162C6C);
	fire_screen_event =			(void*)(addr + 0x1343B0);
	is_char_locked =			(void*)(addr + 0x16167C);
	create_mkproc=				(void*)(addr + 0x15FA4C);
	refresh_screen =			(void*)(addr + 0x1338B4);
	LOG_Message("INFO: MKDeception_Init()\n");
}

int hook_load_hero_model(int ptr)
{

	int p_konquest_info = ReadInt(KONQUEST_INFO);

	if (!(SettingsMgr_Get().iForceShujinkoModel == 100))
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
	mk_sprintf(msgBuff, "INFO: Loading player %d character %d\n", plr,obj->characterID);
	LOG_Message(msgBuff);

	return create_plr(plr, obj);
}


void hook_draw_menu()
{
	wait_for_screen_close();
}
