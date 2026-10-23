#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" u32 func_00159ce0(s32, s64);

u32 func_00159d30(s32 object, kn::FVector* target, kn::FVector* out, f32 rate) {
    kn::FVector base;
    kn::FVector delta;
    kn::FVector result;
    u32 value = func_00159ce0(object, (s32)&base);
    // why: VU macro vector subtract, pattern from accepted siblings func_00178570 and fm_fallback_vector
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(&delta), "r"(target), "r"(&base) : "memory");
    // why: VU macro scale by a float broadcast, pattern from accepted sibling func_001c6400
    asm volatile("lqc2 $vf1,0(%0); mfc1 $8,%1; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                 : : "r"(&delta), "f"(rate) : "$8", "memory");
    // why: VU macro vector add, pattern from accepted sibling fm_fallback_vector
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vadd.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(&result), "r"(&base), "r"(&delta) : "memory");
    *out = result;
    return value;
}
