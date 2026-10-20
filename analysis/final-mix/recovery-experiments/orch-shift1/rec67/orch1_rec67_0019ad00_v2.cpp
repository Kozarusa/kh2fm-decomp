#include "../common/types.h"

s32 func_0019ad00(u8* object, u32 id) {
    u8* table = *(u8**)(object + 8);
    s32 index = 0;
    if (*(u16*)(table + 4) != 0) {
        do {
            u8* entry = table + (index << 6);
            index++;
            if (entry[0x48] == 2 && entry[0x5c] == id) {
                return 1;
            }
        } while (index < *(volatile u16*)(table + 4)); // why: original reloads the count each iteration
    }
    return 0;
}
