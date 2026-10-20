#include "../common/types.h"
extern "C" u16 D_00374aa8[];
s32 func_0029ec98(u32 value) {
    u32 index = 0;
    if (D_00374aa8[0] != 0) {
        do {
            if (D_00374aa8[index] == value) return 1;
            index++;
        } while (D_00374aa8[index] != 0);
    }
    return 0;
}