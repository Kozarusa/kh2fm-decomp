#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u8 D_01dac450[];
extern "C" u8 D_01da8bb0[];
extern "C" u8 D_01da8c40[];
extern "C" void func_0020e7a8(u8*, s32, s32, s32);
extern "C" void func_0020e800(u8*, s32, s32, s32);

void func_0020df70(void) {
    u32* node = (u32*)D_01dac450;
    u32* next;
    for (s32 count = 287; count >= 0; count--) {
        *(Quad*)node = (Quad)0x20000000;
        next = node + 4;
        node[2] = (u32)node;
        node[1] = (u32)next;
        node = next;
    }
    *(Quad*)next = (Quad)0x20000000;
    *next = 0x70000000;
    func_0020e7a8(D_01da8bb0, 9, 0, 0);
    func_0020e800(D_01da8c40, 9, 15, 0);
    // why: keeps the last call a jal with its own return
    asm volatile("" ::: "memory");
}