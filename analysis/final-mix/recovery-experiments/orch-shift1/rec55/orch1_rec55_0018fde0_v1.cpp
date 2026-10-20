#include "../common/types.h"
extern "C" void func_001b50e0(s32, s32, s32, f32);

void func_0018fde0(s32* object) {
    func_001b50e0(object[0], object[1], object[3] != 0, ((f32*)object)[2]);
}