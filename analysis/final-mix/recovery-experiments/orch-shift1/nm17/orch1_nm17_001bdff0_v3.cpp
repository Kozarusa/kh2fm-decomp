#include "../common/types.h"
extern "C" u8 D_0032bb30[];
extern "C" u16 func_001a67b0(s32);
extern "C" u32 func_001b8e88(u64);

void func_001bdff0(void) {
    u32 base = (u32)D_0032bb30;
    // why: keeps the base address materialized before the offset add
    asm("" : "+r"(base) : : "memory");
    u16* cursor = (u16*)(base + 14064);
    // why: pins the cursor computation right after the base
    asm("" : "+r"(cursor) : : "memory");
    s32 count = 3;
    do {
        u8* entry = (u8*)func_001b8e88(cursor[4]);
        if (*(u16*)(entry + 2) == 2) {
            cursor[4] = func_001a67b0(*(s16*)(entry + 4));
        }
        count--;
        cursor++;
    } while (count >= 0);
}
