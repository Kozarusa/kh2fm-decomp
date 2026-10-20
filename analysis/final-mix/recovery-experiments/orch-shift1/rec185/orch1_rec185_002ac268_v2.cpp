#include "../common/types.h"
extern "C" s32 func_002a9d68(void);
extern "C" s32 func_002abf40(s8,s32);
u32 func_002ac268(s32 value, s32 other) {
    u32 base = (u32)func_002a9d68();
    u32 index = (u32)func_002abf40(value, other);
    base = base + (u32)value * 4 + 172;
    u32* pointer = (u32*)((index >> 5) * 4 + base);
    u32 previous = *pointer;
    u32 result = index & 31;
    u32 mask = 1u << result;
    if ((previous & mask) == 0) {
        *pointer = previous | mask;
    }
    return result;
}

