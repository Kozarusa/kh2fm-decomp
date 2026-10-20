#include "../common/types.h"
void func_001e5fd8(void) { volatile u32* mode=(volatile u32*)0x10000010; register volatile u32* count asm("$13")=(volatile u32*)0x10000000; asm("" : "+r"(count)); *mode=*mode|0x83; *count=0; }
