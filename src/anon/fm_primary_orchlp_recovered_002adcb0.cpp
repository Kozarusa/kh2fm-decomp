#include "../common/types.h"
extern "C" u8* D_0035f620;
// why: declaration copied from the recovered sibling func_002adaf0, which calls it the same way
extern "C" u8* func_001a82b0(u8*);
extern "C" u8* func_001a80c8(s32 id);
extern "C" s32 func_002764b0(u32);

// why: every exit returns a constant the function sets itself (move v0,s6 with s6 = 1 or 0), an own value

s32 func_002adcb0(s32 id) {
    u8* entry = 0;
    u32 index = 0;
    s32 result = 1;
    for (;;) {
        entry = func_001a82b0(entry);
        if (entry == 0) break;
        if (func_001a80c8(*(u16*)(entry + 2))[2] != 22) continue;
        if (id >= 0 && func_002764b0(entry[5]) != id) {
            index++;
            continue;
        }
        u32* flags = (u32*)(D_0035f620 + (index >> 5) * 4 + 300);
        u32 mask = 1 << (index & 0x1f);
        index++;
        if ((*flags & mask) == 0) {
            result = 0;
            break;
        }
    }
    return result;
}
