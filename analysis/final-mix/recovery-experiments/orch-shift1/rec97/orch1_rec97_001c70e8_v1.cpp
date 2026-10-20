#include "../common/types.h"
extern "C" f32 D_0036df88;
extern "C" f32 D_0036df8c;
extern "C" f32 D_01d498f0;
extern "C" f32 D_01d498f4;
extern "C" f32 D_01d498f8;
extern "C" s32 D_01d498fc;
extern "C" f32 D_01d4993c;
extern "C" u32 D_01d49940;
extern "C" u64 D_01d49940_wide;

void func_001c70e8() {
    D_01d498f8 = D_0036df88;
    D_01d4993c = D_0036df8c;
    D_01d498f0 = D_0036df88;
    D_01d49940 = (D_01d49940 & 0xffffff87) | 0x30;
    D_01d49940_wide = D_01d49940_wide | 1;
    D_01d498f4 = D_0036df88;
    D_01d498fc = 0;
}