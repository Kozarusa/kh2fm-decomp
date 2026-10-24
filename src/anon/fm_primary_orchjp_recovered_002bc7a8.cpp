#include "../common/types.h"
extern "C" u8* D_01e2aa80;

s32 func_002bc7a8(u32 type) {
    s32 count = 0;
    u8* node = 0;
    u8* next;
    // why: statement expression with goto keeps the loop exit inline before the body,
    // following the accepted 002bbe80 list-walk layout
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
        if (next[0x31] == type) {
            count = count + 1;
        }
    }
    return count;
}
