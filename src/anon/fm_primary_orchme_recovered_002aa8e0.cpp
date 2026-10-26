#include "../common/types.h"
extern "C" s32 func_002a9d68(void);
extern "C" s32 func_002aa5b8(...);

u32 func_002aa8e0(s32 value, s32 mode) {
    u32 base = (u32)func_002a9d68();
    u32 index = (u32)func_002aa5b8(value, mode);
    base += value * 4;
    base += 68;
    u32* pointer = (u32*)((index >> 5) * 4 + base);
    index &= 31;
    u32 word = *pointer;
    u32 mask = 1u << index;
    if ((word & mask) == 0) {
        *pointer = word | mask;
    }
    return index;
}
