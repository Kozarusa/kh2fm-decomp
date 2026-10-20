#include "../common/types.h"

s32 func_001da4d8(s32* object, u16 mode) {
    u32 kind = mode >> 6;
    u32 base = object[0];
    u32 word = *(u16*)(object[1] * 2 + base + 0x10);
    s32 result = 0;
    object[1] = object[1] + 1;
    switch (kind) {
    case 0:
        result = object[2];
        break;
    case 1:
        result = object[4];
        break;
    case 2:
        result = *(s32*)object[2];
        break;
    case 3:
        result = base + 0x10;
        word = word << 1;
        break;
    default:
        break;
    }
    return result + word;
}
