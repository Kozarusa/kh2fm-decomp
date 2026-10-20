#include "../common/types.h"
struct Item { u8 a; u8 b; u8 pad[12]; };
struct Table { s32 head; s32 count; Item items[1]; };
extern "C" Table* D_01c940b4;

Item* func_001aff90(u32 first, u32 second) {
    Table* table = D_01c940b4;
    for (s32 index = 0; index < table->count; index++) {
        Item* item = &table->items[index];
        if (item->a == first && item->b == second) {
            return item;
        }
    }
    return 0;
}
