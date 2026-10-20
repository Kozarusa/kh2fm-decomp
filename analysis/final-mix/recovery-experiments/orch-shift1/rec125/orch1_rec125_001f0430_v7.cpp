#include "../common/types.h"

void func_001f0430(u8* source, f32* dest) {
    f32 zero = 0.0f;
    asm("" : "+f"(zero)); // why: keeps zero in a float register so stores are swc1
    f32 first = *(f32*)(source + 8);
    asm("" : "+f"(first)); // why: keeps first live so second gets its own float register
    dest[1] = first;
    f32 second = *(f32*)(source + 20);
    *(u8**)dest = source;
    dest[4] = second;
    dest[6] = zero; // why: keeps store order
    dest[5] = zero;
    dest[3] = zero;
    dest[2] = zero;
}