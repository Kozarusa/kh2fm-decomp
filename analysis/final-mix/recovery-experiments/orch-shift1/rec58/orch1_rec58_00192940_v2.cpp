#include "../common/types.h"
extern "C" u32 func_00192868(...);

void func_00192940(u64 first, u64 second, s32* source) {
    s32 copy[6];
    copy[5] = source[5];
    copy[1] = source[1];
    copy[2] = source[2];
    copy[3] = source[3];
    copy[4] = source[4];
    copy[0] = source[0];
    func_00192868(first, second, copy);
}