#include "../common/types.h"
extern "C" s32 func_00184780(f32, f32, f32, s32);

void func_00174518(s32 *object) {
    // why: original holds object[1] in a1 and *object in t7
    register s32 second asm("$5") = object[1];
    register s32 first asm("$15") = *object;
    s32 word = *(s32 *)(first + 4);
    f32 x = ((f32 *)object)[2];
    s32 result = func_00184780(*(f32 *)(second + 0xc), x, ((f32 *)object)[3], word);
    *object = result;
}