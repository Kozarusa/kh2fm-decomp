#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" s32 func_0016c028(s32);
extern "C" s32 func_00177860(...);
extern "C" f32 func_002f8870(f32);
extern "C" f32 D_0036d4b0;
extern "C" f32 D_0036d4b4;

s32 func_001a4ff8(u8* object, kn::FVector* target, f32 range, f32 angle) {
    if ((*(u32*)(object + 2040) & 4) != 0) {
        return 0;
    }
    if ((*(u32*)(*(u8**)(object + 12) + 8) & 0x40000) != 0) {
        return 1;
    }
    if (range <= 0.0f) {
        register f32* constant asm("$14") = &D_0036d4b0; // why: original forms the constant address in t6
        asm("" : "+r"(constant)); // why: original forms the full address before the load
        f32 base = *constant;
        range = base;
        if ((*(u32*)(object + 1416) & 4) != 0) {
            u8* ability = (u8*)func_00177860();
            range = *(f32*)(ability + 52) + base;
        }
    }
    u8* bonus = *(u8**)(object + 1164);
    if (bonus != 0) {
        range = range + *(f32*)(bonus + 452);
    }
    if (angle <= 0.0f) {
        f32* fallback = &D_0036d4b4;
        asm("" : "+r"(fallback)); // why: original forms the full address before the load
        angle = *fallback;
    }
    kn::FVector* base = (kn::FVector*)func_0016c028((s32)object);
    kn::FVector difference;
    kn::FVector temporary;
    // why: VU macro vector subtract, pattern from accepted sibling func_0018e8f0; trailing directives emit nothing and keep gas from moving sqc2 into the delay slot, as in 001605a0
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0); .set noreorder; .set reorder"
                 : : "r"(&temporary), "r"(target), "r"(base) : "memory");
    difference = temporary;
    if (angle < func_002f8870(*(f32*)&difference.y)) {
        return 0;
    }
    *(f32*)&difference.y = 0.0f;
    f32 length;
    // why: VU macro xyz length, sequence from accepted sibling func_00116d08
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf1,$vf1,$vf1; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; vsqrt Q,$vf1x; vwaitq; cfc2 $8,$22; mtc1 $8,%0"
                 : "=f"(length) : "r"(&difference) : "$8", "memory");
    if (length <= range) {
        return 1;
    }
    return 0;
}
