#include "../common/types.h"

void func_0018e0d8(u8* object, u32 value) {
    u32 slot;
    if (value != 3) {
        slot = value;
    } else {
        slot = 4;
    }
    u8 shift = slot;
    object[0x2c] = slot;
    object[0x2d] = ~((1 << shift) | 1);
}