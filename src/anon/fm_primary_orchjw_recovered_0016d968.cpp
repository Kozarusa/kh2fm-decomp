#include "../common/types.h"
#include "../kn/fvector.hpp"
struct __attribute__((aligned(16))) Matrix { kn::FVector rows[4]; };
extern "C" f32 D_0036c240;
extern "C" void func_0011b6a8(void*);

void func_0016d968(u8* object) {
    Matrix matrix;
    kn::FVector scale;
    func_0011b6a8(&matrix);
    f32 value = *(f32*)(object + 4);
    f32* lanes = (f32*)&scale;
    scale.w = 0;
    lanes[0] = value;
    lanes[1] = value;
    lanes[2] = value;
    // why: VU macro row scale by vector lanes, same sequence as accepted fm_primary_orchij_recovered_001604f8.cpp
    asm volatile("lqc2 $vf4,0(%1); lqc2 $vf1,0(%0); lqc2 $vf2,16(%0); lqc2 $vf3,32(%0); vmulx.xyzw $vf1,$vf1,$vf4x; vmuly.xyzw $vf2,$vf2,$vf4y; vmulz.xyzw $vf3,$vf3,$vf4z; sqc2 $vf1,0(%0); sqc2 $vf2,16(%0); sqc2 $vf3,32(%0)"
                 : : "r"(&matrix), "r"(&scale) : "memory");
    // why: the scaled matrix is never read again; the original still copies row 3 and sets its w, so these local stores are kept
    matrix.rows[3] = **(kn::FVector**)object;
    const f32* constant = &D_0036c240;
    asm("" : "+r"(constant)); // why: original forms the full address before the lwc1
    *(f32*)&matrix.rows[3].w = *constant;
    s32 count = 4;
    do {
        count--;
        asm volatile("" : "+r"(count)); // why: original keeps the empty delay loop (and the dead +60 store before it), an empty body is deleted
    } while (count >= 2);
}
