#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" s32 func_00162560(u8* object, kn::FVector* point, kn::FVector* direction);

u32 func_00162bb0(kn::FVector* origin, u8* object, kn::FVector* direction, f32* scale, kn::FVector* out) {
    kn::FVector offset;
    kn::FVector temporary;
    // why: VU macro xyz scale by a float broadcast, same sequence as accepted fm_fallback_vector.cpp func_002f4870 (vmulx.xyz), vf1/vf2 registers as in accepted fm_primary_orchit_recovered_0016d760.cpp; trailing noreorder keeps the sqc2 out of the branch delay slot as in accepted fm_primary_orchii_recovered_001605a0.cpp
    asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyz $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0); .set noreorder; .set reorder"
                 : : "r"(&temporary), "r"(direction), "f"(*scale) : "$8", "memory");
    offset = temporary;
    // why: VU macro vector subtract, same sequence as accepted fm_primary_orchjj_recovered_0018df90.cpp
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(&temporary), "r"(origin), "r"(&offset) : "memory");
    *out = temporary;
    return func_00162560(object, out, direction) != 0;
}
