#include "../common/types.h"
s32 func_0028dd90(s32 value) {
    s32 result = 0;
    s32 remainder = value % 10;
    if (remainder == 1) return 2;
    if (remainder > 1 && remainder == 2) result = 1;
    return result;
}
