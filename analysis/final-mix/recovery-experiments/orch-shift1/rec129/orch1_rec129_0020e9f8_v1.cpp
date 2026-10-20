#include "../common/types.h"
extern "C" f32 D_003707c0;
extern "C" f32 D_003707c4;
extern "C" f32 D_00359110;
extern "C" f32 D_00359114;

void func_0020e9f8(f32 near_value, f32 far_value) {
    f32 diff = far_value - near_value;
    D_00359114 = (far_value * D_003707c0) / diff;
    D_00359110 = D_003707c4 / diff;
}
