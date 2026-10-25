#include "../common/types.h"
extern "C" u8* D_0035f610;
extern "C" u32 func_00294000(u64);
extern "C" s32 func_002a9d68(void);
// why: unrecovered callee; its only argument is a0 = -1 and its own code writes v0 (li v0,1 / sltu / move v0,a0), which the caller returns
extern "C" s32 func_002ab180(s32);

s32 func_002ab368(s32 id) {
    s32 found = 1;
    u8* sram = (u8*)func_002a9d68();
    u32 object = func_00294000(7);
    u16* cursor = (u16*)(object + 16);
    if (id < 0) {
        found = func_002ab180(-1);
    } else {
        s32 count = *(s32*)(object + 8);
        s32 i = 0;
        if (i < count) {
            u32* owned = (u32*)(sram + 136);
            u32* bits = (u32*)(D_0035f610 + 136);
            do {
                if (*cursor == id) {
                    u32 mask = 1 << (i & 0x1f);
                    if (bits[(u32)i >> 5] & mask) {
                        found = (owned[(u32)i >> 5] & mask) != 0;
                        if (found == 0) {
                            return found;
                        }
                    }
                }
                cursor += 4;
                i++;
            } while (i < count);
        }
    }
    return found;
}
