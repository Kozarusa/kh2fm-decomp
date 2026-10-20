#include "../common/types.h"

s32 func_00168aa0(u8* object, u32 value) {
    s32 count = *(s32*)(object + 4);
    s32 result = 0;
    if (count > 0) {
        u8* entry = object + 16;
        do {
            u32 key = *(u16*)entry;
            s32 next = result + 1;
            count--;
            entry += 16;
            if ((key ^ value) == 0) {
                result = next;
            }
        } while (count != 0);
    }
    return result;
}