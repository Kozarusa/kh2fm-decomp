#include "../common/types.h"
extern "C" u32 D_0032dfd0[];

u32 func_001d9d48(u8* data) {
    // why: original loads the bit index into t3 ($11) and the row into t5 ($13)
    register u32 bit asm("$11") = data[1];
    register u32 row asm("$13") = data[0];
    u32* table = (u32*)((u8*)D_0032dfd0 + row * 8);
    return (table[bit >> 5] & (1 << (bit & 0x1f))) != 0;
}
