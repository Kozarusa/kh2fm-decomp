#include "../common/types.h"

void func_001cfac0(f32 a, f32 b, f32 c, f32 d, u8* object) {

    f32 scale = 0.017453292f;
    b = b * scale;
    c = c * scale;
    d = d * scale;
    *(f32*)(object + 0xb90) = a * scale;
    *(f32*)(object + 0xb94) = b;
    *(f32*)(object + 0xb98) = c;
    *(f32*)(object + 0xb9c) = d;
}
