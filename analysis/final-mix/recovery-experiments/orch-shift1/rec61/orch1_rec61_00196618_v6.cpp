#include "../common/types.h"
struct Table {
    u16 count;
    u8 data[1];
};
extern "C" Table* volatile D_01c61b08;

s32 func_00196618(u32 first, u32 second) {
    s32 index = 0;
    Table* table = D_01c61b08;
    if (table->count != 0) {
        do {
            u8* entry = (u8*)(index * 2 + (u32)table);
            if (entry[2] == first && entry[3] == second) {
                return index;
            }
            index++;
            table = D_01c61b08;
        } while (index < (s32)table->count);
    }
    return -1;
}

