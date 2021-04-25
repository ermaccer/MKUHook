#pragma once

enum characters {
	SCORPION,
	BARAKA,
	NOOB,
	SUBZERO,
	MILEENA,
	NIGHTWOLF,
	ERMAC,
	ASHRAH,
	SINDEL,
	LI_MEI,
	BORAICHO,
	HOTARU,
	KENSHI,
	SMOKE,
	HAVIK,
	TANYA,
	LIU_KANG,
	GHOST,
	KIRA,
	KABAL,
	KOBRA,
	JADE,
	DAIROU,
	RAIDEN,
	DARRIUS,
	SHUJINKO,
	YOUNG_SHUJINKO,
	NOOBSMOKE,
	MONSTER,
	ONAGA,
	GORO,
	SHAO_KAHN,
	FROST,
	KITANA,
	JAX,
	BLAZE,
	RANDOM,
	MKDA_JAX,
	MKDA_RAIDEN,
	MKDA_QUAN_CHI,
	MKDA_KUNG_LAO,
	MKDA_CAGE,
	MKDA_SONYA,
	MKDA_NITARA,
	MKDA_SHANG_TSUNG,
	MKDA_FROST,
	MKDA_KITANA,
	MKDA_DRAHMIN,
	MKDA_BLAZE,
	// new
	MKDA_MOKAP,
	MKDA_KANO,
	TOTAL_CHARACTERS
};

struct player_info
{
	int field_0;
	int field_4;
	int selected;
	float field_C;
	char field_10;
	char field_11;
	char field_12;
	char field_13;
	int flags;
	int field_18;
	char field_1C;
	char field_1D;
	char field_1E;
	char field_1F;
	char field_20;
	char field_21;
	char field_22;
	char field_23;
	char field_24;
	char field_25;
	char field_26;
	char field_27;
	char field_28;
	char field_29;
	char field_2A;
	char field_2B;
	char field_2C;
	char field_2D;
	char field_2E;
	char field_2F;
	char field_30;
	char field_31;
	char field_32;
	char field_33;
	char field_34;
	char field_35;
	char field_36;
	char field_37;
	char field_38;
	char field_39;
	char field_3A;
	char field_3B;
	char field_3C;
	char field_3D;
	char field_3E;
	char field_3F;
	int field_40;
	int winCount;
	int field_48;
	int field_4C;
	int field_50;
	int characterID;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
};

struct select_screen_entry {
	int characterID;
	int soundID;
	char* headName;
	char* headLockedName;
	char* bodyName;
	char* bodyArchiveName;
	char* difficulty;
	char* style1;
	char* style2;
	char* style3;
};

struct mk_toc_entry {
	struct mk_file_entry* entry;
	int  previousSize;
	int  size;
};

struct mk_file_entry {
	char* name;
	struct mk_toc_entry* belong;
	int  type;
};
