#include "../common/types.h"
extern "C" u64 func_001c0d38(...);
extern "C" s32 D_0034d8a0;

s32* func_00171c60(s32* object) {
    s32* result = (s32*)func_001c0d38(((s32*)object[0])[1], ((s32*)object[1])[1], object[2], object[3]);
    s32 count = object[4];
    if (count != 0) {
        s32 value = D_0034d8a0;
        result[5] = object[5];
        result[3] = value;
        result[4] = count;
    }
    return result;
}
