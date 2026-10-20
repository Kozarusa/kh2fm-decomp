#include "../common/types.h"
extern "C" s32 func_001aafe8(f32, f32, u32, u32*, s32, s32, s32, s32);

void func_001aa8a8(u32* object, s32 a, s32 b, s32 c, s32 d) {
    func_001aafe8(((f32*)object)[9], ((f32*)object)[10], object[0], object + 16, a, b, c, d);
}
