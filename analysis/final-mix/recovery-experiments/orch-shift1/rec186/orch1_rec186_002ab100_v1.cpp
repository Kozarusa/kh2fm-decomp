#include "../common/types.h"
extern "C" u32 D_0035f610;
bool func_002ab100(s64 value) {
    if (value < 0) {
        u32 index = 0;
        u32 word = 0;
        bool result;
        do {
            u32 bit = index & 31u;
            ++index;
            result = (*(u32*)(D_0035f610 + word * 4u + 0x88u) & (1u << bit)) != 0;
            if (result) break;
            word = index >> 5;
        } while ((s32)index < 96);
        return result;
    }
    return (*(u32*)(D_0035f610 + ((u32)value >> 5) * 4u + 0x88u) & (1u << ((u32)value & 31u))) != 0;
}
