#include "../common/types.h"
extern "C" u32 func_00187018(f32, u64, s32, u64, s64);

void func_0018fd40(s32* object) {
    func_00187018(*(f32*)(object + 4), object[0], object[1], object[2], object[3]);
}
