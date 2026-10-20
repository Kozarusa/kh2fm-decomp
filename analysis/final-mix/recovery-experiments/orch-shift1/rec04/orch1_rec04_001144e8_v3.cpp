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
    Entry* entry = table->entries;
    if (entry != 0) {
        s32 index = 0;
        if (table->count > 0) {
            Entry* cursor = entry;
            do {
                if (cursor->first == key.low) {
                    if (cursor->second == key.high) {
                        return cursor;
                    }
                    if (cursor->first == 0) {
                        return cursor;
                    }
                }
                index++;
                cursor++;
            } while (index < table->count);
        }
    }
    return 0;
}
