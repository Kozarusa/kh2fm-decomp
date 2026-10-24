#include "../common/types.h"

s32* func_00124c48(u32 object, s32 value) {
    register u32 root asm("$14") = *(u32*)(object + 4); // why: original keeps the header base in t6
    s32* pointer = 0;
    if (*(s32*)(root + 12) != 0)
        pointer = (s32*)(root + *(u32*)(root + 8));
    if (pointer != 0) {
        while (*pointer != -1) {
            if (*pointer == value) goto found; // why: original shares one exit, the cursor is the result in v0
            u32 base = (u32)pointer + 16; // why: separate base keeps the +16 out of the next load offset
            pointer = (s32*)(base + ((u32)pointer[1] << 4));
        }
    }
    pointer = 0;
found:
    return pointer;
}
