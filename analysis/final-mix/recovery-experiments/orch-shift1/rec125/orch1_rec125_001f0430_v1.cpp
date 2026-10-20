#include "../common/types.h"

void func_001f0430(u8* source, f32* dest) {
    dest[1] = *(f32*)(source + 8);
    f32 second = *(f32*)(source + 20);
    *(u8**)dest = source;
    dest[4] = second;
    dest[2] = 0.0f;
    dest[6] = 0.0f;
    dest[5] = 0.0f;
    dest[3] = 0.0f;
}