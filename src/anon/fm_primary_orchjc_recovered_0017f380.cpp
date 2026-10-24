#include "../common/types.h"

void func_0017f380(u8* object) {
    u8* node;
    u8* next;
    *(s32*)(object + 60) = 0;
    node = 0;
    *(s32*)(object + 64) = 0;
    // why: statement expression with goto keeps the advance arm out of line,
    // which makes the compiler emit the original branch-likely (bnezl) head
    while (({
        if (node != 0) goto advance;
        next = *(u8**)(object + 148);
        goto done;
    advance:
        next = *(u8**)(node + 156);
    done:
        node = next;
        next != 0;
    })) {
        func_0017f380(next);
    }
}
