#include "../common/types.h"
extern "C" u64 func_00209178(...);

void func_002092e0(s32 object, s32* other, s32 context) {
    s32 base = *(s32*)(context + 0xc);
    s32 offset = *(s32*)(base + 8);
    s32 target = object + offset + 0xa0;
    if (*other == *(s32*)(object + 0xc)) {
        func_00209178(other, target);
        // why: keeps the call a normal jal instead of a tail jump
        asm volatile("" ::: "memory");
    }
}