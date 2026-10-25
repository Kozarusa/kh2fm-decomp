// func_002ad660: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" u32 D_0035f620;
extern "C" u32 func_00294000(u64);

// why: every exit returns a constant the function sets itself (move v0,s0 with s0 = 1 or 0), an own value

s32 func_002ad660(void) {
    s32 result = 1;
    s32 count = *(s32 *)(((u8 *) func_00294000(6)) + 8);
    u32 index = 0;
    if (count > 0)
    {
        u32 * flags = (u32 *)(D_0035f620 + 132);
        do
        {
            if ((flags [(index >> 5)] &(1 <<(index & 0x1f))) == 0)
            {
                result = 0;
                break;
            }
            index++;
        }
        while ((s32) index < count);
    }
    return result;
}
