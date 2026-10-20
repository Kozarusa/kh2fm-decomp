#include "../common/types.h"

void func_00188b68(s32 pointer, u16 value, u8 flag) {
    s32 index;
    u16* entry;

    entry = (u16*)(pointer + 0x50);
    for (index = 0; index < 0x50; index++) {
        if ((entry[2] & 0x7fff) == 0) {
            entry[2] = (value & 0x7fff) | ((flag != 0) << 15);
            return;
        }
        entry++;
    }
}
