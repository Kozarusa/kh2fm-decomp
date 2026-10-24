#include "../common/types.h"
extern "C" u8* D_0034dca0;
extern "C" void func_00170018(u8*);

// Preserve original registry aliases.
void func_00170320(s32 value) asm("_ZN2YS10CACHE_BUFF5ClearEi");

void func_00170320(s32 value) {
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
        if (value >= 0) {
            if (*(s32*)(next + 0x28) < value) {
                continue;
            }
        } else {
            if (value < *(s32*)(next + 0x28)) {
                continue;
            }
        }
        func_00170018(next);
    }
}
