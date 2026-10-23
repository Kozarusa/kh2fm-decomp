#include "../common/types.h"
extern "C" u8 D_004f6440[];
extern "C" s32 D_0034dc98;
extern "C" s32 D_01c5f460[];
extern "C" s32 func_00106178(u8*, s32);

void func_0016f970() {
    D_0034dc98 = func_00106178(D_004f6440, 0x4000);
    s32* pointer = D_01c5f460;
    s32 count = 6;
    do {
        *pointer = 0;
        count = count - 1;
        pointer = pointer + 1;
    } while (count >= 0);
    D_01c5f460[1] = 0xe0000;
    D_01c5f460[5] = 0x300000;
    D_01c5f460[6] = 0xc0000;
}
