#include "../common/types.h"
extern "C" u16 D_0036e5a0[][5];

u16 func_001d5ec0(u16* list, s32 count, s32 row, s32 column) {
    s32 index = 0;
    u16* entry = &D_0036e5a0[row - 1][column];
    u16 value = entry[0];
    u16 key = entry[-1];
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
