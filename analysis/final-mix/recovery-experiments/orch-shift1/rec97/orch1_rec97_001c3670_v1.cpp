#include "../common/types.h"
extern "C" u8* D_01d49560;
extern "C" u32 D_0032fca8[];

void func_001c3670(u32 id) {
    s32 index = 0;
    u16* entry = (u16*)(D_01d49560 + 8);
    if (*(s32*)(D_01d49560 + 4) > 0) {
        u16 current = *entry;
        while (entry = entry + 4, current != id && (index = index + 1, index < *(s32*)(D_01d49560 + 4))) {
            current = *entry;
        }
    }
    u32 word = (id >> 5) * 4;
    u32 bit = 1 << (id & 0x1f);
    *(u32*)((u8*)D_0032fca8 + word) = *(u32*)((u8*)D_0032fca8 + word) | bit;
    *(u32*)((u8*)D_0032fca8 + word + 16) = *(u32*)((u8*)D_0032fca8 + word + 16) | bit;
}