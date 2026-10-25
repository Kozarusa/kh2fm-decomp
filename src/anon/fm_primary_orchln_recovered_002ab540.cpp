#include "../common/types.h"
extern "C" u8* D_0035f610;
// why: no recovered declaration; a0 takes the previous entry (starts at 0) and v0 returns the next entry pointer or 0
extern "C" u8* func_001a82b0(u8*);
extern "C" s32 func_002764b0(u32);

s32 func_002ab540(s32 id) {
    u8* entry = 0;
    u32 index = 0;
    s32 found = 0;
    for (;;) {
        entry = func_001a82b0(entry);
        if (entry == 0) break;
        if (entry[4] == 0) {
            u16 kind = *(u16*)(entry + 8);
            if (kind != 0 && kind != 0x800) {
                s32 value = func_002764b0(entry[5]);
                u32 offset = (index >> 5) * 4;
                u32 mask = 1 << (index & 0x1f);
                if (id < 0 || value == id) {
                    u8* base = D_0035f610;
                    if (*(u32*)(base + offset + 236) & mask) {
                        found = 1;
                        break;
                    }
                }
            }
        }
        index++;
    }
    return found;
}
