#include "../common/types.h"
extern "C" u8* func_001cbc50(s32, u8*, s32, s32);
extern "C" s32 D_00351fe4;
extern "C" u8 D_0036e180[];
extern "C" u8 D_001cba90[];

u8* func_001cbeb8(s32 arg, s32 index) {
    // why: original keeps the returned object in t5 ($13), separate from the callee v0
    register u8* result asm("$13") = 0;
    if (D_00351fe4 != 0) {
        u8* object = func_001cbc50(D_00351fe4, D_0036e180 + index * 16, arg, 0);
        result = object;
        *(u8**)(object + 0x10) = D_001cba90;
        *(u32*)(object + 0x28) = *(u32*)(object + 0x28) | 3;
    }
    return result;
}