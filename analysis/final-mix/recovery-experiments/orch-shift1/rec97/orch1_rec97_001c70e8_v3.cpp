#include "../common/types.h"
extern "C" f32 D_0036df88;
extern "C" f32 D_0036df8c;
extern "C" f32 D_01d498f0[];
extern "C" u32 D_01d49940;

void func_001c70e8() {
    D_01d498f0[2] = D_0036df88;
    D_01d498f0[19] = D_0036df8c;
    D_01d498f0[0] = D_0036df88;
    D_01d49940 = (D_01d49940 & 0xffffff87) | 0x30;
    *(u64*)((u8*)D_01d498f0 + 0x50) = *(u64*)((u8*)D_01d498f0 + 0x50) | 1;
    D_01d498f0[1] = D_0036df88;
    *(s32*)(D_01d498f0 + 3) = 0;
}