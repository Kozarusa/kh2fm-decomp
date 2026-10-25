#include "../common/types.h"
extern "C" f32 D_00349e10;
extern "C" f32 D_0036de08;
extern "C" void func_0017f488(u8*, s32, f32, f32);
extern "C" s32 func_0017f5e0(u8*, s32, s32, f32, f32);

// why: void under the second mixed-exit ruling (early exits leave the caller's v0 untouched, the last exit tail-calls func_0017f5e0)
// why: a0 is never read; the object arrives in a1 (same layout as accepted func_002c17d8)

void func_001c38c0(u32 unused, u8* object) {
    f32 value = 0.0f;
    f32 timer = *(f32*)(object + 0xf4);
    if (!(value < timer)) {
        return;
    }
    if (*(u32*)(object + 0x10c) & 4) {
        value = timer - D_00349e10;
    }
    *(f32*)(object + 0xf4) = value;
    f32 zero = 0.0f;
    // why: original reloads the stored timer before the compare
    if (!(*(volatile f32*)(object + 0xf4) <= zero)) {
        return;
    }
    *(f32*)(object + 0xf0) = *(f32*)(object + 0xf8);
    u8* motion = object + 0x140;
    func_0017f488(motion, 0xcc, zero, zero);
    f32* speed = &D_0036de08;
    asm("" : "+r"(speed)); // why: original forms the full address of D_0036de08 before the load
    func_0017f5e0(motion, 4, 0, *speed, zero);
}
