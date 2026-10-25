// func_002ab180: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" s32 func_002a9d68(void);
extern "C" u8* D_0035f610;

s32 func_002ab180(s32 index) {
    u8 * sram;
    sram = (u8 *) func_002a9d68();
    s32 result = 1;
    if (index < 0)
    {
        u32 * known = (u32 *)(D_0035f610 + 136);
        u32 * owned = (u32 *)(sram + 136);
        u32 bit = 0;
        do
        {
            u32 mask = bit & 31;
            mask = 1u << mask;
            if (0 !=(known [(bit >> 5)] & mask))
            {
                result = 0 !=(owned [(bit >> 5)] & mask);
                if (result == 0)
                {
                    return result;
                }
            }
            bit++;
        }
        while ((s32) bit < 96);
    }
    else
    {
        u32 offset = ((u32) index >> 5) * 4;
        u32 mask = 1u <<(index & 31);
        s32 flag = 0;
        if (0 !=(*(u32 *)(D_0035f610 + offset + 136) & mask))
        {
            flag = (*(u32 *)(sram + offset + 136) & mask) != 0;
        }
        result = flag;
    }
    return result;
}
