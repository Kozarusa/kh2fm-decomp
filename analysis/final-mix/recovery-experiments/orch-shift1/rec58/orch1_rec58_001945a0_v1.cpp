#include "../common/types.h"
extern "C" f32 D_0036cf00;
extern "C" u32 func_001ad990(f32, f32, f32, void*);
extern "C" u64 func_001bfd60(...);

void func_001945a0(f32 scale, s32 base, s32 unused, u32 value) {
    u8* record = (u8*)func_001bfd60(base + 0x8e0);
    record[4] = value;
    record[7] = value >> 24;
    record[5] = value >> 8;
    record[6] = value >> 16;
    func_001ad990(0.0f, D_0036cf00, scale, record + 8);
}