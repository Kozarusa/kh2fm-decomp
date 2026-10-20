#include "../common/types.h"
extern "C" u8 D_01c60d50[];
extern "C" s32 D_01c61950;
extern "C" u8 D_01c60d10[];
extern "C" void func_001cd660(u8*);

void func_001900d0() {
    u8* base = D_01c60d50;
    // why: keeps the table base materialized in a register so the +2560 offset is a separate addiu
    asm("" : "+r"(base));
    s32* slot = (s32*)(base + 2560);
    s32 index = 0;
    do {
        *slot = index;
        index++;
        slot++;
    } while (index < 128);
    D_01c61950 = 128;
    func_001cd660(D_01c60d10);
}