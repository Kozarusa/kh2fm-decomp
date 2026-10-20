#include "../common/types.h"
extern "C" u16 D_01d49574[];

void func_001c4080(u32 mode, u32 value, u32 unused2, u32 unused3) {
    if (value == 0xffff && mode == 1) {
        u8* low = (u8*)D_01d49574 - 4;
        D_01d49574[2] = value;
        low[2] = value;
        D_01d49574[0] = value;
        low[1] = value;
        ((u8*)D_01d49574)[-4] = value;
        D_01d49574[1] = value;
    }
}