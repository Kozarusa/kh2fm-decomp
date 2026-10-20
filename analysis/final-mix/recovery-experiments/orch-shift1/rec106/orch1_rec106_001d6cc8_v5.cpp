#include "../common/types.h"
struct Table { s32 pad0; s32 count; };
extern "C" Table* D_01d5ba98;

u32 func_001d6cc8(u32 current) {
    u32 next;
    Table* table;
    if (current == 0) {
        table = D_01d5ba98;
        return (u32)table + 8;
    }
    next = current + 64;
    table = D_01d5ba98;
    u32 end = (u32)table + table->count * 64 + 8;
    return next < end ? next : 0;
}
