#include "../common/types.h"
extern "C" u8* D_00352130;
extern "C" u32 func_0019fdb0(u32);
extern "C" void func_0017f488(f32, f32, s32, u32);
extern "C" void func_0017f5e0(u8*, s32, f32, f32, void*);
extern "C" void func_001a2a18(u8* object);

void func_001a2910(u32 unused, u8* object) {
    u8* vector = object + 32;
    f32 length;
    // why: VU macro scale by a float broadcast, pattern from accepted sibling func_0016d760
    asm volatile("lqc2 $vf1,0(%1); mfc1 $8,%2; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%0)"
                 : : "r"(vector), "r"(vector), "f"(*(f32*)(D_00352130 + 60)) : "$8", "memory");
    // why: VU macro xyz length, sequence from accepted sibling func_001a4ff8
    asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf1,$vf1,$vf1; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; vsqrt Q,$vf1x; vwaitq; cfc2 $8,$22; mtc1 $8,%0"
                 : "=f"(length) : "r"(vector) : "$8", "memory");
    if (length < *(f32*)(object + 0xf4)) {
        u32 result = func_0019fdb0((u32)object);
        func_0017f488(0.0f, 0.0f, (s32)object + 0x140, result);
        func_0017f5e0(object + 320, 0, 0.0f, 0.0f, 0);
        func_001a2a18(object);
    }
}
