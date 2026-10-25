#include "../common/types.h"
// why: no recovered source calls or defines this callee; its instructions take one word in a0 and return (a0 + 1023) >> 10 in v0
extern "C" s32 func_00240440(u32);

s32 func_002408d0(u32 mode) {
    s32 extra = 0;
    s32 total = 0;
    if (mode < 2) {
        total = func_00240440(0x3c4);
        total += func_00240440(0x8a58);
        total += func_00240440(0x10fc0);
        total = ((total + 8) / 5) * 5;
    }
    if (mode == 0 || mode == 2) {
        extra = func_00240440(0x3c4);
        extra += func_00240440(0x8a58);
        extra += func_00240440(0x400);
        extra = ((extra + 8) / 5) * 5;
    }
    total += extra;
    return total;
}
