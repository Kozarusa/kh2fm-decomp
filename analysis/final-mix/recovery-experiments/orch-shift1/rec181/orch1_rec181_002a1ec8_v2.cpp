#include "../common/types.h"
extern "C" u32 func_002766d0(void);
extern "C" u32 func_0028dac8(...);
extern "C" s8* D_0035f5d4;
extern "C" u8 D_00374b60[];
u32 func_002a1ec8() {
    s32 count = 31;
    u32 pointer = func_002766d0() + 0x4398u;
    s32 flag = D_0035f5d4[2];
    s32 offset = 6;
    if (flag != 16) offset = 0;
    s16* data = (s16*)(D_00374b60 + offset);
    u32 result;
    do {
        --count;
        result = func_0028dac8(pointer, data[1]);
        pointer += 408u;
    } while (count >= 0);
    return result;
}

