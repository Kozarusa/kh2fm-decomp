#include "../common/types.h"
extern "C" u8* D_0035f610;
s32 func_002aacd8(s32 value) {
    if (value < 0) {
        u32 index = 0;
        u32* pointer = (u32*)(D_0035f610 + 148);
        s32 result;
        do {
            u32 mask = 1u << (index & 31);
            result = (pointer[index >> 5] & mask) != 0;
            ++index;
        } while (!result && (s32)index < 192);
        return result;
    }
    u32 mask = 1u << ((u32)value & 31);
    return (*(u32*)(D_0035f610 + ((u32)value >> 5) * 4 + 148) & mask) != 0;
}



