#include "../common/types.h"
extern "C" u32 D_0034dca0[];
extern "C" u32 D_0034dcb8[];

void func_00170ee8(s32 initialize, s32 priority) {
    if (priority == 0xffff && initialize == 1) {
        u32* pair = D_0034dca0;
        pair[0] = 0;
        pair[1] = 0;
    }
    if (priority == 0xffff && initialize == 1) {
        u32* pair = D_0034dcb8;
        pair[0] = 0;
        pair[1] = 0;
    }
}
