#include "../common/types.h"
extern "C" f32 D_0036e8b0;
// why: types copied from the accepted definition in tiny_auto80_fptr4.cpp; extern "C" because its C++ linkage fails the isolated probe link (v2)
extern "C" u32 func_001e09a0(u32, u32, u32, u32);

f32 func_001e09d0(u32 table) {
    f32 total = 0.0f;
    f32 weight = total;
    f32* step_pointer = &D_0036e8b0;
    asm("" : "+r"(step_pointer)); // why: original forms the full address (lui+addiu) before loading the step
    f32 step = *step_pointer;
    for (s32 row = 0; row < 9; row++) {
        for (s32 column = 1; column < 4; column++) {
            weight += step;
            total += *(f32*)(func_001e09a0(table, row, column, 0) + 0x20);
        }
    }
    f32* scale_pointer = &D_0036e8b0;
    asm("" : "+r"(scale_pointer)); // why: original forms the full address (lui+addiu) again before loading the scale
    return total / weight * *scale_pointer;
}
