#ifndef __DEBUGGER_H__
#define __DEBUGGER_H__

#include <stdint.h>

enum regs {
	R0,
	R1,
	R2,
	R3,
	R4,
	R5,
	R6,
	R7,
	R8,
	R9,
	R10,
	R11,
	R12,
	FP,
	SP,
	LR,
	PC
};

enum testpoint_type {
	TP_SUCCESS	= 0x1,
	TP_FAILURE	= 0x2,
	TP_USER		= 0x4,
};

struct testpoint {
	uint32_t	addr;
	uint16_t	type;
	uint16_t	tag;
};

struct target;

const struct target *get_target(void);

int dbg_stop(const struct target *t);
int dbg_run(const struct target *t);
int dbg_step(const struct target *t);
int dbg_read_reg(const struct target *t, unsigned reg, uint32_t *val);
int dbg_write_reg(const struct target *t, unsigned reg, uint32_t val);
int dbg_read32(const struct target *t, unsigned addr, uint32_t *val);
int dbg_read16(const struct target *t, unsigned addr, uint32_t *val);
int dbg_read8(const struct target *t, unsigned addr, uint32_t *val);
int dbg_write32(const struct target *t, unsigned addr, uint32_t val);
int dbg_write16(const struct target *t, unsigned addr, uint32_t val);
int dbg_write8(const struct target *t, unsigned addr, uint32_t val);
int load_elf(const struct target *t, const char *path,
	     struct testpoint **testpoints, size_t *nr_testpoints);

#endif /* __DEBUGGER_H__ */