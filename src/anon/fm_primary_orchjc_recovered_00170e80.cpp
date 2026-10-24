#include "../common/types.h"
extern "C" s32 D_0034dc9c;
extern "C" u8* D_0034dca0;
extern "C" u8 D_004fa440[];

s32 func_00170e80() {
    s32 low = D_0034dc9c;
    u8* node = 0;
    s32 high = (s32)D_004fa440;
    u8* next;
    // why: statement expression with goto keeps the node test before the
    // loop body, so the exit block follows it as in the original
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
        s32 kind = *(s32*)(next + 0x28);
        s32 skip = (kind < 10000) ^ 1;
        if (skip != 0) {
            continue;
        }
        if (kind >= 0) {
            high = *(s32*)(next + 0x30) + *(s32*)(next + 0x2c);
        } else {
            low = *(s32*)(next + 0x30);
        }
    }
    return low - high;
}
