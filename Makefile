TARGET = hello-world
OBJS = ./src/main.o ./src/common/callback.o

INCDIR =
CFLAGS = -O2 -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS	= $(CFLAGS)

LIBDIR =
LIBS =
LDFLAGS	=

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = HelloWorld
PSP_EBOOT_ICON= ./res/ICON0.png
PSP_EBOOT_PIC1= ./res/PIC1.png
PSP_EBOOT_SND0= ./res/SND0.at3

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak