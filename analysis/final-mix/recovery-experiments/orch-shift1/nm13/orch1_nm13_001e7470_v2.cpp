#include "../common/types.h"

struct Channel { u32 control; };
void func_001e7470(u32 address) {
    while ((*(volatile u32*)0x1000a000 & 0x100) != 0) {
    }
    *(volatile u32*)0x1000a020 = 0;
    *(volatile u32*)0x1000a030 = address | 0x80000000;
    *(volatile u32*)0x1000e010 = 2;
    ((volatile Channel*)0x1000a000)->control = 0x145;
}