#include "../common/types.h"
extern "C" u64 func_0028b040(...);
extern "C" s32 D_0035f200;
extern "C" s32* D_0035f5ac;
s32 func_0029c9d8(s32 value) {
    if (value < 0) value = (s32)func_0028b040(D_0035f200);
    s32 count = 0;
    s32 bits = *D_0035f5ac;
    s32 index = 0;
    do {
        if ((u8)((bits >> index) & 1)) {
            if (count == value) break;
            count++;
        }
        index++;
    } while (index < 19);
    return index ? index - 1 : 16;
}
