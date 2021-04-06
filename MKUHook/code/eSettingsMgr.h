#pragma once


struct settings {
	char bUsePuzzleModifierInNormalGame;
	int iForceShujinkoModel;
};

void SettingsMgr_Init();
struct settings SettingsMgr_Get();