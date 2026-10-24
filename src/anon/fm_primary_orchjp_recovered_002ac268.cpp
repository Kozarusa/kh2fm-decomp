#include "../common/types.h"
extern "C" s32 func_002a9d68(void);
extern "C" s32 func_002abf40(...);

u32 func_002ac268(s32 value, s32 mode) {
    u32 base = (u32)func_002a9d68();
    u32 index = (u32)func_002abf40(value, mode);
    base += value * 4;
    base += 172;
    u32* pointer = (u32*)((index >> 5) * 4 + base);
    index &= 31;
    u32 word = *pointer;
    u32 mask = 1u << index;
    register u32 result asm("$13") = word | mask; // why: original combined word occupies t5
    asm("" : "+r"(result)); // why: keeps combined value computed before conditional store
    if ((word & mask) == 0) {
        *pointer = result;
    }
    return index;
}
