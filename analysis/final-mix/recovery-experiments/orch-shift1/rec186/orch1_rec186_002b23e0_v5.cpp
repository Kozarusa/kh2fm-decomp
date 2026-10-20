#include "../common/types.h"
extern "C" s64 func_00276608(s32);
extern "C" s32 func_002b2338(s64);
extern "C" u32 D_0035f630;
u32 func_002b23e0(s64 value) {
    if (value < 0) value = func_00276608(28);
    register s32 result asm("$13") = func_002b2338(value); // why: original transports callee result through t5
    asm("" : "+r"(result)); // why: retain original t5 transport before multiply
    register u32 factor asm("$14") = 36u; // why: original multiplier constant uses t6
    return D_0035f630 + (u32)result * factor;
}




