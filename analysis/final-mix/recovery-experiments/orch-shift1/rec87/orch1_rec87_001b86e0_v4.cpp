#include "../common/types.h"
extern "C" u8 D_01d48cc8[];

void func_001b86e0(s32 pointer) {
    s32 index = *(s32*)(D_01d48cc8 + 192);
    s32 offset = (pointer - (s32)D_01d48cc8) >> 2;
    *(s32*)(D_01d48cc8 + 192) = index + 1;
    *(s32*)(D_01d48cc8 + index * 4 + 160) = offset * -0x33333333;
}
