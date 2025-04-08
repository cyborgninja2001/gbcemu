#include "emu.h"

//Cartridge cart;
//Cpu cpu;

void emu_run(Emu *emu, int argc, char* argv[]) {
    load_rom(&emu->cartridge, argv[1]);

    cpu_init(&emu->gbc.cpu, emu->cartridge);
    //set_AF(&cpu, 0x1224);
    debug_cpu(emu->gbc.cpu);

    emu->ticks++;
}

void emu_cycles(Emu *emu, int cycles) {}