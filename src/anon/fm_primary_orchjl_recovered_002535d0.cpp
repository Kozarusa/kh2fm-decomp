#include "../common/types.h"
extern "C" s8 D_003726c8[];
extern "C" s32 func_00102fa0();

s32 func_002535d0(s32 value) {
    s32 result = -1;
    for (s32 index = 0; D_003726c8[index] >= 0; index++) {
        if (value == D_003726c8[index]) { result = 2; break; }
    }
    if (func_00102fa0() != 0) result = 2;
    return result;
}
