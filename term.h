#ifndef __TERM_H

#include <stdint.h>
#include <stddef.h>
#include "vga.h"

color_t term_color;
size_t term_autoscroll;

void term_init(void);
void term_scrollhard(size_t distance);
void term_scrollsoft(void);
void term_clear(void);
void term_putchar(char c);
void term_write(const char *data);

#define __TERM_H
#endif /* __TERM_H */
