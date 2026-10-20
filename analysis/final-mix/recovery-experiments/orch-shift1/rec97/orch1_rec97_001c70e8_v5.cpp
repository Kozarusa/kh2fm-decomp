#include "../common/types.h"
extern "C" f32 D_0036df88;
extern "C" f32 D_0036df8c;
extern "C" f32 D_01d498f0;
extern "C" u32 D_01d49940;

void func_001c70e8() {
    f32* p = &D_01d498f0;
    u8* q = (u8*)p - 32;
    f32* first = &D_0036df88;
    f32* second = &D_0036df8c;
    D_01d49940 = (D_01d49940 & 0xffffff87) | 0x30;
    p[2] = *first;
    *(f32*)(q + 0x6c) = *second;
    *(u64*)(q + 0x70) = *(u64*)(q + 0x70) | 1;
    D_01d498f0 = *first;
    p[1] = *first;
    *(s32*)(p + 3) = 0;
}