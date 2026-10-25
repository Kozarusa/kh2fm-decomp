#include "../common/types.h"
extern "C" s8 D_00374590[];
extern "C" s32 D_0035f4bc;
extern "C" s32 D_0035f4c0;
extern "C" s32 D_0035f4c4;
extern "C" s32 D_0035f4c8;
extern "C" s32 D_0035f4cc;
extern "C" s32 D_0035f4d0;
extern "C" u32 D_0035f4d4;
extern "C" u32 D_0035f4dc;
extern "C" u32 D_0035f4e4;
extern "C" u32 func_00103570();
// why: copied from fm_primary_capacity_recovered_00303c48.cpp; the (u64, u64) form adds a 64-bit move of a0 (probe orch1_lg434_002926c0_v2)
extern "C" u32 func_001063f0(...);
extern "C" u32 func_002fde18(void*,u8,u32);

// why: the tail call leaves memset's v0 (its destination) as the only exit value, so the result is returned

u32 func_002926c0(s32 index) {
    D_0035f4c4 = index;
    D_0035f4bc = D_00374590[index * 2];
    D_0035f4c0 = D_00374590[index * 2 + 1] << 11;
    D_0035f4c8 = 0;
    D_0035f4cc = 0;
    D_0035f4d0 = 0;
    D_0035f4d4 = func_001063f0(D_0035f4bc << 4, func_00103570());
    func_002fde18((void*)D_0035f4d4, 0, D_0035f4bc << 4);
    D_0035f4dc = func_001063f0(D_0035f4bc << 2, func_00103570());
    func_002fde18((void*)D_0035f4dc, 0, D_0035f4bc << 2);
    D_0035f4e4 = func_001063f0(128, func_00103570());
    return func_002fde18((void*)D_0035f4e4, 0, 128);
}
