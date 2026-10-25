// func_002aad58: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" u8* D_0035f610;
extern "C" s32 func_002a9d68(void);

bool func_002aad58(s32 id) {
    u8 * sram = (u8 *) func_002a9d68();
    bool result = 1;
    if (id < 0)
    {
        u32 * own = (u32 *)(sram + 148);
        u32 * bits = (u32 *)(D_0035f610 + 148);
        u32 index = 0;
        do
        {
            u32 mask = index & 0x1f;
            mask = 1 << mask;
            if ((bits [(index >> 5)] & mask) != 0)
            {
                result = 0 !=(own [(index >> 5)] & mask);
                if (!result)
                {
                    return result;
                }
            }
            index += 1;
        }
        while ((s32) index < 192);
    }
    else
    {
        u32 offset = ((u32) id >> 5) * 4;
        u32 mask = 1 <<(id & 0x1f);
        bool flag = 0;
        if ((0 !=(*(u32 *)(D_0035f610 + offset + 148) & mask)))
        {
            flag = (*(u32 *)(sram + offset + 148) & mask);
        }
        result = flag;
    }
    return result;
}
