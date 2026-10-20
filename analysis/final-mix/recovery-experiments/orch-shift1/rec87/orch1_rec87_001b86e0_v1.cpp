#include "../common/types.h"
extern "C" s32 D_01d48cc8[];

void func_001b86e0(s32 pointer) {
    s32 index = D_01d48cc8[48];
    s32 offset = (pointer - (s32)D_01d48cc8) >> 2;
    D_01d48cc8[48] = index + 1;
    D_01d48cc8[40 + index] = offset * -0x33333333;
}
