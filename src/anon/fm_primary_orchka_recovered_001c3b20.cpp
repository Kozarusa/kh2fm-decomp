#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_0036de14;
extern "C" f32 D_00349e10;
extern "C" f32 func_001c3ba8(u8* owner, u8* object);

kn::FVector* func_001c3b20(kn::FVector* out, u8* owner, u8* object) {
    kn::FVector copy;
    register f32* scale asm("$14") = &D_0036de14; // why: original keeps the D_0036de14 address in t6
    asm("" : "+r"(scale)); // why: original forms the full address of D_0036de14 before the load (no folded %lo)
    kn::FVector* velocity = (kn::FVector*)(object + 0x20);
    // why: VU macro scale by a float broadcast, same text and registers as accepted fm_primary_orchjv_recovered_00193be8.cpp (here in place: both operands are the velocity); trailing directives emit nothing and keep gas from moving sqc2 into the beq delay slot
    asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0); .set noreorder; .set reorder"
                 : : "r"(velocity), "r"(velocity), "f"(*scale) : "$8", "memory");
    copy = *velocity;
    *(f32*)&copy.y = func_001c3ba8(owner, object);
    // why: VU macro scale by a float broadcast into the result, same sequence and registers as accepted fm_primary_orchit_recovered_0016d760.cpp
    asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                 : : "r"(out), "r"(&copy), "f"(D_00349e10) : "$8", "memory");
    return out;
}
