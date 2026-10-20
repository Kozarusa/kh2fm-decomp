#include "../common/types.h"
extern "C" void func_00186740(s32, s32, s32, s32, f32, f32);

void func_0018f248(s32* object) {
    s32 table = *object;
    s32 second = object[1];
    f32 y = ((f32*)object)[5];
    func_00186740(*(s32*)(table + 4), second, object[2], object[3], ((f32*)object)[4], y);
}