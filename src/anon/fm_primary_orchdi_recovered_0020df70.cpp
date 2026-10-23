#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u8 D_01dac450[];
extern "C" u8 D_01da8bb0[];
extern "C" u8 D_01da8c40[];
extern "C" void func_0020e7a8(u8*, s32, s32, s32);
extern "C" void func_0020e800(u8*, s32, s32, s32);

// Preserve original registry aliases.
void func_0020df70(void) asm("_Z16u_call0_0020df70v");

void func_0020df70(void) {
    u32* node = (u32*)D_01dac450;
    u32* next;
    Quad header = 0x20000000;
    // why: original keeps the loop counter in t4 and the header quad in t5
    register s32 count asm("$12") = 287;
    do {
        *(Quad*)node = header;
        // why: keeps store order
        asm volatile("" ::: "memory");
        next = node + 4;
        node[2] = (u32)node;
        node[1] = (u32)next;
        count--;
        node = next;
    } while (count >= 0);
    *(Quad*)next = header;
    // why: keeps store order
    asm volatile("" ::: "memory");
    *next = 0x70000000;
    func_0020e7a8(D_01da8bb0, 9, 0, 0);
    func_0020e800(D_01da8c40, 9, 15, 0);
    // why: keeps the last call a jal with its own return
    asm volatile("" ::: "memory");
}
