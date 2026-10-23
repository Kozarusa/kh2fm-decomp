#include "../common/types.h"

void func_0016c750(u32 value) {
    register u32 high asm("$13") = 0x004f0000;
    asm volatile("" : "+r"(high) : : "$15");
    register u32 high2 asm("$15") = 0x004f0000;
    asm("" : "+r"(high2));
    register u32* base asm("$14") = (u32*)(high + 0x6290);
    asm("" : "+r"(base));
    *(u32*)(high2 + 0x6288) = value;
    base[1] = 0;
    *(u32*)(high + 0x6290) = 0;
}
