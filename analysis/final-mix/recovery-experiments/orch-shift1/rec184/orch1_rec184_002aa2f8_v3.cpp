#include "../common/types.h"
extern "C" u32 D_0035f610;
bool func_002aa2f8(s32 value) {
    if (value < 0) {
        u32 index = 0;
        u32 address = D_0035f610 + 316;
        bool result;
        do {
            u32 shift = index & 31;
            u32 mask = 1u << shift;
            u32 pointer = (index >> 5) * 4 + address;
            ++index;
            result = (*(u32*)pointer & mask) != 0;
            if (result) break;
        } while ((s32)index < 13);
        return result;
    }
    u32 mask = 1u << ((u32)value & 31);
    return (*(u32*)(D_0035f610 + ((u32)value >> 5) * 4 + 316) & mask) != 0;
}


