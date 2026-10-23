// func_00160d70: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
// func_00160d70: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// near-miss attempt. Names and types are provisional.
#include "../common/types.h"
extern "C" u8* D_004f3b38;
extern "C" void func_00160d18(u8*);

void func_00160d70(s32 value) {
    u8* node = 0;
    u8* next;
    // why: statement expression with goto keeps the advance arm out of line,
    // which makes the compiler emit the original branch-likely (bnezl) head
    while (({
        if (node != 0) goto advance;
        next = D_004f3b38;
        goto done;
    advance:
        next = *(u8**)(node + 0x80);
    done:
        node = next;
        next != 0;
    })) {
        if (*(s32*)(next + 0x1a8) == value) {
            func_00160d18(next);
        }
    }
}
