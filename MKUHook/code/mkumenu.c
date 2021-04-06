#include "mkumenu.h"
#include "eLog.h"
#include "mkdeception.h"
#include "pspmem.h"
#include "mkuhook.h"
#include <pspctrl.h>
int menu_thread()
{
	SceCtrlData pad;
	sceCtrlSetSamplingCycle(0);
	sceCtrlSetSamplingMode(PSP_CTRL_MODE_DIGITAL);
	while (1)
	{
		sceCtrlPeekBufferPositive(&pad, 1);
		if (pad.Buttons & PSP_CTRL_SQUARE)
		{
			if (pad.Buttons & PSP_CTRL_CIRCLE)
			{
				sceKernelDelayThread(1000000 / 10);
				hook_new_select_table();

			}

		}

		sceKernelDelayThread(1000);
	}
	sceKernelExitDeleteThread(0);
	return 0;
}
