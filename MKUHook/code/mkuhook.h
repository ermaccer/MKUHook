#pragma once
#include "ssf.h"

int hook_character_lock_status(int id, int param);
void dump_select_screen(unsigned int addr);
void hook_new_select_table();
void restore_select_screen();
int hook_restore_select_screen(int id, int unk, int func, int unk2, int unk3);
int hook_load_graphics(int slot, int id, char* name, int orientation, int x, int y, int unk);

void hook_custom_player_select();
void custom_rendering();

void process_select_switch();

