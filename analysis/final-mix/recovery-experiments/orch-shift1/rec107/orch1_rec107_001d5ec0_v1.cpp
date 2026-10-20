#include "../common/types.h"
extern "C" u8 D_0036e5a0[];

void func_001d5ec0(u16* list, s32 count, s32 row, s32 column) {
    s32 index = 0;
    u16* entry = (u16*)(D_0036e5a0 - 10 + row * 10 + column * 2);
    u16 value = entry[0];
    u16 key = entry[-1];
    if (count > 0) {
        do {
            u16 current = *list;
            if ((current & 0x7fff) == key) {
                *list = (current & 0x8000) | (value & 0x7fff);
                return;
            }
            index++;
            list++;
        } while (index < count);
    }
}
