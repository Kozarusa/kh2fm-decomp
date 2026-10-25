#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" kn::FVector* func_0017fe10(kn::FVector* out, u8* motion, f32 time);
extern "C" f32 func_0017ce10(f32);

f32 func_0017fef0(u8* object, f32 rate) {
    // why: object + 0xb0 is formed before the call and copied into accumulator after it; this gives accumulator t6 and &delta t7 as in the original, while one variable (pfix2 v1) swaps t6/t7 (6 words)
    kn::FVector* slot = (kn::FVector*)(object + 0xb0);
    kn::FVector position;
    func_0017fe10(&position, object, rate);
    kn::FVector* accumulator = slot;
    kn::FVector* target = (kn::FVector*)(object + 0xa0);
    kn::FVector delta;
    // why: VU macro vector subtract; instruction text identical to accepted fm_primary_orchjj_recovered_0018df90.cpp line 11
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(&delta), "r"(&position), "r"(target) : "memory");
    // why: VU macro vector add; instruction text identical to accepted fm_primary_orchia_recovered_00159d30.cpp line 17
    asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vadd.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%0)"
                 : : "r"(accumulator), "r"(accumulator), "r"(&delta) : "memory");
    f32 angle = func_0017ce10(*(f32*)(object + 0xbc));
    *(f32*)(object + 0xbc) = angle;
    *target = position;
    return angle;
}
