#include "../common/types.h"
// why: head of a linked list of entries; each entry links to the next through the word at +0x8b4
extern "C" s32 D_01d48da0;

u8 func_001ba028(s32 target) {
    s32 current = 0;
    // why: held 64-bit and tested through its low word (the loaded word is already sign-extended, so no
    // instruction changes); with an s32 link the loop-head null test becomes branch-likely (bnezl), not bnez
    s64 next;
    // why: u32 result narrowed once at the shared exit gives the original's single andi v0,v0,0xff join
    u32 result;
    // why: the link is chosen inside the loop condition (GNU statement expression) because only that form
    // keeps the original loop rotation (bnezl on current, the null test of the link at the loop head)
    while ((s32)(next = ({
                s32 link;
                if (current == 0) {
                    link = D_01d48da0;
                } else {
                    link = *(s32*)(current + 0x8b4);
                }
                link;
            })) != 0) {
        current = next;
        result = 1;
        if ((u32) next == (u32) target) {
            goto done; // why: both exits share one return block (the andi join); early returns lose it
        }
    }
    result = 0;
done:
    return result;
}
