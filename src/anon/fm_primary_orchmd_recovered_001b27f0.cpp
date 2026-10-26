#include "../common/types.h"
struct __attribute__((aligned(16))) FmStructureQuad { u32 words[4]; };
extern "C" u64 func_0017c030(s64, u32, void*, u32);
extern "C" void func_001b6dd0(u32, void*);
extern "C" s32 func_0017f488(f32, f32, s32, u32);

void func_001b27f0(u64 unused, u32 object, u32 byteValue) {
    FmStructureQuad input, copy, extra;
    u32 masked = byteValue & 0xff;
    func_0017c030((s64)(s32)&input, object, &extra, masked);
    // why: original copies the returned quad with lq/sq (same primitive as accepted 002f0640)
    asm volatile("lq $8,0(%1); sq $8,0(%0)"
                 : : "r"(&copy), "r"(&input) : "$8", "memory");
    func_001b6dd0(object, &copy);
    u32 first = extra.words[0];
    *(u8*)(object + 0x514) = 4;
    func_0017f488(0.0f, 0.0f, (s32)object + 0x140, first);
    *(u32*)(object + 0x100) = 4;
    *(u32*)(object + 0x104) = 5;
}
