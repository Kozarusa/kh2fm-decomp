#include "../common/types.h"
extern "C" u16 D_0035ef70;

s32 func_00257fa8(u32 value) {
    s32 result = -1;
    s32 bits = D_0035ef70;
    s32 count = 0;
    s32 index = 0;
    do {
        u8 flag = (bits >> index) & 1;
        if (flag != 0) {
            if ((u32)count == value) { result = index; break; }
            count++;
        }
        index++;
    } while (index < 8);
    return result;
}
