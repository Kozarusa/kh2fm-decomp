#include "../common/types.h"
extern "C" u8* D_0035f610;
extern "C" u32 func_00294000(u64);
extern "C" s32 func_002aacd8(s32);

s32 func_002aae88(s32 id) {
    s32 found = 0;
    u32 object = func_00294000(8);
    u16* entry = (u16*)(object + 16);
    if (id < 0) {
        found = func_002aacd8(-1);
    } else {
        s32 count = *(s32*)(object + 8);
        s32 i = 0;
        if (i < count) {
            u16* cursor = entry;
            u32* bits = (u32*)(D_0035f610 + 148);
            do {
                if (*cursor == id) {
                    if (bits[(u32)i >> 5] & (1 << (i & 0x1f))) {
                        found = 1;
                        break;
                    }
                }
                cursor += 8;
                i++;
            } while (i < count);
        }
    }
    return found;
}
