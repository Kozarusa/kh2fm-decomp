#include "../common/types.h"
extern "C" f32 D_0036d7a0[];
extern "C" u8 D_00350b70[];
extern "C" void func_001ac970(s32*, s32, s32, s32, s32, s32, s32, s32);

void func_001ad0f8(s32* object, s32 first, s32 second) {
    func_001ac970(object, 3, 5, first, second, 128, 104, 0);
    f32* source = D_0036d7a0;
    *(f32*)(object + 26) = *source;
    object[0] = (s32)D_00350b70;
}
