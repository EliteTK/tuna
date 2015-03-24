#ifndef _ASM_H

typedef uint16_t port_t;

static inline uint8_t inb(port_t port)
{
	uint8_t data;

	__asm volatile("in %1, %0" : "=a" (data) : "d" (port));

	return data;
}

static inline void outb(port_t port, uint8_t data)
{
	__asm volatile("out %0, %1" : : "a" (data),  "d" (port));
}

#define _ASM_H
#endif /* _ASM_H */
