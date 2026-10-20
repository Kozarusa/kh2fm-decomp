#include "../common/types.h"
extern "C" s32 D_004f63a8[];

s32 func_0016f930(s32 value) {
    s32 index = 0;
    s32 result = 2410;
    s32* pointer = D_004f63a8;
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