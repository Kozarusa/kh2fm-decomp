#include "../common/types.h"
extern "C" u32 D_0035f620;
u32 func_002ad338() {
    register u32 result asm("$2") = 1; // why: original initializes return register before loop
    asm("" : "+r"(result)); // why: retain original early return value initialization
    u32 index = 0;
    u32 base = D_0035f620 + 0x13cu;
    u32 word = 0;
    do {
        u32 bit = index & 31u;
        ++index;
        u32 mask = 1u << bit;
        if ((*(u32*)(word * 4u + base) & mask) == 0) return 0;
        word = index >> 5;
    } while ((s32)index < 13);
    return result;
}


