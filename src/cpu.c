#include "cpu.h"

static Cpu cpu;

// macros to get the flags
#define CPU_FLAG_Z BIT(cpu.registers.f, 7) // zero flag
#define CPU_FLAG_N BIT(cpu.registers.f, 6) // subtraction flag (BCD)
#define CPU_FLAG_H BIT(cpu.registers.f, 5) // half Carry flag (BCD)
#define CPU_FLAG_C BIT(cpu.registers.f, 4) // carry flag


void cpu_init() {}

void cpu_fetch() {}

void cpu_decode_and_execute() {}