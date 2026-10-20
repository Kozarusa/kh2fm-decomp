#include "../common/types.h"
extern "C" u32 D_0032de28[][2];
extern "C" s32 func_00194878(u32, u32);

bool func_0019eeb8(u32 first, u32 second) {
    bool result = true;
    if (func_00194878(second, first) == 0) {
        result = (D_0032de28[first][second >> 5] & (1 << (second & 0x1f))) != 0;
    }
    return result;
}
