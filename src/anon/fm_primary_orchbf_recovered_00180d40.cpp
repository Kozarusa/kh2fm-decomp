#include "../common/types.h"

// Preserve original registry aliases.
void func_00180d40(u8* object, s32 value) asm("_Z16wtarget_00180d40jjjj");

void func_00180d40(u8* object, s32 value) {
    s32 slot = -1;
    s32 index = 0;
    s32* entry = (s32*)(object + 0x14c);
    do {
        s32 current = *entry;
        entry++;
        if (current == value) {
            return;
        }
        if (current < 0) {
            slot = index;
        }
        index++;
    } while (index < 16);
    *(s32*)(object + slot * 4 + 0x14c) = value;
}
