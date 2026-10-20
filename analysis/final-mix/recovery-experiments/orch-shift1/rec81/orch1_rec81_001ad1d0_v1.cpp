#include "../common/types.h"
extern "C" u8 D_00350af0[];
extern "C" void func_001ac970(s32*, s32, s32, s32, s32, s32, s32, s32);

void func_001ad1d0(s32* object, s32 value) {
    func_001ac970(object, 3, 4, value, 0, 256, 32, 3);
    object[26] = 0;
    object[25] = 2;
    object[0] = (s32)D_00350af0;
}
