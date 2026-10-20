#include "../common/types.h"

void func_00189228(s32 base, s32 index) {
    u16* pointer = (u16*)(index * 2 + base + 5200);
    u32 value = pointer[4];
    // why: keeps the explicit 16-bit mask the original emits after the load
    asm("" : "+r"(value));
    if ((u16)value < 999) {
        pointer[4] = value + 1;
    }
}