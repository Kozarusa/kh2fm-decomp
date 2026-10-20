#include "../common/types.h"
extern "C" f32 D_0036e530[];
extern "C" u32 func_001d1b60(u8*, s32);
extern "C" f32 func_002f8b30(f32, f32);

u32 func_001d4f40(u8* object, s32 scale, s32 exponent) {
    f32 base = (f32)scale;
    f32* pointer = D_0036e530;
    // why: keeps the global address in a register before the call
    asm("" : "+r"(pointer));
    f32 factor = func_002f8b30(*pointer, (f32)exponent);
    s32 amount = (s32)(base * factor);
    s32 field = *(s32*)(object + 0x2c);
    // why: orders the object copy before the constant load\n    asm("" : "+r"(object));\n    // why: original keeps the constant 1 in t7 so the converted amount lands in t6
    register s32 one asm("$15") = 1;
    if (amount == 0) {
        amount = one;
    }
    return func_001d1b60(object, field + amount);
}
