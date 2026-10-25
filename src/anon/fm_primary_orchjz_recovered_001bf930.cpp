#include "../common/types.h"
extern "C" f32 D_0036dcd4;
extern "C" f32 D_0036dcd8;
extern "C" s32 func_0016c028(s32);
extern "C" u32 func_002bc188(u64,u64);

// why: the first argument (a0) is never read; the object arrives in a1

void func_001bf930(u32 unused, u8* object) {
    f32* limit = &D_0036dcd4;
    asm("" : "+r"(limit)); // why: original forms the global address separately from the load
    if (*limit < *(f32*)(object + 36)) {
        s32 count = *(s32*)(object + 2532);
        f32* scale = &D_0036dcd8;
        asm("" : "+r"(scale)); // why: original forms the global address separately from the load
        f32 product = *(f32*)(object + 36) * *scale;
        *(f32*)(object + 36) = product;
        asm("" : "+r"(count) : "f"(product)); // why: original tests the count after the multiply
        if (count < 2) {
            func_002bc188(14, func_0016c028((s32)object));
            count = *(s32*)(object + 2532);
        }
        *(s32*)(object + 2532) = count + 1;
    } else {
        *(u32*)(object + 2528) |= 1;
        // why: original zero-fills vector with VU macro, identical sequence (vf1, vf0, sqc2) to accepted 002c5ff8 (fm_primary_orchfk_recovered_002c5ff8.cpp)
        asm volatile("vsub.wxyz $vf1,$vf0,$vf0; sqc2 $vf1,0(%0)" : : "r"(object + 0x20) : "memory");
    }
    *(u32*)(object + 264) |= 0x8000000;
}
