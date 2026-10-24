#include "../common/types.h"
extern "C" u8* volatile D_01e2aa80;

void func_002bbe80() {
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
        if (*(u8*)(next + 0x31) == 2) {
            *(u32*)(next + 0x24) &= ~4u;
        }
    }
}
