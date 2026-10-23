#include "../common/types.h"

s32 func_002c5238(s32 value, s32 count, s32* out) {
    s32 digits = 0;
    count = count - 1;
    s32* cursor = (s32*)(count * 4 + (s32)out);
    do {
        if (value == 0) {
            *cursor = 0;
        } else {
            digits++;
            *cursor = value % 10;
            value = value / 10;
        }
        count--;
        cursor--;
    } while (count >= 0);
    if (digits != 0) {
        return digits;
    }
    return 1;
}
