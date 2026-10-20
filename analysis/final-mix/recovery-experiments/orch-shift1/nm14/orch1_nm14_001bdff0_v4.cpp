#include "../common/types.h"
struct Table { u8 prefix[14064]; u16 values[8]; };
extern "C" Table D_0032bb30;
extern "C" u16 func_001a67b0(s32);
extern "C" u8* func_001b8e88(u64);

void func_001bdff0(void) {
    Table* base = &D_0032bb30;
    // why: keeps the base address materialized before the offset add
    asm("" : "+r"(base));
    u16* cursor = base->values;
    // why: pins the cursor computation right after the base
    asm("" : "+r"(cursor));
    s32 count = 3;
    do {
        u8* entry = func_001b8e88(cursor[4]);
        if (*(u16*)(entry + 2) == 2) {
            cursor[4] = func_001a67b0(*(s16*)(entry + 4));
        }
        count--;
        cursor++;
    } while (count >= 0);
}
