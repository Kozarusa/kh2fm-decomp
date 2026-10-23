#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 func_0017ce10(f32);
extern "C" f32 func_002f8870(f32);
extern "C" f32 D_00349e10;

s32 func_00116d08(u8* object) {
    kn::FVector temporary;
    register f32 distance asm("$f2"); // why: VU distance result is moved into f2 by the sibling sequence
    // why: VU macro distance sequence copied from accepted sibling 00163210
    asm volatile("lqc2 $vf1,0(%2); lqc2 $vf2,0(%3); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,%0; lqc2 $vf1,%0; vmul.xyz $vf1,$vf1,$vf1; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; vsqrt Q,$vf1x; vwaitq; cfc2 $8,$22; mtc1 $8,%1"
                 : "=m"(temporary), "=f"(distance) : "r"(object + 1600), "r"(object + 1616) : "$8", "memory");
    if (distance < *(f32*)(object + 1576) * D_00349e10) {
        f32 angle = func_002f8870(func_0017ce10(*(f32*)&temporary.w));
        f32 scale = D_00349e10;
        if (angle < *(f32*)(object + 1580) * scale) {
            return 1;
        }
        return 0;
    }
    return 0;
}
