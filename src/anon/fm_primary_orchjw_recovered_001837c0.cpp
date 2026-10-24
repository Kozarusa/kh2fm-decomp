#include "../common/types.h"
#include "../kn/fvector.hpp"

f32 func_001837c0(u8* object, const kn::FVector* point, f32 value) {
    kn::FVector direction;
    kn::FVector temporary;
    f32 length;
    // why: VU macro vector subtract, same sequence as accepted fm_primary_orchjj_recovered_0018df90.cpp
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(&temporary), "r"(point), "r"(object + 0x540) : "memory");
    direction = temporary;
    direction.y = 0;
    // why: VU macro normalize xyz in place, same sequence as accepted fm_primary_orchjj_recovered_0018df90.cpp
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                 : "=f"(length) : "r"(&direction) : "$8", "memory");
    *(kn::FVector*)(object + 16) = direction;
    *(f32*)(object + 28) = value;
    return length;
}
