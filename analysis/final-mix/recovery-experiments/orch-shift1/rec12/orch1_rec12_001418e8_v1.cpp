#include "../common/types.h"

void func_001418e8(u8* object, u8 key) {
    s32 count = *(s32*)(object + 0x24);
    if (count > 0) {
        s32 offset = 0;
        do {
            u8* entry = (u8*)(offset + *(s32*)(object + 8));
            offset += 0x14;
            if (entry[0x11] == key) {
                entry[0x10] = 0;
            }
            count--;
        } while (count != 0);
    }
}
