#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

// get the 'n' bit of 'a'
#define BIT(a,n) (a & (1 << n))

// set the 'n' bit of 'a' with value 'v'
#define BIT_SET(a, n, v) (v ? a = a | (1 << n) : a = a & ~(1 << n))

// macro for things not yet implemented
#define NO_IMPLEMENTED {printf("NOT IMPLEMENTED!\n"); exit(1);}

#endif