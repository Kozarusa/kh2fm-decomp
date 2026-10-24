#include "../common/types.h"
struct Entry {
    u8 id;
    u8 pad[0x43];
};
struct Table {
    s32 count;
    Entry entries[1];
};

s32 func_001d7f40(Table* table, s32 key) {
    s32 count = table->count;
    s32 index;
    for (index = 0; index < count; index++) {
        if (table->entries[index].id == key) {
            return index;
        }
    }
    return -1;
}
