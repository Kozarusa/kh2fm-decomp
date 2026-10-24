#include "../common/types.h"
#include "../kn/fvector.hpp"
struct __attribute__((aligned(16))) Matrix { f32 columns[4][4]; };
struct Entry {
    u8* owner;
    u32 id;
    kn::FVector* vector;
};
extern "C" kn::FVector D_01c5f480;
extern "C" f32 func_0016b0e0(...);

f32 func_00173ce8(Entry* entry) {
    Matrix matrix;
    kn::FVector temp;
    f32 result = func_0016b0e0(*(u8**)(entry->owner + 4), entry->id, &matrix);
    kn::FVector* vector = entry->vector;
    // why: VU0 macro vector times matrix, same sequence as accepted fm_primary_orchhh_recovered_00140500.cpp
    asm volatile("lqc2 $vf5,0(%1); lqc2 $vf1,0(%2); lqc2 $vf2,16(%2); lqc2 $vf3,32(%2); lqc2 $vf4,48(%2); vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; sqc2 $vf5,0(%0)"
                 : : "r"(&temp), "r"(vector), "r"(&matrix) : "memory");
    D_01c5f480 = temp;
    entry->owner = (u8*)&D_01c5f480;
    return result;
}
