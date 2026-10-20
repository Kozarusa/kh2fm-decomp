#include "../common/types.h"
extern "C" u8* D_004f3b38;
extern "C" void func_00160940(u8* object, s32 value, f32 scale);

void func_00161248(s32 value, f32 scale) {
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
        func_00160940(next, value, scale);
    }
}