// func_00304f50: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" s32 D_00378ae4;
extern "C" s64 func_00305be8(u64, u64, u64);

s64 func_00304f50(s32* errorOut, u64 first, u64 second, u64 third) {
    D_00378ae4 = 0;
    register s64 result asm("$15") = func_00305be8(first, second, third); // why: original keeps the callee result in t7
    asm("" : "+r"(result)); // why: forces the result into t7 as the original does
    if (result == -1 && D_00378ae4 != 0) {
        *errorOut = D_00378ae4;
    }
    return result;
}
