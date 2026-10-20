#include "../common/types.h"

void func_001e7470(u32 address) {
    volatile u32* control = (volatile u32*)0x1000a000;
    while ((*control & 0x100) != 0) {
    }
    *(volatile u32*)0x1000a020 = 0;
    *(volatile u32*)0x1000a030 = address | 0x80000000;
    *(volatile u32*)0x1000e010 = 2;
    *control = 0x145;
}