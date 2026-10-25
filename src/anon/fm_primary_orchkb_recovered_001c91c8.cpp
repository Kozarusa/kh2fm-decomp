#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" u8* D_00352130;
extern "C" void func_0017f488(u8*, s32, f32, f32);
extern "C" u32 func_0017f5e0(void*, s32, f32, f32, void*);

// why: the first argument register is never read by the original, but the object arrives in a1

u32 func_001c91c8(u8* unused, u8* object) {
    kn::FVector* dest = (kn::FVector*)(object + 0x20);
    kn::FVector temp;
    f32 scale = *(f32*)(*(u8**)(object + 300) + 0x24);
    // why: VU macro scale by a float broadcast, same sequence as accepted fm_primary_orchjv_recovered_0016d450.cpp
    asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                 : : "r"(&temp), "r"(object + 0x10), "f"(scale) : "$8", "memory");
    *dest = temp;
    *(u32*)(object + 0x10c) = (*(u32*)(object + 0x10c) | 0x10) & ~0x20;
    func_0017f488(object + 0x140, 202, 0.0f, 0.0f);
    u32 result = func_0017f5e0(object + 0x140, 201, 0.0f, 0.0f, 0);
    *(f32*)(object + 0xf0) = *(f32*)(D_00352130 + 0xc0);
    return result;
}
