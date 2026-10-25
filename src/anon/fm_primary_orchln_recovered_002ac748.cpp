#include "../common/types.h"
extern "C" u32 D_0035f610;
extern "C" u8* func_001d9e30(u8* entry);
extern "C" s32 func_002764b0(u32);

// why: both exits return the 0/1 flag the function sets itself (move v0,s4), an own value

s32 func_002ac748(s32 world) {
    u8* entry = 0;
    s32 result = 0;
    for (;;) {
        entry = func_001d9e30(entry);
        if (entry == 0) {
            break;
        }
        if (world >= 0) {
            if (func_002764b0(entry[4]) != world) {
                continue;
            }
        }
        {
            u8 bit = entry[1];
            u8* row = (u8*)D_0035f610 + entry[0] * 8;
            u32* flags = (u32*)(row + (bit >> 5) * 4);
            if ((flags[101] & (1 << (bit & 0x1f))) != 0) {
                result = 1;
                break;
            }
        }
    }
    return result;
}
