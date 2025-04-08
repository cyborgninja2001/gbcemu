#include "memory.h"

u8 memory_init(Memory *memory) {
    for (int i = 0x0000; i < 0x4000; i++) {
        memory->rom_bank_00[i] = 0;
        memory->rom_bank_01_NN[i] = 0;
    }

    for (int i = 0x0000; i < 0x2000; i++) {
        memory->vram[i] = 0;
        memory->external_ram[i] = 0;
        memory->wram[i] = 0;
    }

    for (int i = 0x0000; i < 0x1E00; i++) {
        memory->echo_ram[i] = 0;
    }

    for (int i = 0x00; i < 0xA0; i++) {
        memory->oam[i] = 0;
    }

    // just in case:
    for (int i = 0x00; i < 0x60; i++) {
        memory->not_usable[i] = 0;
    }

    for (int i = 0x00; i < 0x80; i++) {
        memory->io_regsiters[i] = 0;
    }

    for (int i = 0; i < 0x7F; i++) {
        memory->hram[i] = 0;
    }

    memory->interrupt_enable_register = 0;
    printf("MEMORY INITIALIZED!\n");
}

u8 memory_read(Memory mem, u16 address) {
    if (address <= 0x3FFF) {
        return mem.rom_bank_00[address];
    } else if (address <= 0x7FFF) {
        return mem.rom_bank_01_NN[address - 0x4000];
    } else if (address <= 0x9FFF) {
        return mem.vram[address - 0x8000];
    } else if (address <= 0xBFFF) {
        return mem.external_ram[address - 0xA000];
    } else if (address <= 0xDFFF) {
        return mem.wram[address - 0xC000];
    } else if (address <= 0xFDFF) {
        return mem.echo_ram[address - 0xE000];
    } else if (address <= 0xFE9F) {
        return mem.oam[address - 0xFE00];
    } else if (0xFEA0 <= address && address <= 0xFEFF) {
        printf("*MEMORY: NOT USABLE* memory_read(0x%02X)\n", address);
        exit(-1);
        //return -1;
    } else if (address <= 0xFF7F) {
        return mem.io_regsiters[address - 0xFF00];
    } else if (address <= 0xFFFE) {
        return mem.hram[address - 0xFF80];
    } else if (address = 0xFFFF) {
        return mem.interrupt_enable_register;
    }

    printf("NO VALID memory_read(0x%02X)\n", address);
    exit(-1);
    //return -1;
}

void memory_write(Memory *mem, u16 address, u8 value) {
    if (address <= 0x3FFF) {
        mem->rom_bank_00[address] = value;
    } else if (address <= 0x7FFF) {
        mem->rom_bank_01_NN[address - 0x4000] = value;
    } else if (address <= 0x9FFF) {
        mem->vram[address - 0x8000] = value;
    } else if (address <= 0xBFFF) {
        mem->external_ram[address - 0xA000] = value;
    } else if (address <= 0xDFFF) {
        mem->wram[address - 0xC000] = value;
    } else if (address <= 0xFDFF) {
        mem->echo_ram[address - 0xE000] = value;
    } else if (address <= 0xFE9F) {
        mem->oam[address - 0xFE00] = value;
    } else if (0xFEA0 <= address && address <= 0xFEFF) {
        printf("*MEMORY: NOT USABLE* memory_write(0x%02X)\n", address);
        exit(-1);
    } else if (address <= 0xFF7F) {
        mem->io_regsiters[address - 0xFF00] = value;
    } else if (address <= 0xFFFE) {
        mem->hram[address - 0xFF80] = value;
    } else if (address = 0xFFFF) {
        mem->interrupt_enable_register = value;
    }

    printf("NO VALID memory_write(0x%02X)\n", address);
    exit(-1);
}
