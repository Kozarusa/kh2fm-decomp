#include "../common/types.h"
extern "C" u8* D_0035f620;

s32 func_002adf60(s32 value) {
    s32 result = 1;
    u32 index = 0;
    u32* pointer = (u32*)(D_0035f620 + 320);
    do {
        if (value < 0 || (u32)value == index) {
            u32 mask = 1u << (index & 31);
            if ((pointer[index >> 5] & mask) == 0) {
                result = 0;
                break;
            }
        }
        ++index;
    } while ((s32)index < 4);
    return result;
}
