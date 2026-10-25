#include "../common/types.h"
extern "C" u8* D_0035ec88;
extern "C" u8 D_003716b8[];
extern "C" u8* D_0035ebf8;
extern "C" u8* D_0035ec00;
extern "C" u8* D_0035ebfc;
// why: no recovered source uses this result; derived from registers (no args, v0 tested by beqzl and passed as a2)
extern "C" u32 func_00240108();
// why: no recovered source calls this; derived from registers (a0 word global, a1 the kind, a2 the func_00240108 result)
extern "C" u32 func_00240118(u8*, s32, u32);
extern "C" u32 func_002ff2e8(...);

// why: void per DEVIATIONS #36: the kind == -5 exit leaves the untouched entry v0, the other exits are direct tail results, no float result

void func_00240360(s32 kind) {
    if (kind == -5) {
        return;
    }
    if (kind == -4) {
        func_002ff2e8(D_0035ec88, D_003716b8);
    } else if (kind == -3) {
        func_002ff2e8(D_0035ec88, D_0035ebf8);
    } else if (kind == -2) {
        func_002ff2e8(D_0035ec88, func_00240108() ? D_0035ec00 : D_0035ebfc);
    } else {
        func_00240118(D_0035ec88, kind, func_00240108());
    }
}
