#include "../common/types.h"
extern "C" u32 func_00199468(f32, s32, s32, s32);

u32 func_00174060(s32* object) {
    s32 target = *(s32*)(object[0] + 4);
    return func_00199468(((f32*)object)[1], target, object[2], object[3]);
}
