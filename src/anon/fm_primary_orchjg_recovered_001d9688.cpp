#include "../common/types.h"

// Preserve original registry aliases.
u8 func_001d9688(s32 base, s32 index, s32 offset) asm("_Z16wtarget_001d9688jjjj");

u8 func_001d9688(s32 base, s32 index, s32 offset) {
    u8* pointer = (u8*)(index * 3 + base + offset);
    u32 value = *pointer;
    asm("" : "+r"(value)); // why: original re-masks the loaded byte before the compare
    if ((value & 0xff) < 99) {
        register u32 next asm("$13") = value + 1; // why: original keeps the incremented byte in t5
        value = next;
        *pointer = next;
    }
    return value;
}
