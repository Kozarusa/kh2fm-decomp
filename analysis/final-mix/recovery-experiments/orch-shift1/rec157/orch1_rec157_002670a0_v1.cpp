#include "../common/types.h"
extern "C" u8* D_0035f0e4;
s32 func_002670a0(s32 value) {
    s32 result = -1;
    s32 count = 0;
    s32 index = 0;
    s32 flags = *(u16*)(D_0035f0e4+28);
    do {
        u8 flag = (flags >> index) & 1;
        if (flag != 0) {
            if (count == value) return index;
            ++count;
        }
        ++index;
    } while (index < 10);
    return result;
}
