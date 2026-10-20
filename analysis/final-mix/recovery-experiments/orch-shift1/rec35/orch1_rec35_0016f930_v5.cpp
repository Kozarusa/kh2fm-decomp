#include "../common/types.h"
extern "C" s32 D_004f63a8[];

s32 func_0016f930(s32 value) {
    // why: pin loop registers to the original t4/t5/t6 allocation
    register s32* pointer asm("$12") = D_004f63a8;
    register s32 index asm("$13") = 0;
    register s32 result asm("$14") = 2410;
    do {
        s32 entry = *pointer;
        s32 current = result;
        result += 10;
        pointer++;
        if (entry == value) {
            return current;
        }
        index++;
    } while (index < 2);
    return 2400;
}