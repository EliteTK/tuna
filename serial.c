#include <stdbool.h>
#include <stddef.h>
#include "serial.h"

void serial_init(enum serial_port port)
{
	outb(port + 1, 0x00); /* cli                                   */
	outb(port + 3, 0x80); /* enable DLAB                           */
	outb(port + 0, 0x03); /* 0x03                                  */
	outb(port + 1, 0x00); /* 0x00                                  */
	outb(port + 3, 0x03); /* 8 bits, no parity, one stop bit       */
	outb(port + 2, 0xC7); /* enable FIFO, clear, 14-byte threshold */
	outb(port + 4, 0x0B); /* sti, RTS/DTS set                      */
}

bool serial_canwrite()
{
	return inb(PORT + 5) & 1;
}
