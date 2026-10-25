#include "../common/types.h"
extern "C" u32* D_0035f610;
extern "C" u32 func_00294000(u64);
// why: matches the exact definition submitted for 002a9e98 (s32 index tested with bgez); the u16 form in fm_primary_orchlk_recovered_002a1b18.cpp emits li a0,0xffff instead of the original li a0,-1
extern "C" s32 func_002a9e98(s32);

s32 func_002aa098(s32 id) {
    s32 found = 0;
    if (id < 0) {
        found = func_002a9e98(-1);
    } else {
        u32 object = func_00294000(3);
        s32 count = *(s32*)(object + 8);
        u8* entry = (u8*)(object + 16);
        for (s32 i = 0; i < count; i++) {
            if (*(s8*)entry == id) {
                u16 bit = *(u16*)(entry + 4);
                if (D_0035f610[bit >> 5] & (1 << (bit & 0x1f))) {
                    found = 1;
                    break;
                }
            }
            entry += 36;
        }
    }
    return found;
}
