#include "../common/types.h"

s32 func_001da420(s32* object, s32 key) {
    s32* entry = (s32*)(*object + 0x1c);
    s32 value = entry[1];
    s32 next;
    if (value == 0) {
        return 0;
    }
    do {
        if (entry[0] == key) {
            return value;
        }
        entry += 2;
        next = entry[1];
        value = next;
    } while (next != 0);
    return 0;
}
