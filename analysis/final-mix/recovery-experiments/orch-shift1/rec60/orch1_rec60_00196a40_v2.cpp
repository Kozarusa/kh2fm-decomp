#include "../common/types.h"
extern "C" u32 D_00350338[];
extern "C" u8 D_00196888[];
extern "C" u8 D_00196a08[];
extern "C" u32 func_00102c18(u32, u32, u32);

void func_00196a40(void) {
    s32 count = 7;
    u32* entry = D_00350338 + 1;
    do {
        *entry = 0;
        count--;
        entry += 2;
    } while (count >= 0);
    u8* task = (u8*)func_00102c18(1, 14002, (u32)D_00196888);
    *(u32*)(task + 0x30) = (u32)D_00196a08;
}

