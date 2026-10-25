#include "../common/types.h"
#include "../kn/fvector.hpp"
struct __attribute__((aligned(16))) Matrix { f32 columns[4][4]; };
extern "C" u8* D_00361f60;
extern "C" kn::FVector* func_00184540(kn::FVector*, u8*, f32, f32);
extern "C" void func_002e10d0(Matrix*, u8*);

kn::FVector* func_002e1908(kn::FVector* vector, s32 unused, u8* object) {
    f32 scale = 0.8f;
    func_00184540(vector, object, scale, scale);
    Matrix matrix;
    func_002e10d0(&matrix, D_00361f60);
    vector->w = 0;
    kn::FVector temp;
    // why: VU0 macro vector times matrix, same sequence as accepted fm_primary_orchjw_recovered_00173ce8.cpp
    asm volatile("lqc2 $vf5,0(%1); lqc2 $vf1,0(%2); lqc2 $vf2,16(%2); lqc2 $vf3,32(%2); lqc2 $vf4,48(%2); vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; sqc2 $vf5,0(%0)"
                 : : "r"(&temp), "r"(vector), "r"(&matrix) : "memory");
    *vector = temp;
    return vector;
}
