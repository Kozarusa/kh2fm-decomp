#include "../common/types.h"
extern "C" f32 D_003707c0;
extern "C" f32 D_003707c4;
extern "C" f32 D_00359110;

void func_0020e9f8(f32 near_value, f32 far_value) {
    f32* out = &D_00359110;
    f32* scale = &D_003707c0;
    f32 diff = far_value - near_value;
    out[1] = (far_value * *scale) / diff;
    D_00359110 = D_003707c4 / diff;
}
