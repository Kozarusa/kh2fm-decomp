#include "../common/types.h"
extern "C" u32 func_001d7b10(...);

u32 func_001d79b8(s32* table, s32 key, f32 value) {
    s32* slot = 0;
    s32 index = 0;
    s32* entry = table + 1;
    do {
        s32 current = entry[0];
        if (current == key) {
            slot = entry;
            break;
        }
        index++;
        slot = (current != 0) ? slot : entry;
        entry += 2;
    } while (index < 4);
    ((f32*)slot)[1] = value;
    slot[0] = key;
    return func_001d7b10();
}
