#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_0037575c;
extern "C" kn::FVector func_00143e50(u16, s32);
extern "C" u32 func_00186a90(u8*, kn::FVector*, f32);

u32 func_002c5ff8(u8* object, u32 index) {
    asm volatile("vsub.wxyz $vf1,$vf0,$vf0; sqc2 $vf1,0(%0)" : : "r"(object + 0x20) : "memory"); // why: original zero-fills vector with VU macro, pattern from queueeta 00167658
    kn::FVector normal = func_00143e50((u16)index, 0);
    f32* limit = &D_0037575c;
    asm("" : "+r"(limit)); // why: keeps global address formed separately from the load
    return func_00186a90(object, &normal, *limit);
}
