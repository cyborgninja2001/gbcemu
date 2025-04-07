#ifndef MEMORY_H
#define MEMORY_H

#include "common.h"

typedef struct {
    u8 rom_bank_00[0x4000];    // 0x0000 - 0x3FFF
    u8 rom_bank_01_NN[0x4000]; // 0x4000 - 0x7FFF
    u8 vram[0x2000];           // 0x8000 - 0x9FFF
    u8 external_ram[0x2000];   // 0xA000 - 0xBFFF
    u8 wram[0x2000];           // 0xC000 - 0xDFFF
    u8 echo_ram[0x1E00];       // 0xE000 - 0xFDFF
    u8 oam[0xA0];              // 0xFE00 - 0xFE9F
    u8 not_usable[0x60];       // 0xFEA0 - 0xFEFF (not usable)
    u8 io_regsiters[0x80];     // 0xFF00 - 0xFF7F
    u8 hram[0x7F];             // 0xFF80 - 0xFFFE
    u8 interrupt_enable_register; // 0xFFFF
} Memory;

u8 memory_read(Memory mem, u16 address);
void memory_write(Memory *mem, u16 address, u8 value);

#endif