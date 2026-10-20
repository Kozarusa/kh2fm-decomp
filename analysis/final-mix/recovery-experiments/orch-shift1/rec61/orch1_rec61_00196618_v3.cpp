#include "../common/types.h"
struct Pair {
    u8 a;
    u8 b;
};
struct Table {
    u16 count;
    Pair entries[1];
};
extern "C" Table* D_01c61b08;

s32 func_00196618(u32 first, u32 second) {
    s32 index = 0;
    if (D_01c61b08->count != 0) {
        do {
            if (D_01c61b08->entries[index].a == first && D_01c61b08->entries[index].b == second) {
                return index;
            }
            index++;
        } while (index < (s32)D_01c61b08->count);
    }
    return -1;
}
