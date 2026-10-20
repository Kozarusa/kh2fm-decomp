#include "../common/types.h"

u8 func_001d9688(s32 base, s32 index, s32 offset) {
    u8* pointer = (u8*)(index * 3 + base + offset);
    u8 value = *pointer;
    if (value < 99) {
        value = value + 1;
        *pointer = value;
    }
    return value;
}
