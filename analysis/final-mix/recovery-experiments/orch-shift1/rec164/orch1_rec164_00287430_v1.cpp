#include "../common/types.h"
extern "C" u32 func_002859a0(void);
u32 func_00287430(s32 value, s32 index) {
    u32 result = func_002859a0();
    if (value == 7) value = value - 1;
    result += 164;
    u32 bit = (value - 1)*48 + index;
    u32* pointer = (u32*)((bit >> 5)*4 + result);
    u32 mask = 1u << (bit & 31);
    u32 word = *pointer;
    u32 combined = word | mask;
    if (!(word & mask)) *pointer = combined;
    return result;
}
