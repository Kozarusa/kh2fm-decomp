#include "../common/types.h"
extern "C" u32 func_001391c8(void*, s32, s32);

u32 func_0015aa98(u8* object, s32 first, s32 second, f32 scale) {
    u32 result = func_001391c8(object, 11000, 0);
    // why: keeps store order
    *(volatile s32*)(object + 0x20) = second;
    *(s32*)(object + 0x18) = first;
    // why: keeps store order
    *(volatile f32*)(object + 0x1c) = scale;
    return result;
}
