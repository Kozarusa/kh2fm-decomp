#include "../common/types.h"

void func_001aae28(u32* object, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j) {
    object[0] = a;
    object[6] = j;
    object[1] = b;
    object[2] = c;
    object[3] = d;
    ((u8*)object)[16] = e;
    ((u8*)object)[17] = f;
    ((u8*)object)[18] = g;
    ((u8*)object)[19] = h;
    object[5] = i;
}
