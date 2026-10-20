#include "../common/types.h"

s32 func_0019ad00(u8* object, u32 id) {
    u8* table = *(u8**)(object + 8);
    u8* alias = table;
    s32 index = 0;
    if (*(u16*)(table + 4) != 0) {
        do {
            u8* entry = (u8*)(index << 6) + (u32)table;
            index++;
            if (entry[0x48] == 2 && entry[0x5c] == id) {
                return 1;
            }
            table = alias;
        } while (index < *(u16*)(table + 4));
    }
    return 0;
}
