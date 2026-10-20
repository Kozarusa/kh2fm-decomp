#include "../common/types.h"

u8* func_00168b38(u8* object, u32 key, s32 skip) {
    s32 count = *(s32*)(object + 4);
    s32 index = 0;
    if (count > 0) {
        u8* entry = object + 16;
        do {
            if (key == 0xffffffff || *(u16*)entry == key) {
                skip--;
                if (skip == -1) {
                    return entry;
                }
            }
            index++;
            entry += 16;
        } while (index < count);
    }
    return 0;
}
