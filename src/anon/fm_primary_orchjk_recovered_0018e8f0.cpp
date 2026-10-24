#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" u32 func_001de168(u32, s32, s32, s32, s32, s32);
extern "C" kn::FVector* func_001dc5f8(u32);
extern "C" void func_001c2c00(u32);
extern "C" void func_0018efe8(u32);

void func_0018e8f0(u8* first, u32 system, s32 index, u8* second) {
    if ((*(u32*)(*(u8**)first + 4) & 0x80) != 0) {
        return;
    }
    if ((*(u32*)(*(u8**)second + 4) & 0x80) != 0) {
        return;
    }
    u8* effect = (u8*)func_001de168(system, index, 1, 1, 10000, 0);
    if (effect != 0) {
        kn::FVector direction;
        kn::FVector temporary;
        kn::FVector scaled;
        kn::FVector* origin = (kn::FVector*)(first + 32);
        // why: VU macro vector subtract, pattern from accepted sibling func_0018df90; trailing directives emit nothing and keep gas from moving sqc2 into the delay slot, as in 001605a0
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0); .set noreorder; .set reorder"
                     : : "r"(&temporary), "r"(second + 32), "r"(origin) : "memory");
        direction = temporary;
        f32 length;
        // why: VU macro normalize xyz in place, pattern from accepted sibling func_0018df90
        asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                     : "=f"(length) : "r"(&direction) : "$8", "memory");
        kn::FVector* position = func_001dc5f8((u32)effect);
        // why: VU macro scale by a float broadcast, pattern from accepted sibling func_0018d840
        asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                     : : "r"(&scaled), "r"(&direction), "f"(*(f32*)(first + 20)) : "$8", "memory");
        // why: VU macro vector add, pattern from accepted sibling func_00159d30; trailing directives emit nothing and keep gas from moving sqc2 into the delay slot, as in 001605a0
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vadd.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0); .set noreorder; .set reorder"
                     : : "r"(&temporary), "r"(origin), "r"(&scaled) : "memory");
        *position = temporary;
        func_001c2c00((u32)effect);
    }
    func_0018efe8(*(u32*)first);
    func_0018efe8(*(u32*)second);
}
