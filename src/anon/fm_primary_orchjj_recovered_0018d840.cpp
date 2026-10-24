#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_0036ccc0;
extern "C" f32 D_0036ccc4;
extern "C" u64 func_0016af58(...);
extern "C" s32 func_0016c028(s32);

kn::FVector* func_0018d840(kn::FVector* out, u8* object, s32 value) {
    kn::FVector temporary;
    if (*(u32*)(object + 0xc) != 0) {
        kn::FVector* source = (kn::FVector*)func_0016c028(value);
        kn::FVector* origin = (kn::FVector*)(*(u32*)(object + 0xc) + 0x730);
        // why: VU macro vector subtract, pattern from accepted sibling func_00159d30
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                     : : "r"(&temporary), "r"(source), "r"(origin) : "memory");
        *out = temporary;
        out->y = 0;
        register f32 length asm("$f1"); // why: original moves the unused length into $f1
        // why: VU macro normalize xyz in place, pattern from accepted sibling func_00183768
        asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                     : "=f"(length) : "r"(out) : "$8", "memory");
        f32* constant = &D_0036ccc0;
        asm("" : "+r"(constant)); // why: original forms the full address before the load
        *(f32*)&out->w = *constant;
    } else {
        kn::FVector base;
        func_0016af58(&base, value);
        f32* rate = &D_0036ccc4;
        asm("" : "+r"(rate)); // why: original forms the full address before the load
        // why: VU macro scale by a float broadcast, pattern from accepted sibling func_00159d30
        asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                     : : "r"(&temporary), "r"(&base), "f"(*rate) : "$8", "memory");
        *out = temporary;
    }
    return out;
}
