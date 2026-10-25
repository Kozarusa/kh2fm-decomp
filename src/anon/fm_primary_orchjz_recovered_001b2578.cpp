#include "../common/types.h"
#include "../kn/fvector.hpp"

struct PointRing {
    s32 unknown0;
    s32 count;
    s32 unknown8;
    s32 index;
    f32 radius;
    kn::FVector* points;
};

kn::FVector* func_001b2578(PointRing* ring, kn::FVector* target) {
    kn::FVector vector;
    kn::FVector temporary;
    kn::FVector* point = &vector;
    // why: VU macro vector subtract, pattern from accepted sibling func_00191218; trailing directives emit nothing and keep gas from moving sqc2 into the delay slot, as in 001605a0
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0); .set noreorder; .set reorder"
                 : : "r"(&temporary), "r"(&ring->points[ring->index]), "r"(target) : "memory");
    *point = temporary;
    f32 length;
    // why: VU macro vector length, pattern from accepted sibling func_00191218
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf1,$vf1,$vf1; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; vsqrt Q,$vf1x; vwaitq; cfc2 $8,$22; mtc1 $8,%0"
                 : "=f"(length) : "r"(point) : "$8", "memory");
    if (length <= ring->radius) {
        ring->index = (ring->index + 1) % ring->count;
    }
    return &ring->points[ring->index];
}
