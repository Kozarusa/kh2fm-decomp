#include "../common/types.h"
extern "C" u32 func_00199468(s32, f32, s32, s32);

void func_00174060(s32* object) {
    s32 inner = object[0];
    volatile s32* pointer = object;
    s32 third = pointer[3];
    s32 target = *(s32*)(inner + 4);
    f32 value = ((f32*)object)[1];
    s32 second = object[2];
    func_00199468(target, value, second, third);
}
