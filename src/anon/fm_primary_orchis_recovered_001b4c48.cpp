// func_001b4c48: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" u32 func_00168b88(...);

u32 func_001b4c48(s32 object, u32* output, s8* key) {
    register u32 high;
    register s32 first;
    s32 low;
    __typeof__(*((u32 *)(4 + object))) value_t1 = *((u32 *)(4 + object));
    first = func_00168b88(value_t1, 0x18, key [0] |(key [3] << 0x18) | s32((u64) key [2] << 0x10 | key [1] << 8), 0);
    u64 second;
    second = func_00168b88(*(u32 *)(object + 4), 0x19, key [0] |(u32(key [3]) << 0x18) |(key [2] << 0x10 | key [1] << 8), 0);
    low = (*(u32 *)(8 + first));
    high = (*((u32 *)((u32) second + 8)));
    output [0] = low;
    output [1] = high;
    return second;
}
