// func_0018cf18: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" u8 D_01c60bf0[];
extern "C" void func_0031e2b8(void*);

// Preserve original registry aliases.
void func_0018cf18(s32 initialize, s32 priority) asm("_Z16wtarget_0018cf18jjjj");

void func_0018cf18(s32 initialize, s32 priority) {
    if (priority == 0xffff && initialize == 1)
    {
        u8 * pointer = D_01c60bf0;
        s32 count;
        for (count = 3; count != - 1; count--)
        {
            func_0031e2b8(pointer + 24);
            pointer += 48;
        }
        u8 * base = D_01c60bf0;
        s32 index;
        for (index = 0; index < 4; index++)
        {
            ((s32 *)(base + 192)) [index] = index;
        }
        *(s32 *)(base + 208) = 4;
    }
    if (priority == 0xffff && initialize == 0)
    {
        u8 * pointer = D_01c60bf0;
        if (pointer != 0)
        {
            u8 * base = pointer;
            pointer += 192;
            for (;;)
            {
                if (pointer == base)
                {
                    break;
                }
                pointer -= 48;
            }
        }
    }
}
