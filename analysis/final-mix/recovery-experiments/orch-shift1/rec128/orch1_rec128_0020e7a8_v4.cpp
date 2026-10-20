#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u8 D_01dac450[];

void func_0020e7a8(u32* block, s32 size, s32 priority) {
    // why: original stores the hardware zero register with sq
    register Quad zero asm("$0") = 0;
    *(Quad*)block = zero;
    // why: keeps store order
    asm volatile("" ::: "memory");
    block[0] = (size - 1) | 0x20000000;
    if (priority < 1) {
        priority = 0;
    }
    if (priority > 15) {
        priority = 15;
    }
    u32* list = (u32*)(D_01dac450 + priority * 16);
    u32* tail = (u32*)list[2];
    u32 saved = tail[1];
    tail[1] = (u32)block;
    block[1] = saved;
    list[2] = (u32)block;
}