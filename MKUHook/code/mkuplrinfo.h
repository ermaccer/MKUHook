#pragma once
#include "ssf.h"
#include "mkstructs.h"

struct char_info_entry {
	char* name;
	int*  file_table;
	int*  alt_file_table;
	char* scriptName;
};

void dump_char_table(unsigned int addr);
void read_char_table();

extern struct char_info_entry	pCharTable[];

//58F6B4
char* get_char_name(int id);
char* movelist_get_char_name();
int	  custom_create_player(int plr, struct player_info* obj);
void  custom_load_ssf(struct mem_ssf_header* ptr);
void  custom_load_ssf_async(struct mem_ssf_header* ptr);
void  custom_load_ssf_alt(struct mem_ssf_header* ptr);
int   custom_load_script_data(int id, char* name);
int   custom_load_script_data_async(int id, char* name);
int  player1_name(int id, int font, char* text, int y, int x, int unk);
int  player2_name(int id, int font, char* text, int y, int x, int unk);
void set_win_name(char* buf, char* format, char* name);


void hook_unk_func(int unk, int id);
void  unk_load_ssf(struct mem_ssf_header* ptr);
int	  unk_load_script_data(int id, char* name);
void calculate_custom_toc();