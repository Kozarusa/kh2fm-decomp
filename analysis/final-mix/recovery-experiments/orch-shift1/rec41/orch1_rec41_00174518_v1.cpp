#include "../common/types.h"
extern "C" s32 func_00184780(f32, f32, f32, s32);

void func_00174518(s32 *object) {
    s32 result;
    result = func_00184780(*(f32 *)(object[1] + 0xc), ((f32 *)object)[2], ((f32 *)object)[3],
                           *(s32 *)(*object + 4));
    *object = result;
}