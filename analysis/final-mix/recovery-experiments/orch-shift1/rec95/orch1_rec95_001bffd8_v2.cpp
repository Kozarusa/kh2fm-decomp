#include "../common/types.h"
extern "C" u32 D_01d49328[];
extern "C" s32 D_01d49348;

u32 func_001bffd8() {
    s32 count = 0;
    do {
        D_01d49348 = (D_01d49348 + 1) % 255;
        u32 index = D_01d49348 + 1;
        u32 bit = 1 << (index & 0x1f);
        u32 word = D_01d49328[index >> 5];
        if ((word & bit) == 0) {
            D_01d49328[index >> 5] = word | bit;
            return index;
        }
        count++;
    } while (count < 256);
    return 0;
}
