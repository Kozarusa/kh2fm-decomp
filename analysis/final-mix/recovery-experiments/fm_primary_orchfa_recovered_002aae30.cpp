#include "../common/types.h"
extern "C" s32 func_002a9d68(void);

s32 func_002aae30(u32 value) {
    u32 base = (u32)func_002a9d68() + 0x94u;
    u32* pointer = (u32*)((value >> 5) * 4u + base);
    u32 old = *pointer;
    u32 mask = 1u << (value & 31u);
    if ((old & mask) == 0) {
        *pointer = old | mask;
    }
    return (s32)base;
}
