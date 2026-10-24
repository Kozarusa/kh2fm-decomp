// func_001033d8: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" s16 D_00369da8[];

// Preserve original registry aliases.
s32 func_001033d8(s32 value) asm("_Z13func_001033d8Pv");

s32 func_001033d8(s32 value) {
    s32 result = -1;
    s32 index = 0;
    if (D_00369da8[0] >= 0) {
        do {
            if (D_00369da8[index*2] == value) result = D_00369da8[index*2+1];
            index++;
        } while (D_00369da8[index*2] >= 0);
    }
    return result;
}
