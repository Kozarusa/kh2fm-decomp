#include "../common/types.h"

s32 func_002bca10(s32* entry, s32 key, s32 value) {
    s32* limit = (s32*)((u8*)entry + 0x84);
    while (1) {
        if (entry[1] == key && entry[0] == value) {
            return value;
        }
        entry = entry + 3;
        if ((s32)entry >= (s32)limit) {
            return -1;
        }
    }
}
