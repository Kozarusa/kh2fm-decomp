#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" void func_0016bd60(u32, s32);  // copied from accepted fm_primary_animation_recovered.cpp

void func_0019fdc0(u8* object, kn::FVector* direction, f32 value) {
    kn::FVector scaled;
    f32 scale = *(f32*)&direction->w;
    f32 length; // why: receives the vector length the normalize sequence moves to an f register; the original never uses it
    // why: VU macro normalize xyz in place, same sequence as accepted fm_primary_orchit_recovered_0016d760.cpp
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                 : "=f"(length) : "r"(direction) : "$8", "memory");
    kn::FVector* target = (kn::FVector*)(object + 0x20);
    asm volatile("" : "+r"(target)); // why: original forms the destination address before the scale, as in accepted fm_primary_orchjq_recovered_0019bfd0.cpp
    // why: VU macro scale by a float broadcast, same sequence as accepted fm_primary_orchit_recovered_0016d760.cpp
    asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                 : : "r"(&scaled), "r"(direction), "f"(scale) : "$8", "memory");
    *target = scaled;
    *(f32*)(object + 0xf0) = value;
    func_0016bd60((u32)object, 5);
}
