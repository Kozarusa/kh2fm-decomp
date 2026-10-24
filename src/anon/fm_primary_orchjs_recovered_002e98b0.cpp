#include "../common/types.h"
extern "C" s32 D_01e2bfa4;
extern "C" s32 D_01e2bfa0;

void func_002e98b0(s32 value) {
    D_01e2bfa4 = D_01e2bfa4 + -1;
    value = value - D_01e2bfa0;
    s32 count = *(s32*)(D_01e2bfa0 + 0x7f8);
    s32 slot = count * 4 + D_01e2bfa0;
    count = count + 1;
    *(s32*)(D_01e2bfa0 + 0x7f8) = count;
    *(s32*)(slot + 0x780) = value >> 6;
}
