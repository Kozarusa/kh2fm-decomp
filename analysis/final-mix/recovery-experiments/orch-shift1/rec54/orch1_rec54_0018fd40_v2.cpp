#include "../common/types.h"
extern "C" u32 func_00187018(f32, u32, u32, u32, u32);

void func_0018fd40(u32* object) {
    u32 third = object[2];
    u32 second = object[1];
    u32 first = object[0];
    f32 scale = *(f32*)(object + 4);
    u32 fourth = object[3];
    func_00187018(scale, first, second, third, fourth);
}
