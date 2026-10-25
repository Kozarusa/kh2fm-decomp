// func_002aaf40: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" u32 D_0035f610;
extern "C" s32 func_002a9d68(void);
extern "C" u32 func_00294000(u64);
// why: no recovered caller; one word argument in a0 (-1), result copied from v0 into the returned value
extern "C" u32 func_002aad58(s32);

u32 func_002aaf40(s32 key) {
    u32 result = 1;
    u32 sram = func_002a9d68();
    u8 * info;
    info = (u8 *) func_00294000(8);
    u16 * entry = (u16 *)(info + 16);
    if (key < 0)
    {
        result = func_002aad58(- 1);
    }
    else
    {
        s32 count = *(s32 *)(info + 8);
        u32 index;
        for (index = 0;(s32) index < count; index++)
        {
            u32 saved = sram + 0x94u;
            u32 current = D_0035f610 + 0x94u;
            u16 value = * entry;
            entry += 8;
            if (value == key)
            {
                u32 mask = 1u <<(index & 31u);
                if ((*(u32 *)(((index >> 5) * 4u) + current) & mask) != 0)
                {
                    result = (*(u32 *)(((index >> 5) * 4u) + saved) & mask) != 0;
                    if (result == 0)
                        return result;
                }
            }
        }
    }
    return result;
}
