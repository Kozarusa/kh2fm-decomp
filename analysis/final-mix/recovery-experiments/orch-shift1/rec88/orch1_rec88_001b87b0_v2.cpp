#include "../common/types.h"
extern "C" u8 D_0032fb68[];
extern "C" void func_001b8838(s32);
extern "C" void func_001b8da0();

void func_001b87b0() {
    u8* base = D_0032fb68;
    // why: keeps base in its own register so the offset store reuses it
    asm("" : "+r"(base));
    s32 index = 7;
    u32* pointer = (u32*)base;
    do {
        *pointer = 0;
        index--;
        pointer++;
    } while (index >= 0);
    base[287] = 0;
    func_001b8838(0);
    func_001b8da0();
}
