#include "../common/types.h"

u32 func_002d5588(s32* object) {
    s32* entry = (s32*)object[3];
    s32 value = entry[1];
    s32 isFirst = (value == 0x38);
    s32 other = value ^ 0x37;
    u32 result = 0;
    if (isFirst || other == 0) {
        result = 1;
    }
    return result;
}
