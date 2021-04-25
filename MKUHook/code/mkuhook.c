#include "mkuhook.h"
#include "eLog.h"
#include "mkstructs.h"
#include "pspmem.h"
#include "mkdeception.h"
#include "mkumenu.h"
#include <stdio.h>
int  bSwapStatus = 0;



struct select_screen_entry pSelectTableNew[] = {
	{MONSTER, 0	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "2"	, "HAPKIDO"	, "MOI FAH"	, "MUGAI RYU"},
	{ONAGA	, 0	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "1"	, "DRAGON"	, ""	, ""},
	{YOUNG_SHUJINKO	, 96	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "5"	, "MANTIS"	, "SHAOLIN FIST"	, "DAN TIEN DAO"},
	{MKDA_QUAN_CHI	, 0	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "4"	, "TANG SOO DO"	, "ESCRIMA"	, "BROADSWORD"},
	{MKDA_SHANG_TSUNG	, 0	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "3"	, "SNAKE"	, "MANTIS"	, ""},
	{MKDA_NITARA	, 0	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "5"	, "LEOPARD"	, "FU JOW PAI"	, "DRAGON TEETH"},
	{MKDA_SONYA	, 0	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "1"	, "KENPO"	, "TAE KWON DO"	, "KALI STICKS"},
	{MKDA_CAGE	, 0	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "3"	, "SHINTO RYU"	, "JEET KUNE DO"	, "NUNCHAKU"},
	{MKDA_KUNG_LAO	, 0	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "2"	, "MANTIS"	, "SHAOLIN FIST"	, "BROADSWORD"},
	{MKDA_DRAHMIN	, 0	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "5"	, ""	, ""	, "IRON CLUB"},
	{SMOKE	, 13	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "5"	, "MI TZU"	, ""	, ""},
	{NOOB	, 13	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "5"	, "MONKEY"	, ""	, ""},
	{GHOST	, 90	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM" , "body_scorpion_alt.sec"	, "5"	, "JUN FAN"	, "PAO CHUI"	, "NUNCHAKU"},
	{MKDA_RAIDEN	, 94	,	"HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM" , "body_scorpion_alt.sec"	, "4"	, "NAN CHUAN"	, "JUJUTSU"	, "STAFF"},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""},
	{MKDA_KANO	, 0	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "3"	, "SHINTO RYU"	, "JEET KUNE DO"	, "NUNCHAKU"},
	{MKDA_MOKAP	, 0	, "HEAD_RANDOM"	, "HEAD_RANDOM"	, "BODY_RANDOM"	, "body_scorpion_alt.sec"	, "3"	, "SHINTO RYU"	, "JEET KUNE DO"	, "NUNCHAKU"},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""},
	{RANDOM,0,"","","","","","","",""}


};


struct select_screen_entry pSelectTable[] = {
	{KENSHI	, 86	, "HEAD_KENSHI"	, "HEAD_KENSHI_LOCKED"	, "BODY_KENSHI"	, "body_kenshi_alt.sec"	, "4"	, "TAI CHI"	, "JUDO"	, "KATANA"},
	{JADE	, 84	, "HEAD_JADE"	, "HEAD_JADE_LOCKED"	, "BODY_JADE"	, "body_jade_alt.sec"	, "5"	, "FAN ZI"	, "KUO SHOU"	, "BOJUTSU"},
	{SCORPION	, 95	, "HEAD_SCORPION"	, "HEAD_SCORPION"	, "BODY_SCORPION"	, "body_scorpion_alt.sec"	, "2"	, "HAPKIDO"	, "MOI FAH"	, "MUGAI RYU"},
	{MILEENA	, 91	, "HEAD_MILEENA"	, "HEAD_SCORPION"	, "BODY_MILEENA"	, "body_mileena_alt.sec"	, "2"	, "YING YEUNG"	, "MIAN CHUAN"	, "SAI"},
	{GORO	, 103	, "HEAD_GORO"	, "HEAD_GORO"	, "BODY_GORO"	, "body_goro_alt.sec"	, "3"	, "SHOKAN"	, "KUATAN"	, "DRAGON FANGS"},
	{KITANA	, 7214	, "HEAD_KITANA"	, "HEAD_KITANA"	, "BODY_KITANA"	, "body_kitana_alt.sec"	, "4"	, "EAGLE CLAW"	, "BA GUA"	, "STEEL FAN"},
	{BARAKA	, 77	, "HEAD_BARAKA"	, "HEAD_SCORPION"	, "BODY_BARAKA"	, "body_baraka_alt.sec"	, "3"	, "SILAT"	, "HUNG GAR"	, "BLADES"},
	{SUBZERO	, 99	, "HEAD_SUBZERO"	, "HEAD_SCORPION"	, "BODY_SUBZERO"	, "body_subzero_alt.sec"	, "4"	, "SHOTOKAN"	, "DRAGON"	, "KORI BLADE"},
	{HAVIK	, 82	, "HEAD_HAVIK"	, "HEAD_SKAB_LOCKED"	, "BODY_HAVIK"	, "body_havik_alt.sec"	, "5"	, "SNAKE"	, "TANG SOO DO"	, "MORNING STAR"},
	{SINDEL	, 97	, "HEAD_SINDEL"	, "HEAD_SINDEL_LOCKED"	, "BODY_SINDEL"	, "body_sindel_alt.sec"	, "3"	, "ZHA CHUAN"	, "FU JOW PAI"	, "KWAN DO"},
	{RAIDEN	, 94	, "HEAD_RAIDEN"	, "HEAD_RAIDEN_LOCKED"	, "BODY_RAIDEN"	, "body_raiden_alt.sec"	, "4"	, "NAN CHUAN"	, "JUJUTSU"	, "STAFF"},
	{LI_MEI	, 89	, "HEAD_LIMEI"	, "HEAD_LIMEI_LOCKED"	, "BODY_LIMEI"	, "body_limei_alt.sec"	, "2"	, "MI ZONG"	, "LUI HE BA FA"	, "KUNLUN DAO"},
	{KABAL	, 85	, "HEAD_KABAL"	, "HEAD_KABAL_LOCKED"	, "BODY_KABAL"	, "body_kabal_alt.sec"	, "2"	, "SUN BIN"	, "GOJU RYU"	, "HOOK SWORDS"},
	{ERMAC	, 81	, "HEAD_ERMAC"	, "HEAD_SCORPION"	, "BODY_ERMAC"	, "body_ermac_alt.sec"	, "4"	, "HUA CHUAN"	, "CHOY LEE FUT"	, "AXE"},
	{BLAZE	, 7216	, "HEAD_BLAZE"	, "HEAD_BLAZE"	, "BODY_BLAZE"	, "body_blaze_alt.sec"	, "3"	, "HAPKIDO"	, "JEET KUNE DO"	, "XING YI"},
	{JAX, 7215	, "HEAD_JAX"	, "HEAD_JAX"	, "BODY_JAX"	, "body_jax_alt.sec"	, "2"	, "MUAY THAI"	, "JUDO"	, "TONFA"},
	{NIGHTWOLF	, 92	, "HEAD_NIGHTWOLF"	, "HEAD_SCORPION"	, "BODY_NIGHTWOLF"	, "body_nightwolf_alt.sec"	, "4"	, "VAL TUDO"	, "TAE KWAN DO"	, "TOMAHAWKS"},
	{BORAICHO	, 78	, "HEAD_BORAICHO"	, "HEAD_SCORPION"	, "BODY_BORAICHO"	, "body_boraicho_alt.sec"	, "4"	, "SUMO"	, "DRUNKEN FIST"	, "JOJUTSU"},
	{NOOBSMOKE	, 102	, "HEAD_SMOKENOOB"	, "HEAD_SMOKENOOB_LOCKED"	, "BODY_SMOKENOOB"	, "body_smokenoob_alt.sec"	, "5"	, "NOOB - MONKEY"	, "SMOKE - MI TZU"	, " "},
	{TANYA	, 100	, "HEAD_TANYA"	, "HEAD_TANYA_LOCKED"	, "BODY_TANYA"	, "body_tanya_alt.sec"	, "5"	, "ZI RAN MEN"	, "YUE CHUAN"	, "KOBU JUTSU"},
	{SHUJINKO	, 96	, "HEAD_SHUJINKO"	, "HEAD_SHUJINKO_LOCKED"	, "BODY_SHUJINKO"	, "body_shujinko_alt.sec"	, "5"	, "MANTIS"	, "SHAOLIN FIST"	, "DAN TIEN DAO"},
	{HOTARU	, 83	, "HEAD_HOTARU"	, "HEAD_HOTARU_LOCKED"	, "BODY_HOTARU"	, "body_hotaru_alt.sec"	, "1"	, "BA SHAN FAN"	, "PI GUA"	, "NAGINATA"},
	{ASHRAH	, 76	, "HEAD_ASHRAH"	, "HEAD_SCORPION"	, "BODY_ASHRAH"	, "body_ashrah_alt.sec"	, "5"	, "CHOU JAIO"	, "BA GUA"	, "KRISS"},
	{DAIROU	, 79	, "HEAD_DAIROU"	, "HEAD_DAIROU_LOCKED"	, "BODY_DAIROU"	, "body_dairou_alt.sec"	, "5"	, "WING CHUN"	, "ESCRIMA"	, "AUTUMN DAO"},
	{SHAO_KAHN	, 104	, "HEAD_SHAO_KAHN"	, "HEAD_SHAO_KAHN"	, "BODY_SHAO_KAHN"	, "body_shaokahn_alt.sec"	, "2"	, "TAI TZU"	, "LUI HE"	, "WRATH HAMMER"},
	{FROST	, 7217	, "HEAD_FROST"	, "HEAD_FROST"	, "BODY_FROST"	, "body_frost_alt.sec"	, "2"	, "TONG BEI"	, "YUAN YANG"	, "ICE DAGGERS"},
	{KOBRA	, 88	, "HEAD_KOBRA"	, "HEAD_KOBRA_LOCKED"	, "BODY_KOBRA"	, "body_kobra_alt.sec"	, "1"	, "SHORIN RYU"	, "KICKBOXING"	, "KALI STICKS"},
	{DARRIUS	, 80	, "HEAD_DARRIUS"	, "HEAD_SHINJINKO_LOCKED"	, "BODY_DARRIUS"	, "body_darrius_alt.sec"	, "5"	, "SHINTO RYU"	, "LEOPARD"	, "GAUNTLETS"},
	{KIRA	, 87	, "HEAD_KIRA"	, "HEAD_KIRA_LOCKED"	, "BODY_KIRA"	, "body_kira_alt.sec"	, "5"	, "XING YI"	, "KENPO"	, "DRAGON TEETH"},
	{LIU_KANG	, 90	, "HEAD_LIUKANG"	, "HEAD_LIUKANG_LOCKED"	, "BODY_LIUKANG"	, "body_liukang_alt.sec"	, "5"	, "JUN FAN"	, "PAO CHUI"	, "NUNCHAKU"},

};

int hook_character_lock_status(int id, int param)
{
	id = SCORPION;
	return is_char_locked(id, param);
}

void dump_select_screen(unsigned int addr)
{
	int select_addr = addr + 0x31235C;
	char msgBuffer[1256];
	for (int i = 0; i < 30; i++)
	{
		struct select_screen_entry sel = *(struct select_screen_entry*)(select_addr + (sizeof(struct select_screen_entry) * i));
		mk_sprintf(msgBuffer, "{%d\t, %d\t, \"%s\"\t, \"%s\"\t, \"%s\"\t, \"%s\"\t, \"%s\"\t, \"%s\"\t, \"%s\"\t, \"%s\"},\n",
			sel.characterID,
			sel.soundID,
			sel.headName,
			sel.headLockedName,
			sel.bodyName,
			sel.bodyArchiveName,
			sel.difficulty,
			sel.style1,
			sel.style2,
			sel.style3);
		LOG_Message(msgBuffer);
	}
}

void hook_new_select_table()
{
	bSwapStatus ^= 1;
	int select_addr = 0x31235C;
	char msgBuffer[1256];
	for (int i = 0; i < 30; i++)
	{
		int sel = (select_addr + (sizeof(struct select_screen_entry) * i));
		if (bSwapStatus)
		{
			PatchInt(sel + 0, pSelectTable[i].characterID);
			PatchInt(sel + 4, pSelectTable[i].soundID);
			PatchInt(sel + 8, (int)&pSelectTable[i].headName[0]);
			PatchInt(sel + 12, (int)&pSelectTable[i].headLockedName[0]);
			PatchInt(sel + 16, (int)&pSelectTable[i].bodyName[0]);
			PatchInt(sel + 20, (int)&pSelectTable[i].bodyArchiveName[0]);
			PatchInt(sel + 24, (int)&pSelectTable[i].difficulty[0]);
			PatchInt(sel + 28, (int)&pSelectTable[i].style1[0]);
			PatchInt(sel + 32, (int)&pSelectTable[i].style2[0]);
			PatchInt(sel + 36, (int)&pSelectTable[i].style3[0]);
			
		}
		else
		{
			PatchInt(sel + 0, pSelectTableNew[i].characterID);
			PatchInt(sel + 4, pSelectTableNew[i].soundID);
			PatchInt(sel + 8, (int)&pSelectTableNew[i].headName[0]);
			PatchInt(sel + 12, (int)&pSelectTableNew[i].headLockedName[0]);
			PatchInt(sel + 16, (int)&pSelectTableNew[i].bodyName[0]);
			PatchInt(sel + 20, (int)&pSelectTableNew[i].bodyArchiveName[0]);
			PatchInt(sel + 24, (int)&pSelectTableNew[i].difficulty[0]);
			PatchInt(sel + 28, (int)&pSelectTableNew[i].style1[0]);
			PatchInt(sel + 32, (int)&pSelectTableNew[i].style2[0]);
			PatchInt(sel + 36, (int)&pSelectTableNew[i].style3[0]);
		}


	}
	refresh_screen();

}

void restore_select_screen()
{
	int select_addr = 0x31235C;
	for (int i = 0; i < 30; i++)
	{
		int sel = (select_addr + (sizeof(struct select_screen_entry) * i));
		PatchInt(sel + 0, pSelectTable[i].characterID);
		PatchInt(sel + 4, pSelectTable[i].soundID);
		PatchInt(sel + 8, (int)&pSelectTable[i].headName[0]);
		PatchInt(sel + 12, (int)&pSelectTable[i].headLockedName[0]);
		PatchInt(sel + 16, (int)&pSelectTable[i].bodyName[0]);
		PatchInt(sel + 20, (int)&pSelectTable[i].bodyArchiveName[0]);
		PatchInt(sel + 24, (int)&pSelectTable[i].difficulty[0]);
		PatchInt(sel + 28, (int)&pSelectTable[i].style1[0]);
		PatchInt(sel + 32, (int)&pSelectTable[i].style2[0]);
		PatchInt(sel + 36, (int)&pSelectTable[i].style3[0]);

	}
}

int hook_restore_select_screen(int id, int unk, int func, int unk2, int unk3)
{
	restore_select_screen();
	refresh_screen();
	return create_mkproc(id, unk, func, unk2, unk3);
}

int hook_load_graphics(int slot, int id, char * name, int orientation, int x, int y, int unk)
{

	char data[256];
	mk_sprintf(data,"%x %d %s %d %d %d %d\n", slot, id, name, orientation, x, y, unk);
	LOG_Message(data);
	//orientation = 0;
	//name = "";

	return load_named_2d_pfxobj_xy(slot, id, name, orientation, x, y, unk);
}

void hook_custom_player_select()
{
	//p_pselect();
}

void custom_rendering()
{
	process_render();

}
