#include "../common/types.h"
extern "C" u32 func_001acdc0(...);

u32 func_001acf38(s32* object) {
    s32 left = object[1];
    s32 top = object[2];
    u32 width = object[23];
    u32 height = object[24];
    if (object[25] == 2) {
        return func_001acdc0(object, left, top + (height >> 1), left + (width >> 1), top + height, 0);
    }
    return func_001acdc0(object, left, top, left + (width >> 1), top + (height >> 1), 0);
}
