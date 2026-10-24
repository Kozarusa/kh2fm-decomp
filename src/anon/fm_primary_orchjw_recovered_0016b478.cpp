#include "../common/types.h"
#include "../kn/fvector.hpp"
struct __attribute__((aligned(16))) Matrix { f32 columns[4][4]; };
extern "C" f32 D_0036c1e8;
extern "C" f32 func_0016b0e0(...);

kn::FVector* func_0016b478(kn::FVector* out, u8* object, u32 id, f32 scale) {
    Matrix matrix;
    kn::FVector temp;
    f32 value = func_0016b0e0(object, id, &matrix);
    f32* lanes = (f32*)out;
    register const f32* constant asm("$14") = &D_0036c1e8; // why: original forms the constant address in t6
    asm("" : "+r"(constant)); // why: original forms the full address before the lwc1
    out->y = 0;
    out->z = 0;
    lanes[3] = *constant;
    lanes[0] = value * scale;
    // why: VU0 macro vector times matrix, same sequence as accepted fm_primary_orchhh_recovered_00140500.cpp
    asm volatile("lqc2 $vf5,0(%1); lqc2 $vf1,0(%2); lqc2 $vf2,16(%2); lqc2 $vf3,32(%2); lqc2 $vf4,48(%2); vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; sqc2 $vf5,0(%0)"
                 : : "r"(&temp), "r"(out), "r"(&matrix) : "memory");
    *out = temp;
    return out;
}
