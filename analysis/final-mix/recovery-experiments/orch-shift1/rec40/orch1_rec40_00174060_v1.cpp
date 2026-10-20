#include "../common/types.h"
extern "C" u32 func_00199468(s32, f32, s32, s32);

void func_00174060(s32* object) {
    func_00199468(*(s32*)(object[0] + 4), ((f32*)object)[1], object[2], object[3]);
}