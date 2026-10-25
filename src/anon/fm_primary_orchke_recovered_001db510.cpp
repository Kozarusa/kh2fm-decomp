#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_0036e7ac;

f32 func_001db510(u8* object, const kn::FVector* point) {
    kn::FVector vector;
    kn::FVector temp;
    vector = *point;
    u8* matrix = object + 16;
    register f32* one asm("$12") = &D_0036e7ac; // why: original keeps the constant address in t4
    asm("" : "+r"(one)); // why: original forms the full address (lui+addiu) before lwc1 0(reg)
    *(f32*)&vector.w = *one;
    // why: VU0 macro vector times matrix, same sequence as accepted fm_primary_orchjw_recovered_00173ce8.cpp
    asm volatile("lqc2 $vf5,0(%1); lqc2 $vf1,0(%2); lqc2 $vf2,16(%2); lqc2 $vf3,32(%2); lqc2 $vf4,48(%2); vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; sqc2 $vf5,0(%0)"
                 : : "r"(&temp), "r"(&vector), "r"(matrix) : "memory");
    vector = temp;
    f32 scale = *(f32*)(object + 80);
    return (*(f32*)&vector.x + scale) / (scale + scale);
}
