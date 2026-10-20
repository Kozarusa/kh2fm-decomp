#include "../common/types.h"

void func_00189228(s32 base, s32 index) {
    u16* pointer = (u16*)(base + index * 2 + 5200);
    u16 value = pointer[4];
    if (value < 999) {
        pointer[4] = value + 1;
    }
}