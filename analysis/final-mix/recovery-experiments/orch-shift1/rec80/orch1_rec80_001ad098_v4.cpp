#include "../common/types.h"
extern "C" void func_001ac970(u8*, s32, s32, s32, s32, s32, s32, s32);
extern "C" f32 D_0036d79c[];
extern "C" u8 D_00350b70[];

void func_001ad098(u8* object, s32 first, s32 second) {
    func_001ac970(object, 3, 5, first, second, 128, 104, 0);
    f32* source = D_0036d79c;
    *(volatile f32*)(object + 104) = *source;
    *(u8**)object = D_00350b70;
}