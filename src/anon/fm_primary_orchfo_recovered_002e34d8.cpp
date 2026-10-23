#include "../common/types.h"

u8* func_002e34d8(u8** object, s32 count) {
    u8* cursor = *object;
    cursor += 16;
    if (count > 0) {
        do {
            count--;
            cursor = cursor + cursor[10] * 12 + 64;
        } while (count != 0);
    }
    return cursor;
}
