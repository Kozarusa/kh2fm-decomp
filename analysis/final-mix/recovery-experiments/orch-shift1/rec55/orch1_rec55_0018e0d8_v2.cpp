#include "../common/types.h"

void func_0018e0d8(u8* object, u32 value) {
    u32 slot = value;
    if (value == 3) {
        slot = 4;
    }
    object[0x2c] = slot;
    object[0x2d] = ~((1 << (u8)slot) | 1);
}