#include "../common/types.h"
extern "C" s32 D_00350444;

s32 func_0019d380(s32 first, s32 second) {
    s32 result = *(s32*)(D_00350444 + 32);
    if (result == 0 || *(s32*)(D_00350444 + 4) != first || *(s32*)(D_00350444 + 36) != second) {
        result = 0;
    }
    return result;
}
