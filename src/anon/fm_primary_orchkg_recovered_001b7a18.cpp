#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" f32 D_0036db30;
extern "C" u8* func_001b7998(s32* list, s32 key);
extern "C" void func_0018a7d0(u8*, s32, Quad*);
extern "C" void func_001b7b10(u8*, s32*, Quad*, Quad*);
// why: accepted fm_primary_queuezeta_recovered_001b7958.cpp has C++ linkage; v1 failed the isolated probe link, so the exact types are kept with extern "C"
extern "C" void func_001b7958(u8* object,const f32* translation);

void func_001b7a18(u8* objectArgument, s32* list, Quad* accumulator) {
    register u8* object asm("$17") = objectArgument; // why: original keeps the object in s1 and the accumulator in s2
    Quad temporary;
    Quad scaled;
    s32 index = 0;
    if (*list > 0) {
        f32* scaleAddress = &D_0036db30;
        asm("" : "+r"(scaleAddress)); // why: original forms the full address with lui+addiu and loads with a zero offset
        f32 scale = *scaleAddress;
        do {
            u8* entry = (u8*)list + index * 32 + 16;
            u8* found = func_001b7998((s32*)object, (s32)entry);
            if (found != 0) {
                func_0018a7d0(found, (s32)entry, &temporary);
                func_001b7b10(object, list, accumulator, &temporary);
                // why: VU macro scale by a float broadcast, same sequence and registers as accepted fm_primary_orchit_recovered_0016d760.cpp
                asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                             : : "r"(&scaled), "r"(&temporary), "f"(scale) : "$8", "memory");
                func_001b7958(object, (const f32*)&scaled);
                // why: VU macro vector subtract, same sequence and registers as accepted fm_primary_orchjb_recovered_0018b288.cpp
                asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                             : : "r"(accumulator), "r"(accumulator), "r"(&temporary) : "memory");
            }
            index++;
        } while (index < *list);
    }
}
