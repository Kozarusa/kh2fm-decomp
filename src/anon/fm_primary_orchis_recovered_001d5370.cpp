// func_001d5370: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"

extern "C" u32 func_00168b38(...);

s32 func_001d5370(u32 *out, u64 owner, s32 index)
{
    s32 first = func_00168b38(owner, 0xffffffffffffffff);
    s64 second = func_00168b38(owner, 0xffffffffffffffff, index + 1);
    u32 first_value;
    first_value = *(u32 *)(8 + first);
    u32 second_value = *(u32 *)(8 +(u32) second);
    out [0] = first_value;
    out [1] = second_value;
    return second;
}
