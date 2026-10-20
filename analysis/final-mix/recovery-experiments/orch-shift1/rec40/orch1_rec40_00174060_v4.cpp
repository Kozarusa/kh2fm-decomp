#include "../common/types.h"
extern "C" u32 func_00199468(s32, f32, s32, s32);

void func_00174060(s32* object) {
    s32 third = object[3];
    s32 second = object[2];
    f32 value = ((f32*)object)[1];
    s32 target = *(s32*)(object[0] + 4);
    func_00199468(target, value, second, third);
}
