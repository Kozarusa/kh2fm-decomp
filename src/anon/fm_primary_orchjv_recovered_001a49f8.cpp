#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_0036d49c;
extern "C" f32 D_0036d4a0;
extern "C" u64 func_0016af58(...);
extern "C" s32 func_0016c028(s32);

kn::FVector* func_001a49f8(kn::FVector* result, u8* object, s32 target) {
    kn::FVector temporary;
    kn::FVector buffer;
    u32 flags = *(u32*)(object + 4);
    if ((flags & 0x20) != 0) {
        func_0016af58(&buffer, target);
        f32* scale = &D_0036d49c;
        asm("" : "+r"(scale)); // why: original forms the full address before the load, as in accepted fm_primary_orchjq_recovered_0019bfd0.cpp
        // why: VU macro scale by a float broadcast, same sequence as accepted fm_primary_orchit_recovered_0016d760.cpp
        asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                     : : "r"(&temporary), "r"(&buffer), "f"(*scale) : "$8", "memory");
    } else if ((flags & 4) != 0) {
        // why: VU macro vector subtract, same sequence as accepted fm_primary_orchjk_recovered_00191218.cpp; trailing directives emit nothing and keep gas from moving sqc2 into the delay slot, as in accepted fm_primary_orchii_recovered_001605a0.cpp
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0); .set noreorder; .set reorder"
                     : : "r"(&temporary), "r"(object + 0xe0), "r"(object + 0xf0) : "memory");
    } else {
        s32 position = func_0016c028(target);
        // why: VU macro vector subtract, same sequence as accepted fm_primary_orchjk_recovered_00191218.cpp; trailing directives emit nothing and keep gas from moving sqc2 into the delay slot, as in accepted fm_primary_orchii_recovered_001605a0.cpp
        asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0); .set noreorder; .set reorder"
                     : : "r"(&temporary), "r"(position), "r"(object + 0xe0) : "memory");
    }
    *result = temporary;
    if (((f32*)result)[0] == 0.0f && ((f32*)result)[2] == 0.0f) {
        func_0016af58(&buffer, target);
        f32* scale = &D_0036d49c;
        asm("" : "+r"(scale)); // why: original forms the full address before the load, as in accepted fm_primary_orchjq_recovered_0019bfd0.cpp
        // why: VU macro scale by a float broadcast, same sequence as accepted fm_primary_orchit_recovered_0016d760.cpp
        asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                     : : "r"(&temporary), "r"(&buffer), "f"(*scale) : "$8", "memory");
        *result = temporary;
    }
    result->y = 0;
    f32 length;
    // why: VU macro normalize xyz in place, same sequence as accepted fm_primary_orchit_recovered_0016d760.cpp
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                 : "=f"(length) : "r"(result) : "$8", "memory");
    f32* weight = &D_0036d4a0;
    asm("" : "+r"(weight)); // why: original forms the full address before the load, as in accepted fm_primary_orchjq_recovered_0019bfd0.cpp
    ((f32*)result)[3] = *weight;
    return result;
}
