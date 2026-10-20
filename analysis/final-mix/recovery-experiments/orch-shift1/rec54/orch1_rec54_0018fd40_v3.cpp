#include "../common/types.h"
extern "C" u32 func_00187018(f32, u32, u32, u32, u32);

void func_0018fd40(u32* object) {
    // why: volatile reads keep the original load order
    volatile u32* source = object;
    u32 third = source[2];
    u32 second = source[1];
    u32 first = source[0];
    f32 scale = *(volatile f32*)(object + 4);
    u32 fourth = source[3];
    func_00187018(scale, first, second, third, fourth);
}
