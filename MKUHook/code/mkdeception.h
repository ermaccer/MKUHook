#pragma once
#include "mkstructs.h"


enum PLAYER_NUM
{
	INVALID_PLAYER_NUM = -1,
	PLAYER1,
	PLAYER2,
};





#define PLAYER1_OBJ   0x8D929AC
#define PLAYER2_OBJ   0x8D92A18
#define KONQUEST_INFO 0x2FAE40




void(*mk_sprintf)(char* ptr, char* fmt, ...);
int(*load_hero_model)(int ptr);
int(*create_plr)(int plr, struct player_info* obj);
void(*p_game_loop)();
void(*load_font)(int id);
void(*string_right_xy)(int id, int font, char* text, int y, int x, int unk);
void(*wait_for_screen_close)();
void(*gamelogic_jump)(int mode, int function);
void(*p_pselect)(int arg);
void(*fire_screen_event)(int id, int param);
int(*is_char_locked)(int id, int param);
int(*create_mkproc)(int id, int unk, int func, int unk2, int unk3);
void(*refresh_screen)();
void MKDeception_Init(unsigned int addr);



// hooks
int hook_load_hero_model(int ptr);
int hook_create_player(int plr, struct player_info* obj);
void hook_draw_menu();