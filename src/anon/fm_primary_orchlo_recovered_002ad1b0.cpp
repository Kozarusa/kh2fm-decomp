#include "../common/types.h"
extern "C" u32* D_0035f620;
// why: copied from the accepted call site in fm_primary_orcher_recovered_00294208.cpp
extern "C" u32 func_00294000(u64);

s32 func_002ad1b0(s32 id) {
    s32 all = 1;
    u32 object = func_00294000(3);
    s32 count = *(s32*)(object + 8);
    u8* entry = (u8*)(object + 16);
    for (s32 i = 0; i < count; i++) {
        if (id < 0 || *(s8*)entry == id) {
            u16 bit = *(u16*)(entry + 4);
            if ((D_0035f620[bit >> 5] & (1 << (bit & 0x1f))) == 0) {
                all = 0;
                break;
            }
        }
        entry += 36;
    }
    return all;
}
