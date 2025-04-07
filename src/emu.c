#include "emu.h"

//Cartridge cart;
//Cpu cpu;

void emu_run(Emu *emu, int argc, char* argv[]) {
    load_rom(&emu->cart, argv[1]);

    //set_AF(&cpu, 0x1224);
    //debug_cpu(cpu);

    emu->ticks++;
}

void emu_cycles(Emu *emu, int cycles) {}