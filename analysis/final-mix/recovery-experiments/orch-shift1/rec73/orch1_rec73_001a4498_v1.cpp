#include "../common/types.h"
extern "C" u8 D_00350778[];
extern "C" void func_0018d050(u32*, s32, s32, s32, s32, s32, s32);
extern "C" void func_001a4530(u32*);

void func_001a4498(u32* object, s32 a, s32 b, s32 c, s32 d, s32 e) {
    func_0018d050(object, a, a, b, d, e, c);
    object[0x32] = 0;
    object[0x31] = 0;
    u32 value = object[0x32];
    object[0] = (u32)D_00350778;
    object[0x33] = 0;
    object[0x40] = value;
    object[0x43] = value;
    object[0x41] = value;
    object[0x42] = value;
    func_001a4530(object + 0x44);
    object[1] = object[1] | 0x100;
}