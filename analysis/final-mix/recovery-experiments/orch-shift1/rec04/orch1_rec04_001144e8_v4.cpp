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
    Entry* result = 0;
    Entry* entry = table->entries;
    if (entry != 0) {
        s32 index = 0;
        if (table->count > 0) {
            do {
                if (entry->first == key.low) {
                    if (entry->second == key.high) {
                        return entry;
                    }
                    if (entry->first == 0) {
                        return entry;
                    }
                }
                index++;
                entry++;
            } while (index < table->count);
        }
    }
    return result;
}


