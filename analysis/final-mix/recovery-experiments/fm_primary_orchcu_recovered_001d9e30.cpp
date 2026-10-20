#include "../common/types.h"
struct Table {
    s32 pad;
    s32 count;
};
extern "C" Table* D_01d5baa8;

u8* func_001d9e30(u8* entry) {
    if (entry == 0) {
        return (u8*)D_01d5baa8 + 8;
    }
    entry += 10;
    return entry < (u8*)D_01d5baa8 + D_01d5baa8->count * 10 + 8 ? entry : 0;
}
