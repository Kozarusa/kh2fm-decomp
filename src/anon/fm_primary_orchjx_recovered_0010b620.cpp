#include "../common/types.h"
#include "../kn/fvector.hpp"

f32 func_0010b620(u8* self, kn::FVector* target, kn::FVector* origin) {
    kn::FVector difference;
    kn::FVector* direction = (kn::FVector*)(self + 0x10);
    // why: VU macro vector subtract, same sequence as accepted sibling fm_primary_orchjj_recovered_0018d840.cpp
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(&difference), "r"(target), "r"(origin) : "memory");
    *direction = difference;
    *(f32*)(self + 0x0) = *(f32*)(self + 0x14);
    kn::FVector* flat = (kn::FVector*)(self + 0x20);
    *flat = *direction;
    *(u32*)(self + 0x24) = 0;
    f32 length;
    // why: VU macro normalize xyz in place, same sequence as accepted sibling fm_primary_orchjj_recovered_0018df90.cpp
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                 : "=f"(length) : "r"(direction) : "$8", "memory");
    *(f32*)(self + 0x1c) = length;
    f32 flatLength;
    // why: VU macro normalize xyz in place, same sequence as accepted sibling fm_primary_orchjj_recovered_0018df90.cpp
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                 : "=f"(flatLength) : "r"(flat) : "$8", "memory");
    *(f32*)(self + 0x2c) = flatLength;
    return length;
}
