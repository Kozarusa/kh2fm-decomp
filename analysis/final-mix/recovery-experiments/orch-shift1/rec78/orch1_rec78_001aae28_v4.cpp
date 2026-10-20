#include "../common/types.h"

void func_001aae28(volatile u32* object, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j) {
    // why: volatile stores keep the original store order
    u32 last = j;
    object[0] = a;
    object[6] = last;
    object[1] = b;
    object[2] = c;
    object[3] = d;
    ((volatile u8*)object)[16] = e;
    ((volatile u8*)object)[17] = f;
    ((volatile u8*)object)[18] = g;
    ((volatile u8*)object)[19] = h;
    object[5] = i;
}

