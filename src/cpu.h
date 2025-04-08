#ifndef CPU_H
#define CPU_H

// 8-bit 8080-like Sharp CPU (speculated to be a SM83 core)

#include "common.h"
#include "cartridge.h"
#include "memory.h"
#include <stdbool.h>

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
} Registers;

typedef struct {
    Registers registers;
    bool cgb_mode;
    u8 current_opcode;
} Cpu;

typedef enum {
    A,
    F,
    B,
    C,
    D,
    E,
    H,
    L,
    AF,
    BC,
    DE,
    HL,
    SP,
    PC,
} Register_type;

// UTILS:
u16 get_AF(Cpu cpu);
u16 get_BC(Cpu cpu);
u16 get_DE(Cpu cpu);
u16 get_HL(Cpu cpu);

void set_AF(Cpu *cpu, u16 value);
void set_BC(Cpu *cpu, u16 value);
void set_DE(Cpu *cpu, u16 value);
void set_HL(Cpu *cpu, u16 value);

u8 get_flag_Z(Cpu cpu);
u8 get_flag_N(Cpu cpu);
u8 get_flag_H(Cpu cpu);
u8 get_flag_C(Cpu cpu);

void set_flag_Z(Cpu *cpu, bool value);
void set_flag_N(Cpu *cpu, bool value);
void set_flag_H(Cpu *cpu, bool value);
void set_flag_C(Cpu *cpu, bool value);

void debug_cpu(Cpu cpu);

// ****INSTRUCTIONS****
void NOP();

// LD
void LD_R_R(Cpu *cpu, Register_type r1, Register_type r2);  // LD r1, r2
void LD_R_n8(Cpu *cpu, Register_type r1);                   // LD r1, n8
void LD_R_n16(Cpu *cpu, Register_type r1);                  // LD r1, n16
void LD_MR_R(Cpu *cpu, Register_type r1, Register_type r2); // LD [r1], r2

// Main functions:
void cpu_init(Cpu *cpu, Cartridge cartridge);
void cpu_fetch(Cpu *cpu, Memory memory);
void cpu_decode_and_execute(Cpu *cpu, Memory memory);

#endif