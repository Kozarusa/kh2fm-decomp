#include "../common/types.h"
#include "../kn/fvector.hpp"

struct Shape {
    s32 kind;
    f32 x;
    f32 y;
    f32 z;
};
struct Target {
    u8 pad[12];
    Shape* shape;
};
extern "C" f32* func_002d73f0(void);
extern "C" bool func_002cee58(u8*, Shape*);

bool func_002d89b0(u8* frustum, Target* target) {
    Shape* shape = target->shape;
    if ((u32)(shape->kind - 2034) < 2) {
        return 1;
    }
    f32 x = shape->x;
    f32 y = shape->y;
    f32 z = shape->z;
    kn::FVector center;
    f32* lanes = (f32*)&center;
    lanes[0] = x;
    lanes[1] = y;
    lanes[2] = z;
    lanes[3] = 0.0f;
    kn::FVector difference;
    // why: VU macro vector subtract; the asm text is identical to the vsub.wxyz block of accepted sibling func_002c7060 (fm_primary_orchlt_recovered_002c7060.cpp); no plain C form exists for lqc2/vsub/sqc2
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.wxyz $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(&difference), "r"(frustum + 0x1c0), "r"(&center) : "memory");
    f32 length;
    // why: VU macro xyz length; the asm text is identical to the length block of accepted sibling func_001a4ff8 (fm_primary_orchjp_recovered_001a4ff8.cpp); no plain C form exists for vsqrt/cfc2
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf1,$vf1,$vf1; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; vsqrt Q,$vf1x; vwaitq; cfc2 $8,$22; mtc1 $8,%0"
                 : "=f"(length) : "r"(&difference) : "$8", "memory");
    if (func_002d73f0()[5] < length) {
        return 0;
    }
    return func_002cee58(frustum, shape);
}
