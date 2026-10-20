#include "../common/types.h"

void func_00145c68(u8* object, u8 tag) {
    s32 count = *(s32*)(object + 0x14);
    if (count > 0) {
        s32 remaining = count;
        u8 value = 1;
        s32 offset = 0;
        do {
            u8* entry = (u8*)((u32)offset + *(u32*)(object + 8));
            offset += 28;
            if (entry[1] == tag) {
                entry[0] = value;
            }
            remaining--;
        } while (remaining != 0);
    }
}