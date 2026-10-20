#include "../common/types.h"
extern "C" u32 func_00192868(...);

void func_00192940(u64 first, u64 second, s32* source) {
    s32 copy[6];
    s32 w5 = source[5];
    s32 w1 = source[1];
    s32 w2 = source[2];
    s32 w3 = source[3];
    s32 w4 = source[4];
    s32 w0 = source[0];
    copy[2] = w2;
    copy[0] = w0;
    copy[1] = w1;
    copy[3] = w3;
    copy[4] = w4;
    copy[5] = w5;
    func_00192868(first, second, copy);
}