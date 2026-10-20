#include "../common/types.h"

void func_0018e0d8(u8* object, u32 value) {
    u32 slot = value;
    if (value == 3) {
        // why: keeps the original compare-and-branch instead of a conditional move
        asm("" : "+r"(slot));
        slot = 4;
    }
    u8 shift = slot;
    object[0x2c] = slot;
    object[0x2d] = ~((1 << shift) | 1);
}