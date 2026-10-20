#include "../common/types.h"
struct Table {
    u16 count;
    u8 data[1];
};
extern "C" Table* volatile D_01c61b08;

s32 func_00196618(u32 first, u32 second) {
    Table* table = D_01c61b08;
    s32 index;
    for (index = 0; index < (s32)table->count; index++) {
        u8* entry = (u8*)table + index * 2;
        if (entry[2] == first && entry[3] == second) {
            return index;
        }
        table = D_01c61b08;
    }
    return -1;
}
