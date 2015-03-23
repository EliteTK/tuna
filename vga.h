#ifndef __VGA_H

#include <stdint.h>
#include <stddef.h>

typedef uint8_t color_t;
typedef uint16_t entry_t;

enum vga_color
{
	CL_BLACK = 0,
	CL_BLUE,
	CL_GREEN,
	CL_CYAN,
	CL_RED,
	CL_MAGENTA,
	CL_BROWN,
	CL_LGREY,
	CL_DGREY,
	CL_LBLUE,
	CL_LGREEN,
	CL_LCYAN,
	CL_LRED,
	CL_LMAGENTA,
	CL_LBROWN,
	CL_WHITE,
};

color_t vga_makecolor(enum vga_color foreground, enum vga_color background);
entry_t vga_makeentry(char c, color_t color);
void vga_putentry(entry_t entry, size_t x, size_t y);

static const size_t VGA_HEIGHT = 25;
static const size_t VGA_WIDTH = 80;
#define VGA_BUFFER ((entry_t *)0xB8000);

#define __VGA_H
#endif /* __VGA_H */
