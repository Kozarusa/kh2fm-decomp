#include "../common/types.h"

s32 func_00179c80(u8* object) {
    s32 result = 0;
    if (*(s32*)(object + 0xb50) == 7) {
        if (*(s32*)(object + 0x154) == 0xcb) {
            result = 1;
        }
        if (*(s32*)(object + 0x154) == 0xcc) {
            result = 1;
        }
    }
    return result;
}