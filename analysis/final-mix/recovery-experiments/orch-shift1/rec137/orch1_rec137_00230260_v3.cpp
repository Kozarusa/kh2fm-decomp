#include "../common/types.h"
extern "C" f32 func_0017ce10(f32);
extern "C" f32 func_002f8ad0(f32, f32);
extern "C" f32 D_00371264;
f32 func_00230260(f32* first, f32* second, f32* output) {
    // why: original transports atan result through f12
    register f32 result asm("$f12") = func_002f8ad0(second[0] - first[0], second[2] - first[2]);
    // why: original transports atan result through f12
    asm("" : "+f"(result)); // why: preserves original f12 transport
    result = func_0017ce10(D_00371264 - result);
    *(s32*)(output + 2) = 0;
    output[1] = result;
    *(s32*)output = 0;
    return result;
}
