#include "../common/types.h"

u8* func_0018a1b8(u8* object, u32 mask, u8* current) {
    u8* entry = object + 0x40;
    u8* end;
    u8* cursor;
    if (current != 0) {
        entry = current + 0x14;
    }
    end = object + *(s32*)object * 0x14 + 0x40;
    if (entry < end) {
        cursor = entry;
        do {
            if (mask & (1 << cursor[4])) {
                return cursor;
            }
            cursor = cursor + 0x14;
        } while (cursor < end);
    }
    return 0;
}
