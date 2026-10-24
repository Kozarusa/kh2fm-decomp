#include "../common/types.h"
extern "C" u8* D_01e2aa80;

u8* func_002bbda0(s32 value) {
    u8* node = 0;
    u8* next;
    // why: statement expression with goto keeps the advance arm out of line,
    // which makes the compiler emit the original branch-likely (bnezl) head
    while (({
        if (node != 0) goto advance;
        next = D_01e2aa80;
        goto done;
    advance:
        next = *(u8**)(node + 0x1c);
    done:
        node = next;
        next != 0;
    })) {
        if (*(s32*)(next + 0x14) == value) {
            return next;
        }
    }
    return 0;
}
