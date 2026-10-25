#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" u32 func_0016bc20(u64,u64,u32); // copied from accepted caller fm_primary_fiveword_recovered_0017a8f8.cpp
extern "C" s32 func_0016c028(s32);          // copied from accepted caller fm_primary_fiveword_recovered_0016fa58.cpp

// Returns 1 when the target lies within the radius of the tracked entry, 0 otherwise.

s32 func_002d56a0(u8* object) {
    s32 result = 0;
    u8* position = object + 0x540;
    if (*(s32*)(object + 0xc1c) != 0) {
        f32 radius = *(s16*)(func_0016bc20(*(s32*)(object + 0xc1c), 5, -1) + 0x10);
        kn::FVector* base = (kn::FVector*)func_0016c028(*(s32*)(object + 0xc1c));
        kn::FVector difference;
        // why: VU macro vector subtract; same four instructions as the subtract block of accepted func_001bf378 (fm_primary_orchkj_recovered_001bf378.cpp), but that sibling's text also ends with ".set noreorder; .set reorder", which this source omits because those directives emit no instruction (probe exact)
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                     : : "r"(&difference), "r"(position), "r"(base) : "memory");
        f32 length;
        // why: VU macro xyz length; text identical to the length block of accepted func_001bf378 (fm_primary_orchkj_recovered_001bf378.cpp)
        asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf1,$vf1,$vf1; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; vsqrt Q,$vf1x; vwaitq; cfc2 $8,$22; mtc1 $8,%0"
                     : "=f"(length) : "r"(&difference) : "$8", "memory");
        result = length < radius;
    }
    return result;
}
