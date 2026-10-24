#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 func_002f8870(f32);

s32 func_0018a420(u8* object, u8* other) {
    kn::FVector difference;
    kn::FVector temporary;
    // why: VU macro vector subtract, same sequence as accepted sibling fm_primary_orchjj_recovered_0018d840.cpp; trailing directives emit nothing and keep gas from moving sqc2 into the next delay slot (precedent fm_primary_orchii_recovered_001605a0.cpp)
    asm volatile("lqc2 $vf1,0(%0); lqc2 $vf2,0(%1); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%2); .set noreorder; .set reorder"
                 : : "r"(other + 16), "r"(object + 16), "r"(&temporary) : "memory");
    difference = temporary;
    f32 height = func_002f8870(*(f32*)&difference.y);
    if (*(f32*)(object + 8) + *(f32*)(other + 8) <= height) {
        return 0;
    }
    f32 radius = *(f32*)(object + 4) + *(f32*)(other + 4);
    *(f32*)&difference.y = 0;
    register f32 dot asm("$f2"); // why: original moves the dot product into $f2
    // why: VU macro xyz dot product, same sequence as accepted sibling fm_primary_queueeta_recovered_00162b18.cpp
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vmul.xyz $vf1,$vf1,$vf2; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; qmfc2 $8,$vf1; mtc1 $8,%0"
                 : "=f"(dot) : "r"(&difference), "r"(&difference) : "$8", "memory");
    if (dot < radius * radius) {
        return 1;
    }
    return 0;
}
