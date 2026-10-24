#include "../common/types.h"
extern "C" u32 D_0034f240;
extern "C" s32 func_00187920(u8*);
extern "C" s32 func_00197e40();

s32 func_00176a90(u8* object) {
    s32 result = 0;
    if (func_00187920(object) != 0 || (*(u32*)(object + 0x10c) & 0x10000) != 0 ||
        0.0f < *(f32*)(object + 0xb00) || (D_0034f240 & 2) != 0 || func_00197e40() != 0) {
        result = 1;
    }
    return result;
}
