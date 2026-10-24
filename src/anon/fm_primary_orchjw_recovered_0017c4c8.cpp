#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_0036c514;
// why: the accepted placeholder `extern "C" u32 func_0017c430(...);` promotes the f32 argument to double through an extra fptodp call (v1 proof orch1_vu4_0017c4c8_v1.verification.json); parameters are register-derived (a0 object, $f12 value), the accepted u32 return type is kept
extern "C" u32 func_0017c430(u8*, f32);

void func_0017c4c8(u8* object, kn::FVector* vector) {
    f32* lanes = (f32*)vector;
    kn::FVector scaled;
    func_0017c430(object, lanes[1]);
    vector->y = 0;
    f32 scale = lanes[3];
    register f32 length asm("$f1"); // why: original moves the unused length into $f1
    // why: VU macro normalize xyz in place, same sequence as accepted fm_primary_orchit_recovered_0016d760.cpp
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
                 : "=f"(length) : "r"(vector) : "$8", "memory");
    kn::FVector* destination = (kn::FVector*)(object + 192);
    // why: VU macro scale by a float broadcast, same sequence as accepted fm_primary_orchit_recovered_0016d760.cpp; destination is an unused input so its address is formed first, as in accepted fm_primary_orchhh_recovered_00140500.cpp
    asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                 : : "r"(&scaled), "r"(vector), "f"(scale), "r"(destination) : "$8", "memory");
    *destination = scaled;
    const f32* constant = &D_0036c514;
    asm("" : "+r"(constant)); // why: original forms the full address before the lwc1
    *(f32*)(object + 204) = *constant;
}
