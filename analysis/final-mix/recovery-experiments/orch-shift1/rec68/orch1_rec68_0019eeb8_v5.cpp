#include "../common/types.h"
extern "C" u32 D_0032de28[][2];
extern "C" s32 func_00194878(u32, u32);

bool func_0019eeb8(u32 first, u32 second) {
    bool result = true;
    if (func_00194878(second, first) == 0) {
        u32* row = D_0032de28[first];
        u32* word = row + (second >> 5);
        u32 mask = 1 << (second & 0x1f);
        result = (*word & mask) != 0;
    }
    return result;
}
