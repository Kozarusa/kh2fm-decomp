#include "../common/types.h"

s32 func_001aaf98(s32 unused, s32 x, s32 y, s32 w, s32 h) {
    if (x + w >= 28672) {
        if (x > 0x9000) {
            return 1;
        }
        if (y < 29440) {
            return 1;
        }
        if (y - h <= 0x8d00) {
            return 0;
        }
    }
    return 1;
}
