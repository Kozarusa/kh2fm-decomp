#include "../common/types.h"

s32 func_001bcf38(s32* pointer) {
    s32 value = *pointer;
    if (value != 10) {
        if (value < 11) {
            if (value != 5) {
                return 0;
            }
        } else if ((u32)(value - 13) >= 6) {
            return 0;
        }
    }
    return 1;
}
