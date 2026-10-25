#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" s32 D_0034e948;
extern "C" f32 D_0036e66c;
extern "C" f32 D_0036e670;
extern "C" f32 D_0036e674;
extern "C" bool func_0019ba60(u64);
extern "C" s32 func_0016c028(s32);
extern "C" f32 func_002f8870(f32);

s32 func_001da070(s32 object) {
    s32 target = D_0034e948;
    if (!func_0019ba60(target)) {
        return 0;
    }
    s32 from = func_0016c028(target);
    s32 to = func_0016c028(object);
    kn::FVector difference;
    // why: VU macro vector subtract, same sequence as accepted fm_primary_orchjp_recovered_001a4ff8.cpp; trailing directives emit nothing and keep gas from moving sqc2 into the delay slot, as in 001605a0
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0); .set noreorder; .set reorder"
                 : : "r"(&difference), "r"(from), "r"(to) : "memory");
    register f32* offset asm("$14") = &D_0036e66c; // why: original forms this constant address in t6, as in accepted 001a4ff8
    asm("" : "+r"(offset)); // why: original forms the full constant address before the load
    *(f32*)&difference.y = *(f32*)&difference.y + *offset;
    f32 angle = func_002f8870(*(f32*)&difference.y);
    register f32* limit asm("$14") = &D_0036e670; // why: original forms this constant address in t6, as in accepted 001a4ff8
    asm volatile("" : "+r"(limit)); // why: original forms the full constant address before the load; volatile keeps later constant moves below it
    if (angle > *limit) {
        return 0;
    }
    *(f32*)&difference.y = 0.0f;
    register f32 length asm("$f1"); // why: original moves the VU length into f1, binding pattern from accepted 00116d08
    // why: VU macro xyz length, same sequence as accepted fm_primary_orchjp_recovered_001a4ff8.cpp
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf1,$vf1,$vf1; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; vsqrt Q,$vf1x; vwaitq; cfc2 $8,$22; mtc1 $8,%0"
                 : "=f"(length) : "r"(&difference) : "$8", "memory");
    f32* range = &D_0036e674;
    asm volatile("" : "+r"(range)); // why: original forms the full constant address before the load; volatile keeps later constant moves below it
    return length <= *range;
}
