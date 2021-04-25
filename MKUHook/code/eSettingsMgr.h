#pragma once


struct settings {
	int bUsePuzzleModifierInNormalGame;
	int bHideFighterFaceInLifebar;
	int iForceShujinkoModel;
};

void SettingsMgr_Init();
struct settings SettingsMgr_Get();