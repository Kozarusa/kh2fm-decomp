#include "../common/types.h"
extern "C" u64 func_00209178(...);

void func_002092e0(s32 object, s32* other, s32 context) {
    s32 base = *(s32*)(context + 0xc);
    s32 offset = *(s32*)(base + 8);
    s32 target = object + offset + 0xa0;
    // why: forces the object field load after the offset load
    s32 expected = *(volatile s32*)(object + 0xc);
    s32 actual = *other;
    if (actual == expected) {
        func_00209178(other, target);
        // why: keeps the call a normal jal instead of a tail jump
        asm volatile("" ::: "memory");
    }
}