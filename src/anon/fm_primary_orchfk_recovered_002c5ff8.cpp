#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" kn::FVector func_00143e50(u16, s32);
extern "C" u32 func_00186a90(u8*, kn::FVector*, f32);

u32 func_002c5ff8(u8* object, u32 index) {
    asm volatile("vsub.wxyz $vf1,$vf0,$vf0; sqc2 $vf1,0(%0)" : : "r"(object + 0x20) : "memory");     kn::FVector normal = func_00143e50((u16)index, 0);

         return func_00186a90(object, &normal, 1000.0f);
}
