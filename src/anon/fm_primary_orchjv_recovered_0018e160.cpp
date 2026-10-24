#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_0036cccc;
extern "C" f32 func_002f8870(f32);

kn::FVector* func_0018e160(kn::FVector* out, u8* object, f32* shape) {
    kn::FVector delta;
    kn::FVector temporary;
    kn::FVector* base = (kn::FVector*)(shape + 4);
    // why: VU macro vector subtract, same sequence as accepted fm_primary_orchjj_recovered_0018df90.cpp
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(&temporary), "r"(object + 0x20), "r"(base) : "memory");
    delta = temporary;
    f32 limit = shape[2];
    f32 height = *(f32*)&delta.y;
    f32 clamped;
    if (height < -limit) {
        clamped = -limit;
    } else if (limit < height) {
        clamped = limit;
    } else {
        clamped = height;
    }
    f32 angle = func_002f8870(clamped / limit);
    angle = angle * angle;
    delta.y = 0;
    f32* one = &D_0036cccc;
    asm("" : "+r"(one)); // why: original forms the full address before the load, as in accepted fm_primary_orchjq_recovered_0019bfd0.cpp
    f32 radius = __builtin_sqrtf(*one - angle);
    f32 length;
    // why: VU macro normalize xyz in place, same sequence as accepted fm_primary_orchjj_recovered_0018df90.cpp
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                 : "=f"(length) : "r"(&delta) : "$8", "memory");
    // why: VU macro scale by a float broadcast, same sequence as accepted fm_primary_orchia_recovered_00159d30.cpp
    asm volatile("lqc2 $vf1,0(%0); mfc1 $8,%1; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                 : : "r"(&delta), "f"(shape[1] * radius) : "$8", "memory");
    *(f32*)&delta.y = clamped;
    // why: VU macro vector add, same sequence as accepted fm_primary_orchia_recovered_00159d30.cpp
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vadd.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(out), "r"(base), "r"(&delta) : "memory");
    return out;
}
