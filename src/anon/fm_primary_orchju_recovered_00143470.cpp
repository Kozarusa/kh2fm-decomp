// func_00143470: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" s32 func_001652c8(u32, u64, u64, u64, u64, u64, u64, u64);
extern "C" u32 D_00348804;

s32 func_00143470(u64 first, u64 second, u64 third, u64 fourth,
                  u64 fifth, u64 sixth, u64 seventh) {
    s64 result = func_001652c8(D_00348804, first, second, third, fourth, fifth, sixth, seventh);
    return result;
}
