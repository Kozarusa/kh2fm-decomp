#include "../common/types.h"
#include "../kn/fvector.hpp"

kn::FVector func_001840c0(u8* object, kn::FVector* direction) {
    f32 length;
    // why: VU macro normalize xyz in place, identical sequence in accepted sibling fm_primary_orchit_recovered_0016d760.cpp
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                 : "=f"(length) : "r"(direction) : "$8", "memory");
    kn::FVector* axis = (kn::FVector*)(object + 0x630);
    kn::FVector side;
    kn::FVector temporary;
    // why: VU macro cross product with zero w, identical sequence in accepted sibling fm_primary_queuezeta_recovered_0016d888.cpp; trailing directives emit nothing and keep gas from moving sqc2 into the delay slot, as in accepted 00191218/001605a0
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf3,$vf0,$vf0; vopmula.xyz ACC,$vf1,$vf2; vopmsub.xyz $vf3,$vf2,$vf1; sqc2 $vf3,0(%0); .set noreorder; .set reorder"
                 : : "r"(&temporary), "r"(axis), "r"(direction) : "memory");
    side = temporary;
    // why: the normalize sequence writes its length although only the unit vector is used here
    f32 sideLength;
    // why: VU macro normalize xyz in place, identical sequence in accepted sibling fm_primary_orchit_recovered_0016d760.cpp
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                 : "=f"(sideLength) : "r"(&side) : "$8", "memory");
    // why: VU macro cross product with zero w, identical sequence in accepted sibling fm_primary_queuezeta_recovered_0016d888.cpp; trailing directives emit nothing and keep gas from moving sqc2 into the delay slot, as in accepted 00191218/001605a0
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf3,$vf0,$vf0; vopmula.xyz ACC,$vf1,$vf2; vopmsub.xyz $vf3,$vf2,$vf1; sqc2 $vf3,0(%0); .set noreorder; .set reorder"
                 : : "r"(&temporary), "r"(&side), "r"(axis) : "memory");
    *direction = temporary;
    // why: the normalize sequence writes its length although only the unit vector is used here
    f32 upLength;
    // why: VU macro normalize xyz in place, identical sequence in accepted sibling fm_primary_orchit_recovered_0016d760.cpp
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                 : "=f"(upLength) : "r"(direction) : "$8", "memory");
    // why: VU macro scale by a float broadcast, identical sequence in accepted sibling fm_primary_orchit_recovered_0016d760.cpp
    asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                 : : "r"(direction), "r"(direction), "f"(length) : "$8", "memory");
    kn::FVector result;
    asm volatile("lq $8, 0(%1);" "sq $8, 0(%0);" : : "r"(&result), "r"(direction) : "t0", "memory"); // why: FVector copy without self-check, primitive from accepted fm_primary_orchie_recovered_0015d058.cpp
    return result;
}
