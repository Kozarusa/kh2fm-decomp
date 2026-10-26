#include "../common/types.h"

extern "C" u32 D_0035f620;

u32 func_002ad338() {
    u32 result = 1;
    u32 index = 0;
    u32 base = D_0035f620 + 0x13cu;
    do {
        u32 word = index >> 5;
        u32 bit = index & 31u;
        u32 mask = 1u << bit;
        if ((*(u32*)(word * 4u + base) & mask) == 0) { result = 0; break; }
        ++index;
    } while ((s32)index < 13);
    return result;
}
