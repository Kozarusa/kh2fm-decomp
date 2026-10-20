#include "../common/types.h"
struct Entry {
    s32 pad0;
    s32 first;
    s32 second;
    u8 pad1[24];
};
struct Key {
    s32 low;
    s32 high;
};
struct Table {
    u8 pad0[12];
    s32 count;
    Entry* entries;
};

Entry* func_001144e8(Table* table, Key key) {
    Entry* base = table->entries;
    if (base != 0) {
        s32 index;
        for (index = 0; index < table->count; index++) {
            Entry* entry = &base[index];
            if (entry->first == key.low) {
                if (entry->second == key.high) {
                    return entry;
                }
                if (entry->first == 0) {
                    return entry;
                }
            }
        }
    }
    return 0;
}
