#include "../common/types.h"

s32 func_002bc9d8(u8* object, s32 key) {
    s32* entry = (s32*)(object + 0x84);
    s32* limit = (s32*)(object + 300);
    while (1) {
        if (entry[1] == key) {
            return entry[0];
        }
        entry = entry + 3;
        if ((s32)entry >= (s32)limit) {
            return -1;
        }
    }
}
