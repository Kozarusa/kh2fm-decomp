#include "../common/types.h"
extern "C" s32 func_002a9d68(void);
extern "C" s32 func_002aa5b8(s8,s32);
u32 func_002aa8e0(u32 value, s32 mode) {
    u32 address = (u32)func_002a9d68();
    u32 index = (u32)func_002aa5b8(value, mode);
    address = address + (u32)value * 4u + 68;
    u32* pointer = (u32*)((index >> 5) * 4 + address);
    u32 word = *pointer;
    index &= 31;
    u32 mask = 1u << index;
    u32 result = word | mask;
    if ((word & mask) == 0) {
        *pointer = result;
    }
    return index;
}

