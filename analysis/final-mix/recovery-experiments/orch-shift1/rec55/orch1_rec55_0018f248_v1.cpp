#include "../common/types.h"
extern "C" void func_00186740(s32, s32, s32, s32, f32, f32);

void func_0018f248(s32* object) {
    func_00186740(*(s32*)(*object + 4), object[1], object[2], object[3], ((f32*)object)[4], ((f32*)object)[5]);
}