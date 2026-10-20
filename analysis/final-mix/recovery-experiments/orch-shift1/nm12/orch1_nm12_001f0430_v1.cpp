#include "../common/types.h"

void func_001f0430(u8* source, f32* dest) {
    f32 zero = 0.0f;
    asm("" : "+f"(zero)); // why: keeps zero in a float register so stores are swc1
    dest[1] = *(f32*)(source + 8);
    register f32 second asm("$f2") = *(f32*)(source + 20); // why: original uses $f2 for the second load
    *(u8**)dest = source;
    dest[4] = second;
    dest[6] = zero; // why: keeps store order
    dest[5] = zero;
    dest[3] = zero;
    dest[2] = zero;
}
