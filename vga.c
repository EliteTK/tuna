#include "vga.h"
#include "asm.h"

#define PORT 0x03D4
#define WIDTH 80
#define HEIGHT 25

color_t vga_makecolor(enum vga_color fg, enum vga_color bg)
{
	return fg | bg << 4;
}

entry_t vga_makeentry(char c, color_t color)
{
	entry_t c16 = c;
	entry_t color16 = color;

	return c16 | color16 << 8;
}

void vga_setcursor(uint8_t x, uint8_t y)
{
	uint16_t pos = x + (y * WIDTH);

	outb(PORT + 0, 0xF);
	outb(PORT + 1, pos & 0xFF);
	outb(PORT + 0, 0xE);
	outb(PORT + 1, pos >> 8);
}

void vga_getcursor(uint8_t * restrict x, uint8_t * restrict y)
{
	uint16_t pos;

	outb(PORT + 0, 0xF);
	pos = inb(PORT);
	outb(PORT + 0, 0xE);
	pos |= inb(PORT) << 8;

	*x = pos % WIDTH;
	*y = pos - *x;
}
