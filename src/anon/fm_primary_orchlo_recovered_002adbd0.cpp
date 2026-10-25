#include "../common/types.h"
extern "C" u32* D_0035f620;
extern "C" s32 D_0035f628;
extern "C" s32 D_0035f62c;
// why: copied from the accepted call site in fm_primary_orchln_recovered_002ab448.cpp
extern "C" u8* func_001a82b0(u8*);
// why: copied from the accepted call site in fm_primary_capacity_recovered_00303c48.cpp
extern "C" u32 func_001a80c8(...);
// why: no accepted declaration; a0 carries the node pointer and the v0 result is only tested against zero
extern "C" s32 func_002a43b0(u8*);

// why: the only exit leaves func_001a82b0's v0 (the null node), a direct callee result, so the walk result is returned

u8* func_002adbd0(void) {
    u8* node = 0;
    u32 index = 0;
    // why: the original keeps the shift constant 1 in s5 across the loop calls
    register u32 one asm("$21") = 1;
    for (;;) {
        node = func_001a82b0(node);
        if (node == 0) {
            return node;
        }
        u8* info = (u8*)func_001a80c8(*(u16*)(node + 2));
        if (info[2] == 22) {
            D_0035f628++;
            s32 enabled = func_002a43b0(node);
            u32 word = index >> 5;
            u32 bit = index & 0x1f;
            index++;
            if (enabled) {
                u32* bits = (u32*)((u8*)D_0035f620 + 300);
                bits += word;
                *bits |= one << bit;
                D_0035f62c++;
            }
        }
    }
}
