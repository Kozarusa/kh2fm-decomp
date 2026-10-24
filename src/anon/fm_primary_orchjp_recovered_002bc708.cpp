#include "../common/types.h"
extern "C" u8* D_01e2aa80;
extern "C" u64 func_002bbf68(...);

void func_002bc708(s32 value) {
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
        if (*(s32*)(next + 0x18) == value && *(u8*)(next + 0x31) == 6) {
            func_002bbf68(next, 1);
        }
    }
}
