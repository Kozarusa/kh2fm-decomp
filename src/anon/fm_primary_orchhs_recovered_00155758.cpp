#include "../common/types.h"
extern "C" f32 D_004f3588;
extern "C" f32 func_0017ce10(f32);

s32 func_00155758(s32 value, s32* flag, s32* third, s32* first, s32* second, f32* angle) {
    if (value >= 60) {
        return 1;
    }
    *(volatile s32*)flag = 0;
    *angle = (f32)value * *(volatile f32*)&D_004f3588;
    *angle = func_0017ce10(*angle);
    if (value < 20) {
        *first = 64;
        *second = 100;
        *third = -50;
    } else if (value < 40) {
        *first = 64;
        *second = 50;
        *third = 0;
    } else {
        *first = 0;
        *second = 0;
        *third = 50;
    }
    return 0;
}
