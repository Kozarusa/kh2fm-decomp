#include "../common/types.h"

s32 func_001da4d8(s32* object, u16 mode) {
    s32 kind = mode >> 6;
    s32 result = object[0];
    s32 position = object[1];
    s32 next = position + 1;
    u32 word = *(u16*)(position * 2 + result + 0x10);
    asm volatile("" ::: "memory"); // why: keeps the table load before the position store
    object[1] = next;
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
        result = result + 0x10;
        word = word << 1;
        break;
    default:
        result = 0;
        break;
    }
    return result + word;
}
