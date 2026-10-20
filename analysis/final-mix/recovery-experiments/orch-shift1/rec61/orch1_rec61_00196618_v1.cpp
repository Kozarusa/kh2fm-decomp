#include "../common/types.h"
struct Table {
    u16 count;
    u8 data[1];
};
extern "C" Table* D_01c61b08;

s32 func_00196618(u32 first, u32 second) {
    s32 index = 0;
    if (D_01c61b08->count != 0) {
        do {
            u8* entry = (u8*)D_01c61b08 + index * 2;
            if (entry[2] == first && entry[3] == second) {
                return index;
            }
            index++;
        } while (index < (s32)D_01c61b08->count);
    }
    return -1;
}
