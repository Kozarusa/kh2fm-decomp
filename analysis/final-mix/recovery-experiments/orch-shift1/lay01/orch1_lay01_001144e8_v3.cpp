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
    // why: keeps store order (key spill before the entries load)
    asm volatile("" ::: "memory");
    Entry* entries = table->entries;
    Entry* result = 0;
    if (entries != 0) {
        s32 count = table->count;
        s32 index = 0;
        if (count > 0) {
            result = entries;
            do {
                if (result->first == key.low) {
                    if (result->second == key.high) {
                        return result;
                    }
                    if (result->first == 0) {
                        return result;
                    }
                }
                index++;
                result++;
            } while (index < count);
            result = 0;
        }
    }
    return result;
}
