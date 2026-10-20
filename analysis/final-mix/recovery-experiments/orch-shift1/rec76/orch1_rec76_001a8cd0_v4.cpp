#include "../common/types.h"
extern "C" u8 func_001a8bf8(s32, s32);

s32 func_001a8cd0(s32 object, u32 id) {
    u32 kind = id & 0x1f;
    s32 index;
    if (kind == 0x12) {
        return -1;
    }
    index = 0;
    do {
        if (func_001a8bf8(object, index) == kind) {
            return index;
        }
        index++;
    } while (index < 4);
    return -1;
}