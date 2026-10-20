#include "../common/types.h"
extern "C" u8 D_00350378;
extern "C" u8 D_00350379;
extern "C" s32 D_01c61b40;
extern "C" u32 func_00198d20(s32);

void func_00196b88() {
    u32 value = func_00198d20(0);
    D_00350379 = 0;
    if (((value & 0x3f) - 2) < 2) {
        D_00350378 = 1;
        if ((value & 0xc0) == 0) {
            D_00350379 = 1;
        }
    } else {
        D_00350378 = 0;
    }
    D_01c61b40 = 1;
}
