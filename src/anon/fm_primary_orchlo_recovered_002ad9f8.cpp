#include "../common/types.h"
extern "C" s32 D_0035f620;
extern "C" s32 D_0035f628;
extern "C" s32 D_0035f62c;
// why: no accepted declaration; a0 carries the previous node pointer and v0 the next one (0 ends the walk)
extern "C" u8* func_001a82b0(u8*);
extern "C" bool func_00181500(u32);
// why: no accepted declaration; a0 carries the node pointer and the caller tests v0 for zero
extern "C" s32 func_002a4390(u8*);

// why: the only exit leaves func_001a82b0's v0 (the null node), a direct callee result, so the walk result is returned

u8* func_002ad9f8(void) {
    u8* node = 0;
    u32 index = 0;
    for (;;) {
        node = func_001a82b0(node);
        if (node == 0) {
            return node;
        }
        if (node[4] == 0) {
            u16 flag = *(u16*)(node + 8);
            if (flag != 0 && flag != 0x800 && func_00181500(flag)) {
                D_0035f628++;
                if (func_002a4390(node) != 0) {
                    u32* word = (u32*)(D_0035f620 + 0xec + (index >> 5) * 4);
                    *word |= 1 << (index & 0x1f);
                    D_0035f62c++;
                }
            }
        }
        index++;
    }
}
