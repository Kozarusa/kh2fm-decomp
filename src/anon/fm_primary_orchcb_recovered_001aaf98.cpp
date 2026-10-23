#include "../common/types.h"

s32 func_001aaf98(s32 unused, s32 x, s32 y, s32 w, s32 h) {
    s32 result = 0;
    if (x + w < 28672 || x > 0x9000 || y < 29440 || y - h > 0x8d00) {
        result = 1;
    }
    return result;
}
