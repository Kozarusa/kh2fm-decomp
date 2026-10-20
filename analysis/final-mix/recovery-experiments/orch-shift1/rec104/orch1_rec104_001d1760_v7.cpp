#include "../common/types.h"

u32 func_001d1760(s32* object, s32 limit) {
    s32 value = object[7];
    u32 result = 0;
    if (value > 0) {
        if (value < object[5]) {
            if (value >= limit) {
                result = 1;
            }
        } else if (value <= limit) {
            return 1;
        }
    }
    return result;
}