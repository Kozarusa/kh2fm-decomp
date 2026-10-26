#include "../common/types.h"
extern "C" u32 func_00187018(u32, u32, u32, u32, f32);

u32 func_0018fd40(u32* object) {
    u32 third = object[2];
    u32 second = object[1];
    u32 first = object[0];
    return func_00187018(first, second, third, object[3], *(f32*)(object + 4));
}
