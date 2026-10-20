#include "../common/types.h"
extern "C" u8* D_0035f0e4;
s32 func_002671e8(s32 value) {
    s32 result = -1;
    s32 count = 0;
    s32 index = 0;
    u32 one = 1;
    s32 base = *(s8*)(D_0035f0e4 + 32) * 10;
    u32 bits = *(u32*)(D_0035f0e4 + 24);
    do {
        s32 bit = base + index;
        index++;
        asm("" : "+r"(bit) : "r"(index)); // why: schedules native shift after index increment
        if (bits & (one << bit)) {
            if (count == value) { result = bit; break; }
            count++;
        }
    } while (index < 10);
    return result;
}


