#include "../common/types.h"

u8* func_00321728(u8* entries, u32 value, u32 key) {
    u8* best = 0;
    s32 index = 0;
    do {
        if (entries[0] == value && *(u16*)(entries + 2) == key) {
            return entries;
        }
        if (best == 0 || best[1] > entries[1]) {
            best = entries;
        }
        ++index;
        entries += 4;
    } while (index < 128);
    best[0] = value;
    *(u16*)(best + 2) = key;
    best[1] = 0;
    return best;
}
