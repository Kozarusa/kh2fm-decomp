#include "../common/types.h"
extern "C" u32 func_00209178(s32, void*);

void func_002092e0(u8* object, s32* other, u8* context) {
    u8* base = *(u8**)(context + 0xc);
    s32 offset = *(s32*)(base + 8);
    u8* target = object + offset + 0xa0;
    s32 expected = *(s32*)(object + 0xc);
    s32 actual = *other;
    if (actual == expected) {
        func_00209178((s32)other, target);
        // why: keeps the call a normal jal instead of a tail jump
        asm volatile("" ::: "memory");
    }
}
