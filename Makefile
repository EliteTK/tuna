TARGET = i686-elf
AS = $(TARGET)-as
CC = $(TARGET)-gcc

CFLAGS = -std = c11 -ffreestanding -Wall -Wextra -nostdlib -MD -MP
LDFLAGS = -T linker.ld
LDLIBS = -lgcc

OBJECTS = boot.o kernel.o term.o string.o vga.o
BINARIES = tuna.bin

DEBUG ?= 0
ifeq ($(DEBUG), 1)
else
	CFLAGS += -flto -O2
	LDFLAGS += -flto -O2
endif

all: $(BINARIES)

tuna.bin: $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

qemu: $(BINARIES)
	@qemu-system-i386 -kernel $<

clean:
	$(RM) $(BINARIES) $(OBJECTS) *.d

-include *.d
