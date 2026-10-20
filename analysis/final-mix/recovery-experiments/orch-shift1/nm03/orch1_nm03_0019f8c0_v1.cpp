#include "../common/types.h"
extern "C" s32 func_0019f7d0(...);

s32 func_0019f8c0(void) {
    s32 pointer = func_0019f7d0();
    if (pointer != 0) {
        u16 offset = *(u16*)(pointer + 2);
        s32 sum = pointer + offset;
        if (offset != 0) {
            return sum;
        }
    }
    return 0;
}
