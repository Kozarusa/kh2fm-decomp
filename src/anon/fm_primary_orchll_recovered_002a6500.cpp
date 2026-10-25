#include "../common/types.h"
// Declarations copied from accepted callers fm_primary_threeword_recovered_002a6368.cpp / 002a7f20 / orchex 002a6878.
extern "C" bool func_002944d0(void*);
extern "C" u32 func_00276c18(void);
extern "C" u32 func_00294000(u64);

s32 func_002a6500(void) {
    s32 index = 0;
    s32 result = 0;
    u8* info = (u8*)func_00294000(6);
    u8* entries = info + 0x10;
    if (*(s32*)(info + 8) > 0) {
        do {
            if (func_002944d0(entries + index * 8)) {
                result = 1;
                break;
            }
            index++;
        } while (index < *(s32*)(info + 8));
    }
    if (func_00276c18() != 0) {
        result = 1;
    }
    return result;
}
