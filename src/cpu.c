#include "cpu.h"

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

u8 get_flag_Z(Cpu cpu) {
    return ((cpu.registers.f >> 7) & 1);
}

u8 get_flag_N(Cpu cpu) {
    return ((cpu.registers.f >> 6) & 1);
}

u8 get_flag_H(Cpu cpu) {
    return ((cpu.registers.f >> 5) & 1);
}

u8 get_flag_C(Cpu cpu) {
    return ((cpu.registers.f >> 4) & 1);
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
    printf("FLAGS: Z:%u N:%u H:%u C:%u\n", get_flag_Z(cpu), get_flag_N(cpu), get_flag_H(cpu), get_flag_C(cpu));
    //printf("\n");
}

// **** MAIN FUNCTIONS: ****
void cpu_init(Cpu *cpu, Cartridge cartridge) {
    // check if the cartridge supports cgb mode or dmg mode
    unsigned char cgb_flag = (unsigned char)cartridge.header->title[15];
    if (cgb_flag != 0x00) {
        cpu->cgb_mode = true;  // CGB
    } else {
        cpu->cgb_mode = false; // DMG
    }

    // init the current opcode (*CHECK!*)
    cpu->current_opcode = 0x00;

    if (cpu->cgb_mode) {
        // CGB Mode
        cpu->registers.a = 0x11;
        cpu->registers.f = 0x00;
        set_flag_Z(cpu, 1);
        cpu->registers.b = 0x00;
        cpu->registers.c = 0x00;
        cpu->registers.d = 0xFF;
        cpu->registers.e = 0x56;
        cpu->registers.h = 0x00;
        cpu->registers.l = 0x0D;
    } else {
        // CGB (DMG Mode)
        cpu->registers.a = 0x11;
        cpu->registers.f = 0x00;
        set_flag_Z(cpu, 1);

        if ((cartridge.header->old_licensee_code == 0x01) ||
            ((cartridge.header->old_licensee_code == 0x33) &&
            (cartridge.header->new_lincensee_code[1] == 0x30 ||
             cartridge.header->new_lincensee_code[1] == 0x31))) {
                // B is the sum of all 16 title bytes
                //  *DANGER*: in cartridge I rewrote the last characters of the title
                // -> that's why i read from data instead from cartridge.header.title
                u8 result = 0;
                for (int i = 0x0134; i <= 0x0143; i++) {
                    result += cartridge.data[i];
                }
                cpu->registers.b = result;
            } else {
                cpu->registers.b = 0x00;
            }

        cpu->registers.c = 0x00;
        cpu->registers.d = 0x00;
        cpu->registers.e = 0x08;

        if ((cpu->registers.b == 0x43) || (cpu->registers.b == 0x58)) {
            set_HL(cpu, 0x991A);
        } else {
            set_HL(cpu, 0x007C);
        }
    }

    cpu->registers.sp = 0xFFFE;
    cpu->registers.pc = 0x0100;
}

void cpu_fetch(Cpu *cpu) {}

void cpu_decode_and_execute(Cpu *cpu) {}