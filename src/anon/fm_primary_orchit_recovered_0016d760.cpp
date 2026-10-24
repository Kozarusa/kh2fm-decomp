#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_00349e10;

void func_0016d760(u32* object) {
    kn::FVector* direction = (kn::FVector*)object[1];
    kn::FVector* position = (kn::FVector*)object[0];
    kn::FVector unit;
    kn::FVector step;
    kn::FVector scaled;
    f32 length;
    // why: lq/sq copy primitive through t0 (plain copy picks another register), same as kn::FVector::operator=
    asm("lq $8, 0(%1); sq $8, 0(%0)" : : "r"(&unit), "r"(direction) : "$8");
    // why: VU macro normalize xyz in place, pattern from accepted sibling func_00183768
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                 : "=f"(length) : "r"(&unit) : "$8", "memory");
    // why: VU macro scale by a float broadcast, pattern from accepted sibling func_001c6400
    asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                 : : "r"(&scaled), "r"(&unit), "f"(*(f32*)&object[2]) : "$8", "memory");
    // why: VU macro scale by a float broadcast, pattern from accepted sibling func_001c6400
    asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                 : : "r"(&step), "r"(&scaled), "f"(D_00349e10) : "$8", "memory");
    // why: VU macro vector add, pattern from accepted sibling func_001b7958
    asm volatile("lqc2 $vf1,0(%0); lqc2 $vf2,0(%1); vadd.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(position), "r"(&step) : "memory");
}
