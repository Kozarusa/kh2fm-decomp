#include "../common/types.h"
#include "../kn/fvector.hpp"
typedef void (*FillVector)(kn::FVector*, u8*);

kn::FVector* func_0018df90(kn::FVector* out, u8* object, u8* source) {
    kn::FVector temporary;
    kn::FVector position;
    kn::FVector* origin = (kn::FVector*)(*(u32*)(object + 0xc) + 0x730);
    (*(FillVector*)(*(u8**)source + 8))(&position, source);
    // why: VU macro vector subtract, pattern from accepted sibling func_00159d30
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(&temporary), "r"(origin), "r"(&position) : "memory");
    *out = temporary;
    out->y = 0;
    f32 length;
    // why: VU macro normalize xyz in place, pattern from accepted sibling func_00183768
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                 : "=f"(length) : "r"(out) : "$8", "memory");
    return out;
}
