TARGET=i686-elf
AS=$(TARGET)-as
CC=$(TARGET)-gcc

OBJECTS=boot.o kernel.o term.o string.o vga.o

CFLAGS=-std=c11 -ffreestanding -O2 -Wall -Wextra -nostdlib
LDFLAGS=-T linker.ld
LDLIBS=-lgcc

BINARIES=tuna.bin

all: $(BINARIES)

tuna.bin: $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

boot.o: boot.s
kernel.o: kernel.c term.h
term.o: term.c vga.h string.h
vga.o: vga.c
string.o: string.c

qemu: $(BINARIES)
	@qemu-system-i386 -kernel $<

clean:
	$(RM) $(BINARIES) $(OBJECTS)
