#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" s32 D_00361f60;
extern "C" kn::FVector* func_00184540(kn::FVector* out, u8* object, f32 blend, f32 scale);
// why: parameter derived from the register set before the jal (a0 = the word loaded from D_00361f60); the result is used as the matrix address by the lqc2 loads; the original of func_002e2930 is not recovered
extern "C" u8* func_002e2930(s32);

// why: the second parameter is never read (a1 is overwritten before the first call), it only keeps object in a2; the function returns its first parameter (move v0,s0), so the return is kn::FVector*

kn::FVector* func_002e2f08(kn::FVector* vector, s32 unused, u8* object) {
    func_00184540(vector, object, 0.8f, 0.8f);
    u8* matrix = func_002e2930(D_00361f60);
    vector->w = 0;
    kn::FVector transformed;
    // why: VU0 macro vector times matrix, same asm text as accepted 00140500
    asm volatile("lqc2 $vf5,0(%1); lqc2 $vf1,0(%2); lqc2 $vf2,16(%2); lqc2 $vf3,32(%2); lqc2 $vf4,48(%2); vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; sqc2 $vf5,0(%0)"
                 : : "r"(&transformed), "r"(vector), "r"(matrix) : "memory");
    *vector = transformed;
    return vector;
}
