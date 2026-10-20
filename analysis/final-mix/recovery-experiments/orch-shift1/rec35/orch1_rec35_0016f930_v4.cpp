#include "../common/types.h"
extern "C" s32 D_004f63a8[];

s32 func_0016f930(s32 value) {
    s32 result = 2410;
    s32* pointer = D_004f63a8;
    for (s32 index = 0; index < 2; index++) {
        s32 current = result;
        result += 10;
        if (*pointer++ == value) {
            return current;
        }
    }
    return 2400;
}