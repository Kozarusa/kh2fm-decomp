#include "../common/types.h"
extern "C" s32 D_004f63a8[];

s32 func_0016f930(s32 value) {
    s32 index;
    for (index = 0; index < 2; index++) {
        if (D_004f63a8[index] == value) return 2410 + index * 10;
    }
    return 2400;
}
