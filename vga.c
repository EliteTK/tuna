#include "vga.h"

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
