#include "../common/types.h"
extern "C" u8 D_0032bb30[];
extern "C" s32* func_001d5b78(s32, s32);

s32 func_001d5d20() {
    s32* entry = func_001d5b78(0, 1);
    u8* base = D_0032bb30;
    // why: keeps one materialized base register for both global reads
    asm("" : "+r"(base));
    s32 one = 1;
    // why: keeps the constant 1 in a register for the slt compare
    asm("" : "+r"(one));
    s32 count = base[13606];
    s32 total = *(s32*)(base + 14052);
    if (one < count) {
        s32 remaining = count - 1;
        do {
            remaining = remaining - 1;
            total = total + entry[1];
            entry = entry + 2;
        } while (remaining != 0);
    }
    return total;
}
