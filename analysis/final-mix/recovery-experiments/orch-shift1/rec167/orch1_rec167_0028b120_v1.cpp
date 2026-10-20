#include "../common/types.h"
void func_0028b120(s16* object,s32* remainder,s32* quotient,s32 value) {
    if (value < 0) value = object[0] + object[9];
    s16 count = object[12];
    if (!count) __builtin_trap();
    *remainder = value % count;
    *quotient = value / object[12];
}
