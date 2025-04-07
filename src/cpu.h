#ifndef CPU_H
#define CPU_H

// 8-bit 8080-like Sharp CPU (speculated to be a SM83 core)

#include "common.h"

typedef struct {
    u8 a;
    u8 f;
    u8 b;
    u8 c;
    u8 d;
    u8 e;
    u8 h;
    u8 l;
    u16 sp;
    u16 pc;
} registers;

typedef struct {
    registers regs;
} gbc_cpu;

void cpu_init();
void cpu_fetch();
void cpu_decode_and_execute();

#endif