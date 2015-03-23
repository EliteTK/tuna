#ifndef __SERIAL_H

enum serial_port {
	COM1 = 0x3F8,
	COM2 = 0x2F8,
	COM3 = 0x3E8,
	COM4 = 0x2E8
};

enum serial_offset {
	DATA = 0,
	INTR ,
	DLLO = 0,
	DLHI,
	FIFO,
	LCTL,
	MCTL,
	LSTA,
	MSTA,
	SCRA
};

enum serial_parity {
	PNONE = 0,
	PODD,
	PEVEN,
	PMARK,
	PSPACE
};

enum serial_stop {
	STOP1 = 0,
	STOP2
};

enum serial_data {
	DATA5 = 0,
	DATA6,
	DATA7,
	DATA8
};

struct serial_lctl {
	uint8_t _ : 2;
	enum serial_parity parity : 3;
	enum serial_stop : 1;
	enum serial_data : 2;
};

#define __SERIAL_H
#endif /* __SERIAL_H */
