#include "../common/types.h"

u8* func_0018a1b8(u8* object, u32 mask, u8* current) {
    u8* entry = object + 0x40;
    u8* end;
    u8* cursor;
    u8 shift;
    if (current != 0) {
        entry = current + 0x14;
    }
    end = object + *(s32*)object * 0x14 + 0x40;
    if (entry < end) {
        shift = entry[4];
        cursor = entry;
        while (1) {
            if (mask & (1 << shift)) {
                return cursor;
            }
            if (end <= cursor + 0x14) {
                break;
            }
            shift = cursor[0x18];
            cursor = cursor + 0x14;
        }
    }
    return 0;
}
