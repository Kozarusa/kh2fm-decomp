#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_0036ced4;

f32 func_00193be8(s32 object, kn::FVector* first, kn::FVector* second, kn::FVector* matrix) {
    kn::FVector temporary;
    register f32 first_length asm("$f1"); // why: original leaves the unused first length in f1
    f32 length;
    // why: VU macro xyz outer product with zero w, same sequence as accepted fm_primary_queuezeta_recovered_0016d888.cpp; trailing directives emit nothing and keep gas from moving sqc2 into the delay slot, as in accepted fm_primary_orchii_recovered_001605a0.cpp
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf3,$vf0,$vf0; vopmula.xyz ACC,$vf1,$vf2; vopmsub.xyz $vf3,$vf2,$vf1; sqc2 $vf3,%0; .set noreorder; .set reorder"
                 : "=m"(temporary) : "r"(first), "r"(second) : "memory");
    matrix[0] = temporary;
    // why: VU macro normalize xyz in place, same sequence as accepted fm_primary_orchit_recovered_0016d760.cpp
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                 : "=f"(first_length) : "r"(&matrix[0]) : "$8", "memory");
    matrix[0].w = 0;
    kn::FVector* row2 = matrix + 2;
    f32* scale = &D_0036ced4;
    asm("" : "+r"(scale)); // why: original forms the full address before the load, as in accepted fm_primary_orchjq_recovered_0019bfd0.cpp
    // why: VU macro scale by a float broadcast, same sequence as accepted fm_primary_orchit_recovered_0016d760.cpp; trailing directives emit nothing and keep gas from moving sqc2 into the delay slot, as in accepted fm_primary_orchii_recovered_001605a0.cpp
    asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0); .set noreorder; .set reorder"
                 : : "r"(&temporary), "r"(first), "f"(*scale) : "$8", "memory");
    *row2 = temporary;
    // why: VU macro normalize xyz in place, same sequence as accepted fm_primary_orchit_recovered_0016d760.cpp
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                 : "=f"(length) : "r"(row2) : "$8", "memory");
    row2->w = 0;
    kn::FVector* row1 = matrix + 1;
    // why: VU macro xyz outer product with zero w, same sequence as accepted fm_primary_queuezeta_recovered_0016d888.cpp; trailing directives emit nothing and keep gas from moving sqc2 into the delay slot, as in accepted fm_primary_orchii_recovered_001605a0.cpp
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf3,$vf0,$vf0; vopmula.xyz ACC,$vf1,$vf2; vopmsub.xyz $vf3,$vf2,$vf1; sqc2 $vf3,%0; .set noreorder; .set reorder"
                 : "=m"(temporary) : "r"(row2), "r"(&matrix[0]) : "memory");
    *row1 = temporary;
    // why: VU macro normalize xyz in place, same sequence as accepted fm_primary_orchit_recovered_0016d760.cpp
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                 : "=f"(length) : "r"(row1) : "$8", "memory");
    row1->w = 0;
    // why: VU macro store of vf0 (0,0,0,1), same sqc2 $vf0 sequence as accepted fm_primary_orchjq_recovered_0019bfd0.cpp
    asm volatile("sqc2 $vf0,0(%0)" : : "r"(&matrix[3]) : "memory");
    return length;
}
