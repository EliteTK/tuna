#include "term.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

void kernel_main()
{
	term_init();
	term_write("This is a very interesting test of printing something and damn it, it's interesting!");
}
