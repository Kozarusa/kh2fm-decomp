#include "../common/types.h"
extern "C" s32 func_002859a0(void);
u32 func_002865d0(u32 value) {
    u32 result = func_002859a0() + 204;
    u32* pointer = (u32*)((value >> 5)*4 + result);
    register u32 word asm("$14") = *pointer; // why: original loaded word is t6
    u32 mask = 1u << (value & 31);
    u32 combined = word | mask;
    asm("" : "+r"(combined), "+r"(word)); // why: original computes OR before masked branch
    if (!(word & mask)) *pointer = combined;
    return result;
}



