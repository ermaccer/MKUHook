#include "mkuplrinfo.h"
#include "eLog.h"
#include "mkdeception.h"
#include "pspmem.h"
#include "eSettingsMgr.h"

int last_created_player = PLAYER1;
int last_saved_char_id = PLAYER1;


struct mk_toc_entry kano_toc[] = {
	{"",0,0 },
	{"",0,483968},
	{"",0,483968},
	{"",0,145792},
	{"",0,2688},
	{"",0,21600},
	{"",0,12224},
	{"",0,16032},
	{"",0,9600},
	{"",0,14592},
	{"",0,9600},
	{"",0,15424},
	{"",0,9600},
	{"",0,27008},
	{"",0,52352},
	{"",0,170496},
	{"",0,195328},
	{"",0,222208},
	{0,0,0}

};

struct mk_toc_entry psel_toc[] = {
	{"",0,0 },
	{"",0,483968},
	{"",0,483968},
	{"",0,145792},
	{"",0,2688},
	{"",0,21600},
	{"",0,12224},
	{"",0,16032},
	{"",0,9600},
	{"",0,14592},
	{"",0,9600},
	{"",0,15424},
	{"",0,9600},
	{"",0,27008},
	{"",0,52352},
	{"",0,170496},
	{"",0,195328},
	{"",0,222208},
	{0,0,0}

};


struct mk_file_entry kano_file_entry_table[] = {
	{"mkda_kano.ssf"	,0, 4},
	{"mkda_kano.sec"	,0, 1},
	{"mkda_kano_ap.sec"	,0, 1},
	{"sh_mkda_kano.sec"	,0, 1},
	{"mkda_kano.mko"	,0, 3},
	{"blood_fx.mko"	,0	,3},
	{"fight_fx.mko"	,0	,3},
	{"karate.mko"	,0	,3},
	{"style_karate.sec"	,0,1 },
	{"jeetkunedo.mko"	,0, 3},
	{"style_jeet_kun_do.sec",0,1 },
	{"nunchaku.mko"	,0, 3},
	{"style_nunchaku.sec", 0,1 },
	{"kano_anims.sec"	,0, 2},
	{"pz_jax_anims.sec"	,0, 2},
	{"karate_anims.sec"	,0, 2},
	{"jeetkunedo_anims.sec"	,0, 2},
	{"nunchaku_anims.sec"	,0, 2},

};

struct mk_toc_entry kano_file_table[] = {
		{&kano_file_entry_table[0]	,0,0 },
		{&kano_file_entry_table[1]	,0,483968},
		{&kano_file_entry_table[2]	,0,483968},
		{&kano_file_entry_table[3]	,0,145792},
		{&kano_file_entry_table[4]	,0,2688},
		{&kano_file_entry_table[5]	,0,21600},
		{&kano_file_entry_table[6]	,0,12224},
		{&kano_file_entry_table[7]	,0,16032},
		{&kano_file_entry_table[8]	,0,9600},
		{&kano_file_entry_table[9]	,0,14592},
		{&kano_file_entry_table[10]	,0,9600},
		{&kano_file_entry_table[11]	,0,15424},
		{&kano_file_entry_table[12]	,0,9600},
		{&kano_file_entry_table[13]	,0,27008},
		{&kano_file_entry_table[14]	,0,52352},
		{&kano_file_entry_table[15]	,0,170496},
		{&kano_file_entry_table[16]	,0,195328},
		{&kano_file_entry_table[17]	,0,222208},
		{0,0,0}
};


struct mk_file_entry mokap_file_entry_table[] = {
	{"mkda_mokap.ssf"	,0, 4},
	{"mkda_mokap.sec"	,0, 1},
	{"mkda_mokap_ap.sec"	,0, 1},
	{"sh_mkda_mokap.sec"	,0, 1},
	{"mkda_mokap.mko"	,0, 3},
	{"blood_fx.mko"	,0	,3},
	{"fight_fx.mko"	,0	,3},
	{"karate.mko"	,0	,3},
	{"style_karate.sec"	,0,1 },
	{"jeetkunedo.mko"	,0, 3},
	{"style_jeet_kun_do.sec",0,1 },
	{"nunchaku.mko"	,0, 3},
	{"style_nunchaku.sec", 0,1 },
	{"mokap_anims.sec"	,0, 2},
	{"pz_jax_anims.sec"	,0, 2},
	{"karate_anims.sec"	,0, 2},
	{"jeetkunedo_anims.sec"	,0, 2},
	{"nunchaku_anims.sec"	,0, 2},

};

struct mk_toc_entry mokap_file_table[] = {
		{&mokap_file_entry_table[0]		,0,0 },
		{&mokap_file_entry_table[1]		,0,498304},
		{&mokap_file_entry_table[2]		,0,498304},
		{&mokap_file_entry_table[3]		,0,145792},
		{&mokap_file_entry_table[4]		,0,2720},
		{&mokap_file_entry_table[5]		,0,21600},
		{&mokap_file_entry_table[6]		,0,12224},
		{&mokap_file_entry_table[7]		,0,16032},
		{&mokap_file_entry_table[8]		,0,9600},
		{&mokap_file_entry_table[9]		,0,14592},
		{&mokap_file_entry_table[10]	,0,9600},
		{&mokap_file_entry_table[11]	,0,15424},
		{&mokap_file_entry_table[12]	,0,9600},
		{&mokap_file_entry_table[13]	,0,21120},
		{&mokap_file_entry_table[14]	,0,52352},
		{&mokap_file_entry_table[15]	,0,170496},
		{&mokap_file_entry_table[16]	,0,195328},
		{&mokap_file_entry_table[17]	,0,222208},
		{0,0,0}
};



struct char_info_entry	pCharTable[] = {
	{"SCORPION"	, 0x8B05CA4	, 0x8B05DD0	,"scorpion.mko"},
	{"BARAKA"	, 0x8B00560	, 0x8B00698	,"baraka.mko"},
	{"NOOB"	, 0x8B055B4	, 0x8B05680	,"noob.mko"},
	{"SUB-ZERO"	, 0x8B06EB0	, 0x8B06FE8	,"subzero.mko"},
	{"MILEENA"	, 0x8B03F74	, 0x8B040AC	,"mileena.mko"},
	{"NIGHTWOLF"	, 0x8B05308	, 0x8B05440	,"nightwolf.mko"},
	{"ERMAC"	, 0x8B014D8	, 0x8B0161C	,"ermac.mko"},
	{"ASHRAH"	, 0x8B0023C	, 0x8B00374	,"ashrah.mko"},
	{"SINDEL"	, 0x8B06694	, 0x8B067CC	,"sindel.mko"},
	{"LI MEI"	, 0x8B03944	, 0x8B0380C	,"limei.mko"},
	{"BO' RAI CHO"	, 0x8B00A40	, 0x8B00B78	,"boraicho.mko"},
	{"HOTARU"	, 0x8B01FB8	, 0x8B020F0	,"hotaru.mko"},
	{"KENSHI"	, 0x8B02BE8	, 0x8B02D20	,"kenshi.mko"},
	{"SMOKE"	, 0x8B06C10	, 0x8B06D0C	,"smoke.mko"},
	{"HAVIK"	, 0x8B06964	, 0x8B06A9C	,"skab.mko"},
	{"TANYA"	, 0x8B071BC	, 0x8B072F4	,"tanya.mko"},
	{"LIU KANG"	, 0x8B03C5C	, 0x8B03B24	,"liukang.mko"},
	{"GHOST"	, 0x8B03D94	, 0x8B03D94	,"liukang_ghost.mko"},
	{"KIRA"	, 0x8B02EDC	, 0x8B03014	,"kira.mko"},
	{"KABAL"	, 0x8B028E8	, 0x8B02A20	,"kabal.mko"},
	{"KOBRA"	, 0x8B034E8	, 0x8B03620	,"kobra.mko"},
	{"JADE"	, 0x8B022DC	, 0x8B02414	,"jade.mko"},
	{"DAIROU"	, 0x8B0107C	, 0x8B011B4	,"dairou.mko"},
	{"RAIDEN"	, 0x8B05A04	, 0x8B05B3C	,"raiden.mko"},
	{"DARRIUS"	, 0x8B00D58	, 0x8B00E90	,"cassius.mko"},
	{"SHUJINKO"	, 0x8B06268	, 0x8B063A0	,"shujinko.mko"},
	{"SHUJINKO"	, 0x8B064E4	, 0x8B064E4	,"shujinko_13.mko"},
	{"NOOB - SMOKE"	, 0x8B058D8	, 0x8B057B8	,"noobsmoke.mko"},
	{"MONSTER"	, 0x8B017CC	, 0x8B017CC	,"freak.mko"},
	{"ONAGA"	, 0x8B01340	, 0x8B01340	,"dragonking.mko"},
	{"GORO"	, 0x8B01CAC	, 0x8B01DD8	,"goro.mko"},
	{"SHAO KAHN"	, 0x8B05FB0	, 0x8B060DC	,"shaokahn.mko"},
	{"FROST"	, 0x8B01994	, 0x8B01ACC	,"frost.mko"},
	{"KITANA"	, 0x8B031DC	, 0x8B03308	,"kitana.mko"},
	{"JAX"	, 0x8B025E8	, 0x8B02714	,"jax.mko"},
	{"BLAZE"	, 0x8B0086C	, 0x8B0086C	,"blaze.mko"},
	{"RANDOM"	, 0x8B05FB0	, 0x8B060DC	,"shaokahn.mko"},
	{"JAX"	, 0x8B04688	, 0x8B04790	,"mkda_jax.mko"},
	{"RAIDEN"	, 0x8B04EC4	, 0x8B04EC4	,"mkda_rayden.mko"},
	{"QUAN CHI"	, 0x8B04D08	, 0x8B04D08	,"mkda_quanchi.mko"},
	{"KUNG LAO"	, 0x8B04A64	, 0x8B04A64	,"mkda_kunglao.mko"},
	{"JOHNNY CAGE"	, 0x8B0431C	, 0x8B0431C	,"mkda_cage.mko"},
	{"SONYA"	, 0x8B05164	, 0x8B05164	,"mkda_sonya.mko"},
	{"NITARA"	, 0x8B04BB8	, 0x8B04BB8	,"mkda_nitara.mko"},
	{"SHANG TSUNG"	, 0x8B05038	, 0x8B05038	,"mkda_shang.mko"},
	{"FROST"	, 0x8B04568	, 0x8B04568	,"mkda_frost.mko"},
	{"KITANA"	, 0x8B048CC	, 0x8B048CC	,"mkda_kitana.mko"},
	{"DRAHMIN"	, 0x8B0446C	, 0x8B0446C	,"mkda_drahmin.mko"},
	{"BLAZE"	, 0x8B041F0	, 0x8B041F0	,"mkda_blaze.mko"},
	// new characters 
	{"MOKAP"	,	(int)&mokap_file_table	, (int)&mokap_file_table		,"mkda_mokap.mko"},
	{"KANO"	,		(int)&kano_file_table	, (int)&kano_file_table		,	 "mkda_kano.mko"},



};

void dump_char_table(unsigned int addr)
{

	int select_addr = addr + 0x311AA8;
	char msgBuffer[1256];
	for (int i = 0; i < 49; i++)
	{
		struct  char_info_entry chr = *(struct char_info_entry*)(select_addr + (sizeof(struct char_info_entry) * i));
		sprintf(msgBuffer, "{\"%s\"\t, 0x%X\t, 0x%X\t,\"%s\"},\n",
			chr.name,
			chr.file_table,
			chr.alt_file_table,
			chr.scriptName);
		LOG_Message(msgBuffer);
	}
}

void read_char_table()
{
}

char * get_char_name(int id)
{
	int p1_selbox_pos = ReadInt(0x4173B0);
	int p2_selbox_pos = ReadInt(0x4173B4);
	int charID;
	char *result;

	charID = -1;
	if (id)
	{
		if (id == 1)
			charID = p2_selbox_pos;
	}
	else
		charID = p1_selbox_pos;


	if (charID >= 0 && charID < TOTAL_CHARACTERS)
		result = pCharTable[translate_id_from_pz(charID)].name;
	else
		result = 0;

	return result;
}

char * movelist_get_char_name()
{
	int who_paused = ReadInt(0x58EB08);
	int p1_id = ReadInt(PLAYER1_ADDR + 0x54);
	int p2_id = ReadInt(PLAYER2_ADDR + 0x54);

	if (who_paused == PLAYER2)
		return pCharTable[p2_id].name;
	else
		return pCharTable[p1_id].name;

}

int custom_create_player(int plr, struct player_info * obj)
{
	last_created_player = plr;
	return hook_create_player(plr,obj);
}

void custom_load_ssf(struct mem_ssf_header * ptr)
{
	int p1_id = ReadInt(PLAYER1_ADDR + 0x54);
	int p2_id = ReadInt(PLAYER2_ADDR + 0x54);

	if (last_created_player == PLAYER2)
		load_ssf((struct mem_ssf_header*)pCharTable[p2_id].file_table);
	else
		load_ssf((struct mem_ssf_header*)pCharTable[p1_id].file_table);


}

void custom_load_ssf_async(struct mem_ssf_header * ptr)
{
	int async_proc_data = ReadInt(0x58F6B4);
	int scriptID = *(int*)(async_proc_data + 8);
	int charID = *(int*)(async_proc_data + 12);
	int flags = *(int*)(async_proc_data + 16);

	if (flags & 1)
		load_ssf(pCharTable[charID].alt_file_table);
	else
		load_ssf(pCharTable[charID].file_table);
}

void custom_load_ssf_alt(struct mem_ssf_header* ptr)
{
	int p1_id = ReadInt(PLAYER1_ADDR + 0x54);
	int p2_id = ReadInt(PLAYER2_ADDR + 0x54);

	if (last_created_player == PLAYER2)
		load_ssf((struct mem_ssf_header*)pCharTable[p2_id].alt_file_table);
	else
		load_ssf((struct mem_ssf_header*)pCharTable[p1_id].alt_file_table);


}

int custom_load_script_data(int id, char * name)
{
	int p1_id = ReadInt(PLAYER1_ADDR + 0x54);
	int p2_id = ReadInt(PLAYER2_ADDR + 0x54);

	if (last_created_player == PLAYER2)
		return load_script_data(id, pCharTable[p2_id].scriptName);
	else
		return load_script_data(id, pCharTable[p1_id].scriptName);
}

int custom_load_script_data_async(int id, char * name)
{
	int async_proc_data = ReadInt(0x58F6B4);
	int scriptID = *(int*)(async_proc_data + 8);
	int charID = *(int*)(async_proc_data + 12);
	int flags = *(int*)(async_proc_data + 16);


	return load_script_data(id,pCharTable[charID].scriptName);
}

int player1_name(int id, int font, char * text, int x, int y, int unk)
{
	int p1_id = ReadInt(PLAYER1_ADDR + 0x54);
	return string_left_xy(id, font, pCharTable[p1_id].name, x, y, unk);
}

int player2_name(int id, int font, char * text, int y, int x, int unk)
{
	int p2_id = ReadInt(PLAYER2_ADDR + 0x54);
	return string_right_xy(id, font, pCharTable[p2_id].name, y, x, unk);
}

void set_win_name(char * buf, char * format, char * name)
{
	int round_winner = ReadInt(0x2F3D04);

	int p1_id = ReadInt(PLAYER1_ADDR + 0x54);
	int p2_id = ReadInt(PLAYER2_ADDR + 0x54);

	if (round_winner == 2)
		sprintf(buf, format, pCharTable[p2_id].name);
	else
		sprintf(buf, format, pCharTable[p1_id].name);


}

void hook_unk_func(int unk, int id)
{
	last_saved_char_id = id;
	func_6F388(unk, id);
}

void unk_load_ssf(struct mem_ssf_header * ptr)
{
	load_ssf((struct mem_ssf_header*)pCharTable[last_saved_char_id].alt_file_table);
}

int unk_load_script_data(int id, char * name)
{
	return load_script_data(id, pCharTable[last_saved_char_id].scriptName);
}

void calculate_custom_toc()
{
	// from toceditor

	// KANO
	for (int i = 0; i < 18; i++)
	{
		kano_file_entry_table[i].belong = &kano_file_table;
	}

	int baseSize = 2048;
	for (int i = 1; i < 18; i++)
	{
		kano_file_table[i].previousSize = baseSize;
		baseSize += (kano_file_table[i].size + 2048 - 1) & -2048;

	}

	// MOKAP
	for (int i = 0; i < 18; i++)
	{
		mokap_file_entry_table[i].belong = &mokap_file_table;
	}

	baseSize = 2048;
	for (int i = 1; i < 18; i++)
	{
		mokap_file_table[i].previousSize = baseSize;
		baseSize += (mokap_file_table[i].size + 2048 - 1) & -2048;

	}

	

}

