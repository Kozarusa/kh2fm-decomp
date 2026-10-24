#include "../common/types.h"

void func_00314640(u32* source, u32* dest) {
    u32 bits = *source;
    u32 fraction = bits & 0x7fffff;
    u32 exponent = (bits >> 23) & 0xff;
    u32 sign = bits >> 31;
    dest[1] = sign;
    if (exponent == 0) {
        dest[0] = 2;
        return;
    }
    dest[2] = exponent - 127;
    dest[0] = 3;
    dest[3] = (fraction << 7) | 0x40000000;
}
