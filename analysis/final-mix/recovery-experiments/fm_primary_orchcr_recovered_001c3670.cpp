#include "../common/types.h"
extern "C" u8* D_01d49560;
extern "C" u32 D_0032fca8[];

void func_001c3670(u32 id) {
    s32 index = 0;
    u16* entry = (u16*)(D_01d49560 + 8);
    s32 count = *(s32*)(D_01d49560 + 4);
    if (count > 0) {
        do {
            u16 current = *entry;
            entry = entry + 4;
            if (current == id) {
                break;
            }
            index = index + 1;
        } while (index < count);
    }
    u32 word = id >> 5;
    asm("" : "+r"(word)); // why: pins the shift-right result before the array address is formed
    word = word * 4;
    u32 bit = 1 << (id & 0x1f);
    *(u32*)((u8*)D_0032fca8 + word) = *(u32*)((u8*)D_0032fca8 + word) | bit;
    *(u32*)((u8*)D_0032fca8 + word + 16) = *(u32*)((u8*)D_0032fca8 + word + 16) | bit;
}
