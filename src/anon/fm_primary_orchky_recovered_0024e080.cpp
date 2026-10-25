#include "../common/types.h"
extern "C" s32 func_001d56c8(...);
extern "C" u32 func_00276c18(...);
extern "C" s32 D_0035edf4;
extern "C" s32 D_003722ec;
extern "C" s32 D_003722f0;
extern "C" u8 D_003722e0[];
extern "C" u8 D_003722e8[];

s32 func_0024e080(void) {
    if (func_00276c18() != 0) {
        return 1;
    }
    s32 result = 0;
    s32 count;
    if (D_0035edf4 == 0) {
        count = D_003722ec;
    } else {
        count = D_003722f0;
    }
    for (s32 index = 0; index < count; index++) {
        u8 value;
        if (D_0035edf4 == 0) {
            value = D_003722e0[index];
        } else {
            value = D_003722e8[index];
        }
        u8* score = (u8*)func_001d56c8(value);
        if (*score >= 2) {
            result = 1;
            break;
        }
    }
    return result;
}
