#include "../common/types.h"
extern "C" void func_001391c8(void*, s32, s32);

void func_0015aa98(u8* object, s32 first, s32 second, f32 scale) {
    func_001391c8(object, 11000, 0);
    // why: keeps store order
    *(volatile s32*)(object + 0x20) = second;
    *(volatile s32*)(object + 0x18) = first;
    *(f32*)(object + 0x1c) = scale;
}