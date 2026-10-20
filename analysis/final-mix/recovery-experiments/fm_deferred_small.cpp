#include "../common/types.h"

u32 func_00152598(u32 ignored, s32 index, u32 second, u32* base) {
    register u32 offset asm("$15") = index * 8;
    asm("" : "+r"(offset));
    register u32* target asm("$15") = (u32*)((u32)base + offset);
    asm("" : : "r"(target));
    return second == 0 ? target[0] : target[1];
}

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

void func_0016f7b0(void) {
    register u32 high asm("$15") = 0x004f0000;
    asm volatile("" : "+r"(high) : : "$14");
    register u32 high2 asm("$14") = 0x004f0000;
    asm("" : "+r"(high2));
    asm volatile("" : : "r"(high), "r"(high2));
    *(u32*)(high + 0x63a8) = 0;
    asm volatile("" : : : "memory");
    register u32 base asm("$13") = high + 0x63a8;
    asm("" : "+r"(base));
    *(u32*)(high2 + 0x63a0) = 0;
    *(u32*)(base + 4) = 0;
}
