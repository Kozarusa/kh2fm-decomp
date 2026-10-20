#include "../common/types.h"
extern "C" u8 D_01c94090[];

s32 func_001afe30(s32 value) {
    s32 index = 0;
    s32* pointer = (s32*)(D_01c94090 + 4);
    do {
        s32 current = *pointer;
        s32 result = index;
        index = index + 1;
        pointer = pointer + 3;
        if (current == value) return result;
    } while (index < 3);
    return -1;
}
