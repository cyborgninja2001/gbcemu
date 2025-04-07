#include "cpu.h"

// macros to get the flags
#define CPU_FLAG_Z BIT(cpu.registers.f, 7) // zero flag
#define CPU_FLAG_N BIT(cpu.registers.f, 6) // subtraction flag (BCD)
#define CPU_FLAG_H BIT(cpu.registers.f, 5) // half Carry flag (BCD)
#define CPU_FLAG_C BIT(cpu.registers.f, 4) // carry flag

// **** UTILS: ****
u16 get_AF(Cpu cpu) {
    return ((u16)cpu.registers.a << 8) | cpu.registers.f;
}

u16 get_BC(Cpu cpu) {
    return ((u16)cpu.registers.b << 8) | cpu.registers.c;
}

u16 get_DE(Cpu cpu) {
    return ((u16)cpu.registers.d << 8) | cpu.registers.e;
}

u16 get_HL(Cpu cpu) {
    return ((u16)cpu.registers.h << 8) | cpu.registers.l;
}

void set_AF(Cpu *cpu, u16 value) {
    cpu->registers.a = (value >> 8) & 0xFF;
    cpu->registers.f = value & 0xFF;
}

void set_BC(Cpu *cpu, u16 value) {
    cpu->registers.b = (value >> 8) & 0xFF;
    cpu->registers.c = value & 0xFF;
}

void set_DE(Cpu *cpu, u16 value) {
    cpu->registers.d = (value >> 8) & 0xFF;
    cpu->registers.e = value & 0xFF;
}

void set_HL(Cpu *cpu, u16 value) {
    cpu->registers.h = (value >> 8) & 0xFF;
    cpu->registers.l = value & 0xFF;
}

void set_flag_Z(Cpu *cpu, bool value) {
    BIT_SET(cpu->registers.f, 7, value);
}

void set_flag_N(Cpu *cpu, bool value) {
    BIT_SET(cpu->registers.f, 6, value);
}

void set_flag_H(Cpu *cpu, bool value) {
    BIT_SET(cpu->registers.f, 5, value);
}

void set_flag_C(Cpu *cpu, bool value) {
    BIT_SET(cpu->registers.f, 4, value);
}

void debug_cpu(Cpu cpu) {
    printf("A:0x%02X F:0x%02X B:0x%02X C:0x%02X D:0x%02X E:0x%02X H:0x%02X L:0x%02X\n",
        cpu.registers.a,
        cpu.registers.f,
        cpu.registers.b,
        cpu.registers.c,
        cpu.registers.d,
        cpu.registers.e,
        cpu.registers.h,
        cpu.registers.l);
    printf("AF:0x%04X BC:0x%04X DE:0x%04X HL:0x%04X\n",
        get_AF(cpu),
        get_BC(cpu),
        get_DE(cpu),
        get_HL(cpu));
    printf("PC:0x%04X SP:0x%04X\n",
        cpu.registers.pc,
        cpu.registers.sp);
    //printf("\n");
}

// **** MAIN FUNCTIONS: ****
void cpu_init(Cpu *cpu) {}

void cpu_fetch(Cpu *cpu) {}

void cpu_decode_and_execute(Cpu *cpu) {}