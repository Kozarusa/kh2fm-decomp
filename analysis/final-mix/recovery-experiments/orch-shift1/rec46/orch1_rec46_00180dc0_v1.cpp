#include "../common/types.h"

s32 func_00180dc0(u8* object, s32 value) {
    s32* entry = (s32*)(object + 0x14c);
    s32 index = 0;
    do {
        if (*entry++ == value) {
            return 1;
        }
        index++;
    } while (index < 16);
    return 0;
}