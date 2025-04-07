#include "common.h"
#include "cartridge.h"
#include "cpu.h"

int main(int argc, char** argv) {
    load_rom(argv[1]);
    return 0;
}
