#include "../common/types.h"

s32* func_0017f3d8(u8* object, s32 first, s32 second, f32 x, f32 y) {
    u8* base = object + 0x3c;
    s32 index = *(s32*)base;
    s32 next = index + 1;
    u8* entry = base + index * 20;
    *(s32*)base = next % 4;
    s32* slot = (s32*)(entry + 8);
    ((volatile f32*)slot)[1] = x;
    ((volatile f32*)slot)[2] = y;
    slot[3] = second;
    *(s32*)(entry + 8) = first;
    *(s32*)(entry + 24) = 0;
    return slot;
}
