#include "../common/types.h"

void func_00145c28(u8* object, u8 tag) {
    s32 count = *(s32*)(object + 0x14);
    if (count > 0) {
        s32 offset = 0;
        do {
            u8* entry = *(u8**)(object + 8) + offset;
            offset += 28;
            if (entry[1] == tag) {
                entry[0] = 0;
            }
            count--;
        } while (count != 0);
    }
}