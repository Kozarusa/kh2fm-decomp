#include "../common/types.h"
extern "C" s32 D_01c60bc8[];
extern "C" s32 func_00188340(u8*, s32, s32*, s32);

s32 func_001883f8(u8* object, s32 value) {
    D_01c60bc8[0] = *(s32*)(object + 0x88);
    D_01c60bc8[1] = value;
    return func_00188340(object, 3, D_01c60bc8, 2);
}
