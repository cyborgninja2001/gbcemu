#ifndef EMU_H
#define EMU_H

#include "common.h"
#include "cartridge.h"
#include "cpu.h"
#include "memory.h"
#include "gbc.h"

typedef struct {
    GBC gbc;
    Cartridge cartridge;
    bool paused;
    bool running;
    u64 ticks;
} Emu;

// execute the emulator
void emu_run(Emu *emu, int argc, char* argv[]);

// emulate the cycles
void emu_cycles(Emu *emu, int cycles);

#endif