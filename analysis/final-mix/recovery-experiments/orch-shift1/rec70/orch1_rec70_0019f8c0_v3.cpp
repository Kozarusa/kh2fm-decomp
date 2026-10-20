#include "../common/types.h"
extern "C" s32 func_0019f7d0(...);

s32 func_0019f8c0(void) {
    s32 pointer = func_0019f7d0();
    s32 result;
    if (pointer == 0) {
        result = 0;
    } else {
        u16 offset = *(volatile u16*)(pointer + 2);
        result = pointer + offset;
        if (offset == 0) {
            result = 0;
        }
    }
    return result;
}
