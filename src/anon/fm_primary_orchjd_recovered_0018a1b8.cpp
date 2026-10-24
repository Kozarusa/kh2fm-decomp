#include "../common/types.h"

u8* func_0018a1b8(u8* object, u32 mask, u8* current) {
    u8* end = object + *(s32*)object * 0x14 + 0x40;
    u8* entry = current + 0x14;
    if (current == 0) {
        entry = object + 0x40;
    }
    for (current = entry; current < end; current = current + 0x14) {
        if (mask & (1 << current[4])) {
            return current;
        }
    }
    return 0;
}
