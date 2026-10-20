#include "../common/types.h"

void func_001e5fd8(void) { volatile u32* mode=(volatile u32*)0x10000010; volatile u32* count=(volatile u32*)0x10000000; *mode=*mode|0x83; *count=0; asm volatile("nop" ::: "memory"); }
