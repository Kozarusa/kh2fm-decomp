#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" s32 func_0016c028(s32);
extern "C" void func_0018b008(void* self); // why: exact accepted type from misc_1.cpp; C++ linkage fails the isolated probe link
typedef void (*DirectionHandler)(u8*, kn::FVector*, s32, kn::FVector*);

void func_0018b010(u8* object, kn::FVector* target, s32 value) {
    register u32 spare asm("$16"); // why: original saves s0 without using it
    asm volatile("" : "=r"(spare)); // why: empty definition marks s0 live so the frame saves it as in the original
    kn::FVector direction;
    kn::FVector difference;
    kn::FVector* origin = (kn::FVector*)func_0016c028((s32)object);
    // why: VU macro vector subtract, same sequence as accepted sibling fm_primary_orchjj_recovered_0018d840.cpp; trailing directives emit nothing and keep gas from moving sqc2 into the next delay slot (precedent fm_primary_orchii_recovered_001605a0.cpp)
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0); .set noreorder; .set reorder"
                 : : "r"(&difference), "r"(target), "r"(origin) : "memory");
    direction = difference;
    // why: asm output only; the original moves the unused length into $f0
    f32 length;
    // why: VU macro normalize xyz in place, same sequence as accepted sibling fm_primary_orchjj_recovered_0018df90.cpp
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                 : "=f"(length) : "r"(&direction) : "$8", "memory");
    // why: accepted definition (misc_1.cpp) declares one void* parameter; the original sets a0-a3 for this call
    ((DirectionHandler)func_0018b008)(object, &direction, value, target);
}
