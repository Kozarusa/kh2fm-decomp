#include "../common/types.h"
s32 func_0028b160(u8* object,s32 value) {
    u16 count = *(u16*)(object + 4);
    s32 index = 0;
    if ((s16)count > 0) {
        s32* pointer = *(s32**)(object + 40);
        do {
            if (value == *pointer++) break;
            ++index;
        } while (index < (s16)count);
    }
    s32 result = -1;
    if (index < (s16)count) result = index;
    return result;
}

