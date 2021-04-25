#pragma once




struct mem_ssf_entry {
	char* fileName;
	int   totalFileSize; // padded
	int   fileSize;
};

struct mem_ssf_header {
	char* fileName;
	int   pad[2];
	struct mem_ssf_entry files[250];
};



void hook_load_ssf(struct mem_ssf_header* ptr);