TARGET = ..\bin\mkuhook
OBJS = main.o exports.o minIni.o code/pspmem.o code/mkdeception.o code/mkumenu.o code/eLog.o  code/mkuhook.o code/eSettingsMgr.o code/mkuplrinfo.o

CFLAGS = -O2 -G0 -Wall -Wwrite-strings -Wdiscarded-qualifiers
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

BUILD_PRX = 1
PRX_EXPORTS = exports.exp

#
#USE_KERNEL_LIBC = 1
#USE_KERNEL_LIBS = 1

USE_PSPSDK_LIBC = 1

LIBS = -lpspsystemctrl_kernel

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build_prx.mak