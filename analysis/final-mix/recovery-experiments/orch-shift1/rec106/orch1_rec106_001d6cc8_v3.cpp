#include "../common/types.h"
struct Table { s32 pad0; s32 count; };
extern "C" Table* D_01d5ba98;

u32 func_001d6cc8(u32 current) {
    Table* table = D_01d5ba98;
    if (current == 0) {
        return (u32)table + 8;
    }
    u32 next = current + 64;
    if (next >= (u32)table + table->count * 64 + 8) {
        next = 0;
    }
    return next;
}
