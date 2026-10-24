#include "../common/types.h"
#include "../kn/fvector.hpp"

void func_0016da20(u32* object) {
    kn::FVector* first = (kn::FVector*)object[0];
    kn::FVector a;
    kn::FVector b;
    f32 length;
    f32 length2;
    f32 dot;
    // why: lq/sq copy primitive through t0 (plain copy picks another register), same as kn::FVector::operator=
    asm("lq $8, 0(%1); sq $8, 0(%0)" : : "r"(&a), "r"(first) : "$8");
    // why: VU macro normalize xyz in place, pattern from accepted sibling func_0016d760
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                 : "=f"(length) : "r"(&a) : "$8", "memory");
    kn::FVector* second = (kn::FVector*)object[1];
    // why: lq/sq copy primitive through t0 (plain copy picks another register), same as kn::FVector::operator=
    asm("lq $8, 0(%1); sq $8, 0(%0)" : : "r"(&b), "r"(second) : "$8");
    // why: VU macro normalize xyz in place, pattern from accepted sibling func_0016d760
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                 : "=f"(length2) : "r"(&b) : "$8", "memory");
    // why: VU macro xyz dot product, pattern from accepted sibling func_00162b18
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vmul.xyz $vf1,$vf1,$vf2; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; qmfc2 $8,$vf1; mtc1 $8,%0"
                 : "=f"(dot) : "r"(&a), "r"(&b) : "$8");
    *(f32*)&object[0] = dot;
}
