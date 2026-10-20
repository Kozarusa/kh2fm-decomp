#include "../common/types.h"

s32 func_00179c80(u8* object) {
    s32 result = 0;
    if (*(s32*)(object + 0xb50) == 7) {
        s32 state = *(s32*)(object + 0x154);
        if (state == 0xcb) {
            return 1;
        }
        if (state == 0xcc) {
            return 1;
        }
    }
    return result;
}