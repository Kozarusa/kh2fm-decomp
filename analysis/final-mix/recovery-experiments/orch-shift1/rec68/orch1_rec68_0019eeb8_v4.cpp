#include "../common/types.h"
extern "C" u32 D_0032de28[][2];
extern "C" s32 func_00194878(u32, u32);

bool func_0019eeb8(u32 first, u32 second) {
    s32 found = func_00194878(second, first);
    u32* row = D_0032de28[first];
    u32* word = row + (second >> 5);
    u32 mask = 1 << (second & 0x1f);
    bool result = true;
    if (found == 0) {
        result = (*word & mask) != 0;
    }
    return result;
}
