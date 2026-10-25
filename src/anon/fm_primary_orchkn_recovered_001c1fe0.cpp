#include "../common/types.h"
#include "../kn/fvector.hpp"

struct Source;
struct SourceVtable {
    u8 pad[8];
    void (*position)(kn::FVector*, Source*);
};
struct Source {
    SourceVtable* vtable;
};

extern "C" f32 D_0036dd84;
extern "C" void func_0016be98(...);
extern "C" u32 func_0016aef0(u8*, kn::FVector*);

// why: returns func_0016aef0's u32 result (the only exit, direct); the void declarations at fm_primary_animation_recovered.cpp:7 and fm_primary_floatload_recovered.cpp:7 only discard the result

u32 func_001c1fe0(u8* object) {
    kn::FVector direction;
    kn::FVector temporary;
    kn::FVector target;
    kn::FVector origin;
    register kn::FVector* first asm("$16") = &target; // why: original keeps the first vector's address in s0
    Source* source = *(Source**)(object + 0xaac);
    source->vtable->position(first, source);
    func_0016be98(&origin, object);
    // why: VU macro vector subtract, same sequence as accepted fm_primary_orchjk_recovered_0018e8f0.cpp; trailing directives emit nothing and keep gas from moving sqc2 into the delay slot
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0); .set noreorder; .set reorder"
                 : : "r"(&temporary), "r"(first), "r"(&origin) : "memory");
    direction = temporary;
    f32 length;
    // why: VU macro normalize xyz in place, same sequence as accepted fm_primary_orchjk_recovered_0018e8f0.cpp
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                 : "=f"(length) : "r"(&direction) : "$8", "memory");
    register s32 kind asm("$14") = *(s32*)(object + 0xab8); // why: original loads the compared word into t6
    register f32* rate asm("$15") = &D_0036dd84; // why: original forms the float's address in t7 before reusing t7 for the constant
    asm("" : "+r"(rate)); // why: original forms the full address before the load
    f32 scale = *rate;
    register s32 expected asm("$15") = 21; // why: original reuses t7 for the compared constant after the float load
    if (kind == expected) {
        // why: VU macro scale by a float broadcast, same sequence as accepted fm_primary_orchjv_recovered_0018e160.cpp
        asm volatile("lqc2 $vf1,0(%0); mfc1 $8,%1; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                     : : "r"(&direction), "f"(scale) : "$8", "memory");
        register u32 unused asm("$19"); // why: original saves s3 although no instruction uses it
        asm volatile("" : "=r"(unused)); // why: marks s3 as written so the prologue saves it, emits nothing; kept off the join block so the branch delay slot can take its first move
    }
    return func_0016aef0(object, &direction);
}
