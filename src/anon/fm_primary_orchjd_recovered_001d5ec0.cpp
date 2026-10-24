#include "../common/types.h"
extern "C" u8 D_0036e5a0[];

u16 func_001d5ec0(u16* list, s32 count, s32 row, s32 column) {
    s32 stride = 10;
    asm("" : "+r"(stride)); // why: original multiplies by a register-held stride instead of shifting
    s32 index = 0;
    u16* rowBase = (u16*)(D_0036e5a0 - 10 + row * stride);
    u16* entry = rowBase + column;
    u16 key = entry[-1];
    u16 value = entry[0];
    if (count > 0) {
        do {
            u16 current = *list;
            if ((current & 0x7fff) == key) {
                *list = (current & 0x8000) | (value & 0x7fff);
                return value;
            }
            index++;
            list++;
        } while (index < count);
    }
    return value;
}
