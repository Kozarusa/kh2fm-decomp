#include "../common/types.h"
extern "C" void func_0017f488(u8*, s32, f32, f32);
extern "C" s32 func_0017f5e0(u8*, s32, s32, f32, f32);

s32 func_002c17d8(u32 unused, u8* object) {
    u8* target = object + 0x20;
    *(u32*)(object + 0x108) |= 2;
    asm volatile("vsub.wxyz $vf1,$vf0,$vf0; sqc2 $vf1,0(%0)" : : "r"(target) : "memory"); // why: original zero-fills vector with VU macro, pattern from queueeta 00167658
    f32 zero = 0.0f;
    u8* motion = object + 0x140;
    func_0017f488(motion, 0xa1, zero, zero);
    return func_0017f5e0(motion, 0, 0, zero, zero);
}
