#include "../common/types.h"
extern "C" u32 func_00187018(u32, u32, u32, u32, f32);

u32 func_0018fd40(u32* object) {
    u32 third = object[2];
    u32 second = object[1];
    register u32 first asm("$15") = object[0]; // why: original loads the first word into t7 while a0 is still the object
    return func_00187018(first, second, third, object[3], *(f32*)(object + 4));
}
