#include "../common/types.h"
struct Entry {
    s32 pad0;
    s32 first;
    s32 second;
    u8 pad1[24];
};
struct Table {
    u8 pad0[12];
    s32 count;
    Entry* entries;
};

Entry* func_001144e8(Table* table, u64 key) {
    Entry* entry = table->entries;
    if (entry != 0) {
        s32 index = 0;
        if (table->count > 0) {
            s32 low = ((s32*)&key)[0];
            s32 high = ((s32*)&key)[1];
            do {
                if (entry->first == low) {
                    if (entry->second == high) {
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
    return 0;
}
