#include "../common/types.h"
struct __attribute__((aligned(16))) Vector {
    f32 v[4];
};
extern "C" void func_001cf320();
extern "C" s32 func_0019c090();
extern "C" void func_0017f488(u8*, s32, f32, f32);
extern "C" void func_0017f5e0(u8*, s32, f32, f32, void*);
extern "C" void func_0016af58(Vector*, u8*);
extern "C" void func_00186c58(u8*, Vector*, f32);
extern "C" void func_00186a90(u8*, Vector*, f32);

void func_00187018(u8* object, u8* state, s32 unused, s32 motion, f32 time) {
    Vector scaled;
    Vector source;
    if (*(u32*)(state + 4) & 0x40) {
        return;
    }
    if ((*(s32*)(*(u8**)(object + 12) + 4) ^ 0x17) == 0) {
        func_001cf320();
        return;
    }
    if (time < 0.0f) {
        time = 50.0f;
    }
    if (func_0019c090() != 0) {
        func_0017f488(object + 320, motion < 0 ? 43 : motion, 0.0f, 0.0f);
        func_0017f5e0(object + 320, 4, 0.0f, 0.0f, 0);
        if (0.0f < time) {
            func_0016af58(&source, object);
            f32 scale = -1.0f;
            // why: VU macro scale by a float broadcast, pattern from accepted 001606e0 / 00159d30
            asm volatile("lqc2 $vf1,0(%0); mfc1 $8,%1; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%2)"
                         : : "r"(&source), "f"(scale), "r"(&scaled) : "$8", "memory");
            func_00186c58(object, &scaled, time);
        }
    } else {
        func_0017f488(object + 320, motion < 0 ? 41 : motion, 0.0f, 0.0f);
        if (0.0f < time) {
            func_0016af58(&source, object);
            f32 scale = -1.0f;
            // why: VU macro scale by a float broadcast, pattern from accepted 001606e0 / 00159d30
            asm volatile("lqc2 $vf1,0(%0); mfc1 $8,%1; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%2)"
                         : : "r"(&source), "f"(scale), "r"(&scaled) : "$8", "memory");
            func_00186a90(object, &scaled, time);
        }
        func_0017f5e0(object + 320, 0, 0.0f, 0.0f, 0);
    }
    *(u32*)(state + 4) |= 0x40;
}
