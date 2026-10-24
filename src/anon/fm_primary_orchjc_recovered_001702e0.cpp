#include "../common/types.h"
extern "C" u8* D_0034dca0;

// Preserve original registry aliases.
u8* func_001702e0(s32 value) asm("_Z16ctarget_001702e0jjjj");

u8* func_001702e0(s32 value) {
    u8* node = 0;
    u8* next;
    // why: statement expression with goto keeps the advance arm out of line,
    // which makes the compiler emit the original branch-likely (bnezl) head
    while (({
        if (node != 0) goto advance;
        next = D_0034dca0;
        goto done;
    advance:
        next = *(u8**)(node + 0x3c);
    done:
        node = next;
        next != 0;
    })) {
        if (*(s32*)(next + 0x30) == value) {
            return next;
        }
    }
    return 0;
}
