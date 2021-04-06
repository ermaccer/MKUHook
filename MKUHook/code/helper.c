#include "helper.h"
#include <string.h>
#include <stdio.h>
int str_to_int(char * str)
{
	int res = 0;

	for (int i = 0; str[i] != 0x20; ++i)
		res = res * 10 + str[i] - '0';


	return res;
}

