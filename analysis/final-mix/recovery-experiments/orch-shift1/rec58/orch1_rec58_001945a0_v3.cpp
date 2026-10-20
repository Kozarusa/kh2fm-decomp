#include "../common/types.h"
extern "C" f32 D_0036cf00;
extern "C" u32 func_001ad990(f32, f32, f32, void*);
extern "C" u8* func_001bfd60(s32);

void func_001945a0(f32 scale, s32 base, s32 unused, u32 value) {
    u8* record = func_001bfd60(base + 0x8e0);
    f32 limit = D_0036cf00;
    u8* cursor = record + 4;
    cursor[0] = value;
    cursor[3] = value >> 24;
    cursor[1] = value >> 8;
    cursor[2] = value >> 16;
    func_001ad990(0.0f, limit, scale, record + 8);
}