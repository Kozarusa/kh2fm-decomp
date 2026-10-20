#include "../common/types.h"
extern "C" s32 func_00184780(f32, f32, f32, s32);

void func_00174518(s32 *object) {
    s32 second = object[1];
    s32 first = *object;
    f32 x = ((f32 *)object)[2];
    f32 y = ((f32 *)object)[3];
    s32 result = func_00184780(*(f32 *)(second + 0xc), x, y, *(s32 *)(first + 4));
    *object = result;
}