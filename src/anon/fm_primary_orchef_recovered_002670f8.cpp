#include "../common/types.h"
extern "C" u8* D_0035f0e4;

s32 func_002670f8(s32 value) {
    s32 result = -1;
    s32 count = 0;
    s32 index = 0;
    s32 bits = *(u16*)(D_0035f0e4 + 28);
    do {
        if ((u8)((bits >> index) & 1)) {
            if (index == value) { result = count; break; }
            count++;
        }
        index++;
    } while (index < 10);
    return result;
}
