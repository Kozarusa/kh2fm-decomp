#include "../common/types.h"
extern "C" u8* D_0035ec94;

s32 func_00241a00() {
    s32 result = 0;
    u32* pointer = (u32*)(D_0035ec94 + 8);
    s32 count;
    for (count = 0; count < 99; count++) {
        if (*pointer & 0x10) {
            result = 1;
            break;
        }
        pointer += 8;
    }
    return result;
}
