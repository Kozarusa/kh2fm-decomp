#include "../common/types.h"
extern "C" u8* func_001cbc50(s32, u8*, s32, s32);
extern "C" s32 D_00351fe4;
extern "C" u8 D_0036e180[];
extern "C" u8 D_001cba90[];

u8* func_001cbeb8(s32 arg, s32 index) {
    u8* result = 0;
    if (D_00351fe4 != 0) {
        result = func_001cbc50(D_00351fe4, D_0036e180 + index * 16, arg, 0);
        *(u8**)(result + 0x10) = D_001cba90;
        *(u32*)(result + 0x28) = *(u32*)(result + 0x28) | 3;
    }
    return result;
}