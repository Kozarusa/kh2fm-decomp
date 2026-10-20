#include "../common/types.h"
extern "C" u32 D_0035f610;
u32 func_002ab100(s32 value) {
    if (value < 0) {
        u32 index = 0;
        u32 base = D_0035f610 + 0x88u;
        u32 word = 0;
        u32 result;
        do {
            u32 bit = index & 31u;
            u32 mask = 1u << bit;
            ++index;
            result = (*(u32*)(base + word * 4u) & mask) != 0;
            if (result) break;
            word = index >> 5;
        } while ((s32)index < 96);
        return result;
    }
    return (*(u32*)(D_0035f610 + ((u32)value >> 5) * 4u + 0x88u) & (1u << ((u32)value & 31u))) != 0;
}





