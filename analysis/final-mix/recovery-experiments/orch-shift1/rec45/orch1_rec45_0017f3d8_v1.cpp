#include "../common/types.h"

s32* func_0017f3d8(s32* object, s32 first, s32 second, f32 x, f32 y) {
    s32 index = object[15];
    s32* entry = (s32*)((u8*)object + 0x3c + index * 20);
    object[15] = (index + 1) % 4;
    ((f32*)entry)[3] = x;
    ((f32*)entry)[4] = y;
    entry[5] = second;
    entry[2] = first;
    entry[6] = 0;
    return entry + 2;
}
