#include "../common/types.h"
extern "C" s32 func_002a9d68(void);
u32 func_002aab90(u32 value) {
    u32 address = (u32)func_002a9d68() + 132;
    u32* pointer = (u32*)((value >> 5) * 4 + address);
    u32 word = *pointer;
    u32 mask = 1u << (value & 31);
    register u32 result asm("$13") = word | mask; // why: original OR result uses t5
    asm("" : "+r"(result)); // why: keep OR result before condition
    if ((word & mask) == 0) {
        *pointer = result;
    }
    return address;
}



