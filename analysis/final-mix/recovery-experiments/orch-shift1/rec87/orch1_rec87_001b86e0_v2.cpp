#include "../common/types.h"
extern "C" s32 D_01d48cc8[];

void func_001b86e0(s32 pointer) {
    s32* slot = &D_01d48cc8[40 + D_01d48cc8[48]];
    D_01d48cc8[48] = D_01d48cc8[48] + 1;
    *slot = ((pointer - (s32)D_01d48cc8) >> 2) * -0x33333333;
}
