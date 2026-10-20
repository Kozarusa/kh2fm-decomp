#include "../common/types.h"

s32 func_001da420(s32* object, s32 key) {
    s32* entry = (s32*)(*object + 0x1c);
    s32 value = entry[1];
    while (value != 0) {
        if (entry[0] == key) {
            return value;
        }
        entry += 2;
        value = entry[1];
    }
    return 0;
}
