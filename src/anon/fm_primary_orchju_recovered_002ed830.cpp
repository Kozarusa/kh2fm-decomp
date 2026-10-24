#include "../common/types.h"
extern "C" f32 D_0037619c;
extern "C" f32 D_003761a0;
extern "C" void func_002ed630(u8*);
extern "C" void func_002ed720(u8*);

// Preserve original registry aliases.
s32 func_002ed830(u8* object) asm("_Z16u_call4_002ed830jjjj");

s32 func_002ed830(u8* object) {
    func_002ed630(object);
    func_002ed720(object);

    s32 result = 1;
    // why: original keeps the field value in $f1 through the compare and first multiply
    register f32 value asm("$f1") = *(f32*)(object + 88);
    if (value < 0.0f) return 0;
    asm volatile("" ::: "memory"); // why: keeps the first address formation after the guard (original does not hoist it above bc1t)

    // why: original forms the address in t7 after the guard
    register f32* scale asm("$15") = &D_0037619c;
    asm("" : "+r"(scale)); // why: original keeps the full address in t7 and loads with offset 0
    register f32 multiplier asm("$f0") = *scale; // why: original loads the first scale into $f0
    register f32 product asm("$f0") = value * multiplier; // why: original keeps the first product in $f0
    // why: original forms the second address in t7 again
    register f32* factor asm("$15") = &D_003761a0;
    asm("" : "+r"(factor)); // why: original keeps the full address in t7 and loads with offset 0
    *(object + 21) = (u8)(s32)(product * *factor);
    return result;
}
