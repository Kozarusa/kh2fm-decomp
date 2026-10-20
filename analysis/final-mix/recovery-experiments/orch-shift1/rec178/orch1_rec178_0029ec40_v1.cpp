#include "../common/types.h"
extern "C" u16 D_00374aa0[];
s32 func_0029ec40(u32 value) {
    u32 index=0;
    if(D_00374aa0[0]) {
        do {
            if(D_00374aa0[index]==value) return 1;
            ++index;
        } while(D_00374aa0[index]);
    }
    return 0;
}
