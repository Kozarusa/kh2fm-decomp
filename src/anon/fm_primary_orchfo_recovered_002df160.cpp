#include "../common/types.h"

f32 func_002df160(volatile f32* object) {
    object[8] = 0;
    register f32 result asm("$f0") = object[6]; // why: original keeps the loaded value in $f0 and returns it
    f32 zero = object[8];
    object[9] = result;
    object[11] = zero;
    *(volatile u8*)&object[12] = 0;
    *((volatile u8*)&object[12] + 1) = 0;
    object[7] = result;
    object[10] = zero;
    return result;
}
