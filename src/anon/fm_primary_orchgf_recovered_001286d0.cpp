#include "../common/types.h"
extern "C" f32 D_0036aa14;
extern "C" f32 D_0036aa18;

f32 func_001286d0(f32 x, f32 p1, f32 a, f32 b, f32 p2, f32 c, f32 d) {
    f32 t = x - p1;
    f32* pointer = &D_0036aa14;
    asm("" : "+r"(pointer)); // why: original forms the address before lwc1 0(reg)
    f32 one = *pointer;
    f32 inv = one / (p2 - p1);
    register f32 sq asm("$f5") = t * t; // why: original keeps the square in f5
    pointer = &D_0036aa18;
    asm("" : "+r"(pointer)); // why: original forms the address before lwc1 0(reg)
    register f32 scale asm("$f3") = *pointer; // why: original loads the scale into f3
    f32 cube = sq * t;
    f32 k = sq * scale;
    f32 s = sq * inv;
    f32 inv2 = inv * inv;
    cube = cube * inv2;
    k = k * inv2;
    register f32 twice asm("$f4") = (cube + cube) * inv; // why: original keeps the doubled cube in f4
    return a * ((twice - k) + one) + c * (k - twice) + b * ((cube - (s + s)) + t) + d * (cube - s);
}
