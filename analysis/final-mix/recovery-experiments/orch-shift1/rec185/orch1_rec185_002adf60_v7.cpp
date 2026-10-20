#include "../common/types.h"
extern "C" u8* D_0035f620;
s32 func_002adf60(s32 value) {
    register s32 result asm("$2") = 1; // why: original keeps success result in v0
    asm("" : "+r"(result)); // why: keeps the success result live before the loop
    u32 index = 0;
    register u32* pointer asm("$11") = (u32*)(D_0035f620 + 320); // why: original keeps bit-array base in t3
    do {
        if (value < 0 || (u32)value == index) {
            u32 mask = 1u << (index & 31);
            if ((pointer[index >> 5] & mask) == 0) return 0;
        }
        ++index;
    } while ((s32)index < 4);
    asm("" : "+r"(result)); // why: keeps the successful return separate from the zero return
    return result;
}





