// func_00103428: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" s16 D_00369d98[];

s32 func_00103428(s32 value) {
    // why: carried over from the earlier attempt; the permuter kept it to stay exact
    register s32 result asm("$2") = 0;
    s32 index = 0;
    if (D_00369d98 [0] >= 0)
    {
        do
        {
            if (value == D_00369d98 [index])
            {
                result = 1;
                break;
            }
            index++;
        }
        while (D_00369d98 [index] >= 0);
    }
    return result;
}
