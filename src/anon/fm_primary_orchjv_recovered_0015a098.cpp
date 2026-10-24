#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" kn::FVector D_0034aa50[];
extern "C" f32 D_0036b38c;
extern "C" f32 func_002f8ad0(f32,f32);

f32 func_0015a098() {
    // why: the original copies the first vector to sp+0 and sets its w, but never reads it back
    kn::FVector start;
    kn::FVector direction;
    kn::FVector difference;
    kn::FVector* out = &direction; // why: pointer temporary keeps &direction in its own register (t4) from the first delay slot, as in the original
    start = D_0034aa50[0];
    // why: VU macro vector subtract, same sequence as accepted fm_primary_orchjj_recovered_0018df90.cpp; operands listed sources first so the table address is formed before the destination, as in the original
    asm volatile("lqc2 $vf1,0(%0); lqc2 $vf2,0(%1); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%2)"
                 : : "r"(&D_0034aa50[1]), "r"(&D_0034aa50[0]), "r"(&difference) : "memory");
    *out = difference;
    f32* source = &D_0036b38c;
    asm("" : "+r"(source)); // why: original forms the full address before the load, as in accepted fm_primary_orchjq_recovered_0019bfd0.cpp
    f32 w = *source;
    *(f32*)&direction.w = w; // why: direction w is written first so the scheduler emits the sp+12 store before the branch and sp+28 in its delay slot, as in the original
    *(f32*)&start.w = w;
    difference = *out;
    return func_002f8ad0(*(f32*)&difference.x, *(f32*)&difference.z);
}
