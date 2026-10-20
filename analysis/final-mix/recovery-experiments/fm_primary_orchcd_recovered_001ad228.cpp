#include "../common/types.h"
extern "C" void func_001ac970(u8*, s32, s32, s32, s32, s32, s32, s32);
extern "C" u8 D_00350af0[];

void func_001ad228(u8* object, s32 value) {
    func_001ac970(object, 3, 4, value, 0, 256, 32, 3);
    *(s32*)(object + 104) = 0;
    *(s32*)(object + 100) = 2;
    *(u8**)object = D_00350af0;
}
