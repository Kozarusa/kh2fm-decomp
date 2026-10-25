#include "../common/types.h"
extern "C" u32 D_0035db18;
extern "C" u32 D_0035db50[];
extern "C" u8 D_01dad918[];
extern "C" u32 func_002ff2e8(...);
extern "C" s32 func_002ff3fc(...);
// why: no recovered source calls or defines this callee; u32 because on every in-range path it returns the v0 of func_00224c20, whose accepted definition (fm_primary_queuegamma_recovered_00224c20.cpp) returns u32
extern "C" u32 func_00224cf0();

// why: u32 return because both exits leave a live callee result in v0 (strlen length on the zero-size path, func_00224cf0 on the tail path)

u32 func_00227130(u8* object) {
    u32 result;
    s32 size;
    s32 limit;
    // why: the original places the first-time setup block after the epilogue and jumps back from it
    if (D_0035db50[0] == 0) {
        goto setup;
    }
clear:
    for (s32 i = 0; i < 32; i++) {
        D_01dad918[i] = 0;
    }
    func_002ff2e8(D_01dad918, object + 10);
    result = func_002ff3fc(D_01dad918);
    size = *(s32*)(object + 4);
    D_0035db18 = size;
    if (size == 0) {
        return result;
    }
    limit = size + 0x40000;
    if (limit > 0x400000) {
        limit = 0x400000;
    }
    D_0035db18 = limit;
    return func_00224cf0();
setup:
    D_0035db50[0] = (u32)object;
    D_0035db50[2] = 0;
    D_0035db50[1] = 0;
    goto clear;
}
