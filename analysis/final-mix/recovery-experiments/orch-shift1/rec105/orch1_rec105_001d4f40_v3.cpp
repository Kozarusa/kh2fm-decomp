#include "../common/types.h"
extern "C" f32 D_0036e530;
extern "C" u32 func_001d1b60(u8*, s32);
extern "C" f32 func_002f8b30(f32, f32);

u32 func_001d4f40(u8* object, s32 scale, s32 exponent) {
    f32 base = (f32)scale;
    f32 factor = func_002f8b30(D_0036e530, (f32)exponent);
    s32 amount = (s32)(base * factor);
    if (amount == 0) {
        amount = 1;
    }
    return func_001d1b60(object, *(s32*)(object + 0x2c) + amount);
}