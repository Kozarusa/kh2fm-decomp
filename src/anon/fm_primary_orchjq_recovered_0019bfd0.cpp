#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_0036d3a0;
extern "C" f32 D_0036d3a4;
extern "C" u64 func_00185118(...);
extern "C" u64 func_00143928(...);

s32 func_0019bfd0(u8* object, kn::FVector* target) {
    func_00185118(object);
    kn::FVector* motion = (kn::FVector*)(object + 0x590);
    *motion = *target;
    f32* weight = &D_0036d3a0;
    asm("" : "+r"(weight)); // why: original forms the full address before the load
    *(f32*)(object + 0x59c) = *weight;
    // why: VU macro store of vf0 (0,0,0,1), sqc2 pattern from accepted sibling func_001a4ff8
    asm volatile("sqc2 $vf0,0(%0)" : : "r"(object + 0x5a0) : "memory");
    *(u64*)(object + 0x600) |= 1;
    func_00143928(motion);
    kn::FVector difference;
    // why: VU macro vector subtract, pattern from accepted sibling func_001a4ff8
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(&difference), "r"(object + 0x5c0), "r"(target) : "memory");
    f32 length;
    // why: VU macro xyz length, sequence from accepted sibling func_001a4ff8
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf1,$vf1,$vf1; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; vsqrt Q,$vf1x; vwaitq; cfc2 $8,$22; mtc1 $8,%0"
                 : "=f"(length) : "r"(&difference) : "$8", "memory");
    f32* limit = &D_0036d3a4;
    asm volatile("" : "+r"(limit)); // why: original forms the full address before the load, after the length transfer
    return length < *limit;
}
