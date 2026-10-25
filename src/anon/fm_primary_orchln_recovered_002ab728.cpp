#include "../common/types.h"
extern "C" u8* D_0035f610;
extern "C" s32 func_002a9d68(void);
// why: unrecovered iterator; a0 is the previous entry (0 starts), its own code writes v0 with the next entry or 0
extern "C" u8* func_001a82b0(u8*);
extern "C" s32 func_002764b0(u32);

u8* func_002ab728(s32 id) {
    u8* entry = 0;
    u32 index = 0;
    u32 sram = func_002a9d68() + 236;
    for (;;) {
        u8* next = func_001a82b0(entry);
        entry = next;
        if (next == 0) {
            break;
        }
        if (next[4] == 0) {
            u16 kind = *(u16*)(next + 8);
            if (kind != 0 && kind != 2048) {
                if (func_002764b0(next[5]) == id) {
                    u32 offset = (index >> 5) * 4;
                    u32 mask = 1 << (index & 0x1f);
                    if (*(u32*)(D_0035f610 + offset + 236) & mask) {
                        u32* owned = (u32*)(offset + sram);
                        u32 value = *owned;
                        if ((value & mask) == 0) {
                            *owned = value | mask;
                        }
                    }
                }
            }
        }
        index++;
    }
    return entry;
}
