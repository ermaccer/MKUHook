#pragma once
#include "mkstructs.h"
#include "ssf.h"


enum PLAYER_NUM
{
	INVALID_PLAYER_NUM = -1,
	PLAYER1,
	PLAYER2,
};





#define PLAYER1_OBJ   0x8D929AC
#define PLAYER2_OBJ   0x8D92A18
#define PLAYER1_ADDR  0x58E9AC
#define PLAYER2_ADDR  0x58EA18
#define KONQUEST_INFO 0x2FAE40






// system
void(*mk_sprintf)(char* ptr, char* fmt, ...);


//file
void(*load_ssf)(struct mem_ssf_header* ssf);
void(*load_font)(int id);
int(*load_script_data)(int id, char* name);
void(*func_6F388)(int unk, int id);

// proc
void(*p_pselect)();
void(*p_game_loop)();
int(*create_mkproc)(int id, int unk, int func, int unk2, int unk3);
void(*gamelogic_jump)(int mode, int function);


// screen
void(*fire_screen_event)(int id, int param);
void(*refresh_screen)();
void(*wait_for_screen_close)();

int(*load_named_2d_pfxobj_xy)(int slot, int id, char* name, int orientation, int x, int y, int unk);


// misc
int(*string_right_xy)(int id, int font, char* text, int y, int x, int unk);
int(*string_left_xy)(int id, int font, char* text, int y, int x, int unk);
int(*load_hero_model)(int ptr);
int(*create_plr)(int plr, struct player_info* obj);
int(*is_char_locked)(int id, int param);
int(*translate_id_from_pz)(int id);

// core

void(*process_render)();


void(*impale_player)();





void MKDeception_Init(unsigned int addr);



// hooks
int hook_load_hero_model(int ptr);
int hook_create_player(int plr, struct player_info* obj);