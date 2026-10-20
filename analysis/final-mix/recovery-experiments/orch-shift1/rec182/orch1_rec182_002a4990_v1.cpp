#include "../common/types.h"
extern "C" u32 D_0035f5e4;
s32 func_002a4990(s32 value) {
    if (value < 0) {
        s32 offset = *(s32 *)(D_0035f5e4 + 0x1088);
        value = (s32)((u32)*(s32 *)(D_0035f5e4 + 0x1084) + (u32)(offset / 8));
    }
    s32 count = 0;
    s32 index = 0;
    u8 *pointer = (u8 *)(D_0035f5e4 + 0x1001);
    do {
        u32 flag = *pointer;
        pointer += 8;
        if (flag != 0) {
            count += flag;
            if (value < count) break;
        }
        index++;
    } while (index < 15);
    return index;
}
