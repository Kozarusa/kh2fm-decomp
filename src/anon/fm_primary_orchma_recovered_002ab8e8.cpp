// func_002ab8e8: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" u8* D_0035f610;
// why: no recovered declaration; a0 takes the previous entry (starts at 0) and v0 returns the next entry pointer or 0
extern "C" u8* func_001a82b0(u8*);
extern "C" u8* func_001a80c8(s32 id);
extern "C" s32 func_002764b0(u32);

s32 func_002ab8e8(s32 id) {
    u8 * entry = 0;
    u32 index = 0;
    s32 found = 0;
    for (;;)
    {
        entry = func_001a82b0(entry);
        if (entry == 0)
            break;
        if ((func_001a80c8(*(u16 *)(entry + 2))) [2] != 22)
            continue;
        if (id >= 0 && func_002764b0(entry [5]) != id)
        {
            index++;
            continue;
        }
        u32 offset = (index >> 5) * 4;
        if (*(u32 *)(D_0035f610 + offset + 300) &(1 <<(index & 0x1f)))
        {
            found = 1;
            break;
        }
        index++;
    }
    return found;
}
