#include "emu.h"

Cartridge cart;
Cpu cpu;

void emu_run(int argc, char* argv[]) {
    //load_rom(&cart, argv[1]);

    set_AF(&cpu, 0x1224);
    debug_cpu(cpu);
}