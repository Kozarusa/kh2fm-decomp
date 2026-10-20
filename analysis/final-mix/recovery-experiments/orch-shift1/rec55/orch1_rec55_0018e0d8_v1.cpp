#include "../common/types.h"

void func_0018e0d8(u8* object, u32 value) {
    if (value == 3) {
        value = 4;
    }
    object[0x2c] = value;
    object[0x2d] = ~((1 << (u8)value) | 1);
}