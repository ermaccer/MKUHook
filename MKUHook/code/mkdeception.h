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
int(*is_bgnd_locked)(int id);
int(*translate_id_from_pz)(int id);
void(*snd_req)(int id);
int(*set_music)(int id);
void(*sub_7F050)();
int(*randu)(int range);
int(*bgnd_unhide_sobj)(int id);

char*(*get_string_by_id)(int id);
// core

void(*render)();
int(*get_game_state)();
int get_game_tick();
int(*pressed_button)(int plr, int id);

void(*impale_player)();

// rw
int(*RwRasterCreate)(int x, int y, int bits, int mode);


enum pad_button {
	PAD_L2,
	PAD_R2,
	PAD_L1,
	PAD_R1,
	PAD_TRIANGLE,
	PAD_CIRCLE,
	PAD_CROSS,
	PAD_SQUARE,
	PAD_SELECT,
	PAD_L3,
	PAD_R3,
	PAD_START,
	PAD_UP,
	PAD_RIGHT,
	PAD_DOWN,
	PAD_LEFT,
	PAD_ANY,
	PAD_L2R2,
};

enum game_state {
	STATE_0,
	STATE_1,
	STATE_2,
	STATE_ATTRACT,
	STATE_SELECT,
	STATE_5,
	STATE_6,
	STATE_GAME,
	STATE_8,
	STATE_MENU,
};



void MKDeception_Init(unsigned int addr);



// hooks
int hook_load_hero_model(int ptr);
int hook_create_player(int plr, struct player_info* obj);