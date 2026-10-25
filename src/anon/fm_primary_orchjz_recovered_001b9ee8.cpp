#include "../common/types.h"
extern "C" u8* D_01d48da0;

void func_001b9ee8(s32 value) {
    u8* node = 0;
    u8* next;
    // why: statement expression with goto keeps the advance arm out of line,
    // which makes the compiler emit the original branch-likely (bnezl) head
    while (({
        if (node != 0) goto advance;
        next = D_01d48da0;
        goto done;
    advance:
        next = *(u8**)(node + 0x8b4);
    done:
        node = next;
        next != 0;
    })) {
        if ((*(u32*)(next + 0x588) & 0x20) == 0) {
            if ((*(s32 (**)(u8*))(*(u8**)next + 0x3c))(next) < value) {
                *(u32*)(next + 0x10c) |= 0x80;
            }
        }
    }
}
