#include "../common/types.h"

s32* func_00114490(u8* object, s32 value) {
    s32* result = 0;
    u32 table = *(u32*)(object + 8);
    if (table != 0) {
        s32 offset = *(s32*)(table + 180);
        u32 index = 0;
        s32 count = *(s32*)(table + 176);
        u32 base = table + offset;
        if (count > 0) {
            s32 limit = count;
            asm("" : "+r"(limit)); // why: original copies the count into its own loop register
            do {
                s32* item = (s32*)((index << 7) + base);
                index++;
                if (*item == value) {
                    result = item;
                    break;
                }
            } while ((s32)index < limit);
        }
    }
    return result;
}
