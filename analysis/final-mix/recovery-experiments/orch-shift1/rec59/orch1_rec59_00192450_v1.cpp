#include "../common/types.h"

s32 func_00192450(u8* base, s32 index) {
    u32 value = base[index];
    u32 high = value - 25;
    s32 result = value - 32;
    if (value < 32) {
        if ((high & 0xff) < 7) {
            return (high << 8) + base[index + 1] + 224;
        }
        result = -1;
    }
    return result;
}
