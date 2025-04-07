#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include "common.h"

typedef struct {
    u8 entry_point[4];          // 0x0100 - 0x0103
    u8 nintendo_logo[48];       // 0x0104 - 0x0133
    char title[16];             // 0x0134 - 0x0143 (0x013F - 0x0142 -> Manufacturer code)
                                //                 (0143 -> CGB flag)
    u8 new_lincensee_code[2];   // 0x0144 - 0x0145
    u8 sgb_flag;                // 0x0146
    u8 cartridge_type;          // 0x0147
    u8 rom_size;                // 0x0148
    u8 ram_size;                // 0x0149
    u8 destination_code;        // 0x014A
    u8 old_licensee_code;       // 0x014B
    u8 mask_rom_version_number; // 0x014C
    u8 header_checksum;         // 0x014D
    u8 global_checksum;         // 0x014E - 0x014F
} Cartridge_header;

typedef struct {
    char *filename;
    u32 rom_size;
    u8 *data;
    Cartridge_header *header;
} Cartridge;

// returns the cartridge type
const char *get_rom_type(Cartridge cart);

// returns the ROM code (new or old lic code)
const char *get_rom_code(Cartridge cart);

// loads the ROM. Returns true if success otherwise false
bool load_rom(Cartridge *cart, char *rom_path);

#endif