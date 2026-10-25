// func_001b6fb0: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" s32* D_01d48cb4;
extern "C" s32 func_001b7818(s32);

s32* func_001b6fb0(s32 key, s32 limit) {
    s32 index = func_001b7818(key);
    if (index == 0)
    {
        index = 1;
    }
    if (!(index < D_01d48cb4 [1] && D_01d48cb4 [index + 2]))
    {
        index = 1;
    }
    s32 * base = D_01d48cb4 +(D_01d48cb4 + index) [2];
    s32 count;
    count = * base;
    if (count < limit)
    {
        limit = count;
    }
    return base + limit * 4 - 3;
}
