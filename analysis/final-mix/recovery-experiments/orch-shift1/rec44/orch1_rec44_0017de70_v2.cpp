#include "../common/types.h"
extern "C" u8* D_00352130;

s32 func_0017de70(u8* object) {
    u8* source = *(u8**)(object + 1164);
    s32 amount = (s32)((f32)*(s32*)(source + 4) * *(f32*)(D_00352130 + 88));
    u8* table = *(u8**)object;
    return ((s32 (*)(u8*, s32, s32, s32))*(u32*)(table + 120))(object, amount, 0, 0);
}
