#include "../common/types.h"
extern "C" s32 func_002a9d68(void);
u32 func_002aa450(u32 value) {
    u32 address = (u32)func_002a9d68() + 316;
    u32* pointer = (u32*)((value >> 5) * 4 + address);
    register u32 word asm("$14") = *pointer; // why: original loads word into t6
    u32 mask = 1u << (value & 31);
    u32 result = word | mask;
    asm("" : "+r"(result)); // why: original computes OR before branch test
    u32 flag = word & mask;
    if (flag == 0) {
        *pointer = result;
    }
    return address;
}



