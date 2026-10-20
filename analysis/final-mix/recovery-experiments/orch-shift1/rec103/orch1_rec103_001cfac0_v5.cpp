#include "../common/types.h"
extern "C" f32 D_0036e360;

void func_001cfac0(f32 a, f32 b, f32 c, f32 d, u8* object) {
    f32* pointer = &D_0036e360;
    // why: keeps the address in a register so the load uses a zero offset
    asm("" : "+r"(pointer));
    f32 scale = *pointer;
    b = b * scale;
    c = c * scale;
    d = d * scale;
    *(f32*)(object + 0xb90) = a * scale;
    *(f32*)(object + 0xb94) = b;
    *(f32*)(object + 0xb98) = c;
    *(f32*)(object + 0xb9c) = d;
}