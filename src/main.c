#include "emu.h"

Emu emu;

int main(int argc, char* argv[]) {
    emu_run(&emu, argc, argv);
    return 0;
}
