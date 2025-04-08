#include "emu.h"

Emu emulator;

int main(int argc, char* argv[]) {
    emu_run(&emulator, argc, argv);
    return 0;
}
