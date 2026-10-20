#include "../common/types.h"
extern "C" u32 D_0032dfd0[];

u32 func_001d9d48(u8* data) {
    // why: original keeps bit index in t3 ($11), row in t5 ($13), word index in t4 ($12), mask in t6 ($14)
    register u32 bit asm("$11") = data[1];
    // why: row lives in t5 ($13) in the original
    register u32 row asm("$13") = data[0];
    // why: word index lives in t4 ($12) in the original
    register u32 index asm("$12") = bit >> 5;
    // why: mask lives in t6 ($14) in the original
    register u32 mask asm("$14") = 1;
    // why: pins row and index to their own registers
    asm("" : "+r"(row), "+r"(index));
    u32* table = (u32*)((u8*)D_0032dfd0 + row * 8);
    mask = mask << (bit & 0x1f);
    return (table[index] & mask) != 0;
}
