#pragma once


struct settings {
	int bUsePuzzleModifierInNormalGame;
	int bHideFighterFaceInLifebar;
	int iForceShujinkoModel;
	int bUseImagesForExtraSelectScreen;
};

void SettingsMgr_Init();
struct settings SettingsMgr_Get();