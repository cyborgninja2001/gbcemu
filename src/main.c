#include "common.h"
#include "cartridge.h"

int main(int argc, char** argv) {
    load_rom(argv[1]);
    return 0;
}
