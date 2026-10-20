#include "../common/types.h"
extern "C" u8* D_004f3b38;
extern "C" void func_00160488(u8* object, u32 red, u32 green, u32 blue);

void func_001611a8(u8 red, u8 green, u8 blue) {
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
        func_00160488(next, red, green, blue);
    }
}