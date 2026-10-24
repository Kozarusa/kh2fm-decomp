#include "../common/types.h"
extern "C" u8* D_01c60cd8;

s32 func_0018f070(u8* target) {
    if (target == 0) {
        return 0;
    }
    u8* node = 0;
    u8* next;
    // why: statement expression with goto keeps the advance arm out of line,
    // which makes the compiler emit the original branch-likely (bnezl) head
    while (({
        if (node != 0) goto advance;
        next = D_01c60cd8;
        goto done;
    advance:
        next = *(u8**)(node + 0xc0);
    done:
        node = next;
        next != 0;
    })) {
        if (next == target) {
            return 1;
        }
    }
    return 0;
}
