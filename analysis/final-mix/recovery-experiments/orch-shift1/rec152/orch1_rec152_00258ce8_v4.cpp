#include "../common/types.h"
extern "C" u16 D_0035f0a8[];
void func_00258ce8(u16* pointer) {
    if (pointer == 0) {
        D_0035f0a8[0] = 0x9fcf;
        // why: original index2 constant occupies t6
        register u16 value asm("$14") = 0x9fd1;
        D_0035f0a8[2] = value;
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

