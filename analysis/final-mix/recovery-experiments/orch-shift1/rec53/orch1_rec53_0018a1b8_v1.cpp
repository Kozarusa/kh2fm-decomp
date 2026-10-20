#include "../common/types.h"

u8* func_0018a1b8(u8* object, u32 mask, u8* current) {
    u8* entry = object + 0x40;
    u8* end;
    if (current != 0) {
        entry = current + 0x14;
    }
    end = object + *(s32*)object * 0x14 + 0x40;
    if (entry < end) {
        do {
            if (mask & (1 << entry[4])) {
                return entry;
            }
            entry = entry + 0x14;
        } while (entry < end);
    }
    return 0;
}
