#include "../common/types.h"
extern "C" u8 func_001a8bf8(s32, s32);

s32 func_001a8cd0(s32 object, u32 id) {
    s32 result = -1;
    u32 kind = id & 0x1f;
    if (kind != 0x12) {
        s32 index = 0;
        do {
            if (func_001a8bf8(object, index) == kind) {
                result = index;
                break;
            }
            index++;
        } while (index < 4);
    }
    return result;
}