#pragma once
#include "ssf.h"
#include "stage.h"

#define SELECT_SCREEN_SWAP_SOUND 6985
#define SELECT_SCREEN_ALT_PAL_SOUND 6951

int hook_character_lock_status(int id, int param);
int hook_stage_lock_status(int id);

void dump_select_screen(unsigned int addr);
void hook_new_select_table(int status);
void restore_select_screen();
int hook_restore_select_screen(int id, int unk, int func, int unk2, int unk3);

void hook_custom_player_select();
void hook_render();
void process_mkuhook();


extern int toggle_palette;

void process_select_switch(int status);
void process_palette_toggle();

