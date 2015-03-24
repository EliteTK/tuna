#include "term.h"
#include "vga.h"
#include "string.h"
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

size_t term_y = 0;
size_t term_x = 0;
entry_t *buffer = VGA_BUFFER;

void term_init(void)
{
	static bool initialised = false;
	if (initialised)
		return;

	term_color = vga_makecolor(CL_LGREY, CL_BLACK);
	term_autoscroll = 1;

	term_clear();

	initialised = true;
}

void term_clear(void)
{
	for (size_t x = 0; x < VGA_WIDTH; x++)
		for (size_t y = 0; y < VGA_HEIGHT; y++)
			buffer[x + y * VGA_WIDTH] = vga_makeentry(' ', term_color);
}

static inline void putentry(char c)
{
	buffer[term_y * VGA_WIDTH + term_x] = vga_makeentry(c, term_color);
}

inline void term_scrollhard(const size_t dist)
{
	for (size_t i = 0; i < VGA_WIDTH * (term_y - dist); i++)
		buffer[i] = buffer[i + VGA_WIDTH];

	for (size_t i = 0; i < VGA_WIDTH * dist; i++)
		buffer[i + VGA_WIDTH * (term_y - dist)] = vga_makeentry(' ', term_color);

	term_y -= dist;
}

inline void term_scrollsoft(void)
{
	if (term_y == VGA_HEIGHT)
		term_scrollhard(term_autoscroll);
}

static inline void newline(void)
{
	term_x = 0;
	term_y++;

	term_scrollsoft();
}

void term_putchar(char c)
{
	if (c == '\n') {
		newline();
		return;
	}

	putentry(vga_makeentry(c, term_color));

	if (++term_x == VGA_WIDTH)
		newline();
}

void term_write(const char *data)
{
	size_t length = strlen(data);

	for (size_t i = 0; i < length; i++)
		term_putchar(data[i]);

	vga_setcursor(term_x, term_y);
}
