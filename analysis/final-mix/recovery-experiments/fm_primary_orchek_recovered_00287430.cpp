#include "../common/types.h"
extern "C" s32 func_002859a0(void);

u32 func_00287430(s32 value, s32 index) {
    register u32 result asm("$2") = func_002859a0(); // why: original SRAM base stays in v0
    if (value == 7) value = value - 1;
    result += 164;
    value--;
    u32 bit = value*48 + index;
    u32* pointer = (u32*)((bit >> 5)*4 + result);
    u32 mask = 1u << (bit & 31);
    u32 word = *pointer;
    u32 combined = word | mask;
    asm("" : "+r"(combined), "+r"(word)); // why: keeps original OR before masked branch
    if (!(word & mask)) *pointer = combined;
    return result;
}
