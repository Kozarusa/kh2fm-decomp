#include "../common/types.h"
extern "C" u32 D_0035f610;
extern "C" s32 func_002a9d68(void);
// why: no accepted declaration; a0 carries the previous node pointer and v0 the next one (0 ends the walk)
extern "C" u8* func_001a82b0(u8*);
extern "C" bool func_00181500(u32);
extern "C" s32 func_002764b0(u32);
extern "C" u32 func_002954e0(s32);

// why: the only exit leaves func_001a82b0's v0 (the null node), a direct callee result, so the walk result is returned

u8* func_002ab448(void) {
    u8* node = 0;
    u32 index = 0;
    u32* sram = (u32*)((u8*)func_002a9d68() + 236);
    for (;;) {
        node = func_001a82b0(node);
        if (node == 0) {
            return node;
        }
        if (node[4] == 0) {
            u16 flag = *(u16*)(node + 8);
            if (flag != 0 && flag != 0x800 && func_00181500(flag)) {
                u32 world = func_002954e0(func_002764b0(node[5]));
                u32 slot = index >> 5;
                u32 bit = 1 << (index & 0x1f);
                if (world != 0) {
                    if ((sram[slot] & bit) == 0) {
                        // why: original keeps the flag-array address in t6 (14) and the loaded word in t7
                        register u8* base asm("$14") = (u8*)D_0035f610 + 236;
                        // why: original forms the flag-array base (addiu 236) before adding the word offset; keeps gcc from folding 236 into the load
                        asm("" : "+r"(base));
                        u32* word = (u32*)(base + (slot << 2));
                        *word |= bit;
                    }
                }
            }
        }
        index++;
    }
}
