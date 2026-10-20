#include "../common/types.h"
extern "C" u32 D_0032dfd0[];

u32 func_001d9d48(u8* data) {
    u32 bit = data[1];
    u32 row = data[0];
    u32 mask = 1 << (bit & 0x1f);
    u32* table = (u32*)((u8*)D_0032dfd0 + row * 8);
    return (table[bit >> 5] & mask) != 0;
}
