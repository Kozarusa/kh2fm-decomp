#include "../common/types.h"

u32 func_001ae210(s8* pointer) {
    u32 result = 0xffffffffu;
    s32 value = *pointer++;
    while (value != 0) {
        result ^= (u32)value << 24;
        s32 count = 7;
        do {
            if (result & 0x80000000u) result = (result << 1) ^ 0x04c11db7u;
            else result <<= 1;
            --count;
        } while (count >= 0);
        value = *pointer++;
    }
    return ~result;
}
