#include "../common/types.h"

u8 func_001d9688(s32 base, s32 index, s32 offset) {
    u8* pointer = (u8*)(index * 3 + base + offset);
    u32 value = *pointer;
    if ((u8)value < 99) {
        u32 next = value + 1;
        *pointer = next;
        value = next;
    }
    return value;
}
