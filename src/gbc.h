#ifndef GBC_H
#define GBC_H

#include "common.h"
#include "cpu.h"
#include "memory.h"

typedef struct {
    Cpu cpu;
    Memory memory;
} GBC;

#endif