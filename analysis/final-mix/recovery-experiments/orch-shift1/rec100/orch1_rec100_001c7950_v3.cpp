#include "../common/types.h"
extern "C" s32 func_001a4ff8(s32, u32*);

s32 func_001c7950(u32* object, s32 other) {
    s32 result = 0;
    if ((object[10] & 1) != 0) {
        u32 local[4];
        local[0] = object[0];
        local[2] = object[2];
        local[3] = object[3];
        *(f32*)&local[1] = (f32)object[1] + *(f32*)(object[0x13] + 4);
        result = func_001a4ff8(other, local);
    }
    return result;
}