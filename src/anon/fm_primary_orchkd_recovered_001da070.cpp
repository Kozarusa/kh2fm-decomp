#include "../common/types.h"
extern "C" s32 D_0034e948;
extern "C" bool func_0019ba60(u64);
extern "C" s32 func_0016c028(s32);
extern "C" f32 func_002f8870(f32);

struct __attribute__((aligned(16))) Vector4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

s32 func_001da070(s32 object) {
    s32 target = D_0034e948;
    if (!func_0019ba60(target)) {
        return 0;
    }
    s32 from = func_0016c028(target);
    s32 to = func_0016c028(object);
    Vector4 difference;
    // VU macro vector subtract, same sequence as accepted fm_primary_orchjp_recovered_001a4ff8.cpp; trailing directives emit nothing and keep gas from moving sqc2 into the delay slot, as in 001605a0
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0); .set noreorder; .set reorder"
                 : : "r"(&difference), "r"(from), "r"(to) : "memory");
    difference.y = difference.y + -50.0f;
    f32 angle = func_002f8870(difference.y);
    if (angle > 90.0f) {
        return 0;
    }
    difference.y = 0.0f;
    f32 length;
    // VU macro xyz length, same sequence as accepted fm_primary_orchjp_recovered_001a4ff8.cpp
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf1,$vf1,$vf1; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; vsqrt Q,$vf1x; vwaitq; cfc2 $8,$22; mtc1 $8,%0"
                 : "=f"(length) : "r"(&difference) : "$8", "memory");
    return length <= 80.0f;
}
