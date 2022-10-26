TARGET = ..\bin\mkuhook
OBJS = main.o exports.o minIni.o code/pspmem.o code/mkdeception.o code/eLog.o  code/mkuhook.o code/eSettingsMgr.o code/mkuplrinfo.o code/stage.o code/mips.o code/injector.o

CFLAGS = -O2 -Os -G0 -Wall -fshort-wchar -fno-pic -mno-check-zero-division
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

BUILD_PRX = 1
PRX_EXPORTS = exports.exp

USE_PSPSDK_LIBC = 1
USE_PSPSDK_LIBS = 1

LIBS = -lpspsystemctrl_user


PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build_prx.mak