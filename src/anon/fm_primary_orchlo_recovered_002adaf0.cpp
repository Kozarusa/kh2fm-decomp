#include "../common/types.h"
extern "C" u8* D_0035f620;
// why: no recovered declaration; a0 takes the previous entry (starts at 0) and v0 returns the next entry pointer or 0
extern "C" u8* func_001a82b0(u8*);
extern "C" s32 func_002764b0(u32);

// why: every exit returns a constant the function sets itself (move v0,s6 with s6 = 1 or 0), an own value

s32 func_002adaf0(s32 id) {
    u8* entry = 0;
    u32 index = 0;
    s32 result = 1;
    for (;;) {
        entry = func_001a82b0(entry);
        if (entry == 0) break;
        if (entry[4] == 0) {
            u16 kind = *(u16*)(entry + 8);
            if (kind != 0 && kind != 0x800) {
                if (id < 0 || func_002764b0(entry[5]) == id) {
                    u32* flags = (u32*)(D_0035f620 + (index >> 5) * 4 + 236);
                    u32 mask = 1 << (index & 0x1f);
                    if ((*flags & mask) == 0) {
                        result = 0;
                        break;
                    }
                }
            }
        }
        index++;
    }
    return result;
}
