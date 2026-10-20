#include "../common/types.h"
extern "C" u16 D_0035f0a8[];
void func_00258ce8(u16* pointer) {
    if (pointer == 0) {
        D_0035f0a8[0] = 0x9fcf;
        D_0035f0a8[2] = 0x9fd1;
        asm volatile("" ::: "memory"); // why: keeps store order
        D_0035f0a8[1] = 0x9fd0;
        return;
    }
    s32 count = 2;
    u16* output = D_0035f0a8;
    do {
        u16 value = *pointer;
        --count;
        *output = value;
        ++pointer;
        ++output;
    } while (count >= 0);
}

