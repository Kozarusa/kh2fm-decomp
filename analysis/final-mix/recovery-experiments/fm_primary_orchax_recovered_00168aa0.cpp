#include "../common/types.h"

s32 func_00168aa0(u8* object, u32 value) {
    s32 total = *(s32*)(object + 4);
    s32 result = 0;
    if (total > 0) {
        u8* entry = object + 16;
        s32 remaining = total;
        do {
            u32 key = *(u16*)entry;
            s32 next = result + 1;
            remaining--;
            entry += 16;
            if ((key ^ value) == 0) {
                result = next;
            }
        } while (remaining != 0);
    }
    return result;
}
