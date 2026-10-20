#include "../common/types.h"
extern "C" u8 D_0032de28[];
extern "C" s32 func_00194878(u32, u32);

bool func_0019eeb8(u32 first, u32 second) {
    bool result = true;
    if (func_00194878(second, first) == 0) {
        result = ((*(u32*)(D_0032de28 + first * 8 + (second >> 5) * 4)) & (1 << (second & 0x1f))) != 0;
    }
    return result;
}
