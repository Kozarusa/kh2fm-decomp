#include "../common/types.h"

void func_0018e0d8(u8* object, u32 value) {
    u8 slot = (value == 3) ? 4 : value;
    object[0x2c] = slot;
    object[0x2d] = ~((1 << slot) | 1);
}