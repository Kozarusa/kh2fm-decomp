#include "../common/types.h"
extern "C" u16 D_00374aa8[];

s32 func_0029ec98(u32 value) {
    s32 result = 0;
    u32 index = 0;
    if (D_00374aa8[0] != 0) {
        do {
            if (D_00374aa8[index] == value) {
                result = 1;
                break;
            }
            index++;
        } while (D_00374aa8[index] != 0);
    }
    return result;
}
