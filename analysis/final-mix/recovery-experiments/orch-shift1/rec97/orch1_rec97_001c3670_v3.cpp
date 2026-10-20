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
    u32 bit = 1 << (id & 0x1f);
    D_0032fca8[word] = D_0032fca8[word] | bit;
    D_0032fca8[word + 4] = D_0032fca8[word + 4] | bit;
}