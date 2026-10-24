#include "../common/types.h"

union EntryInfo {
    s32 word;
    u16 half;
};

struct Entry {
    u32 hash;
    EntryInfo info;
    u32 unused[2];
};

struct Table {
    s32 count;
    Entry entries[1];
};

extern "C" u32 func_001ae210(s8* pointer);
extern "C" u16 func_001ae270(int arg1);

Entry* func_001ae308(Table* table, s8* name) {
    if (table == 0) return 0;
    u32 hash = func_001ae210(name);
    if (table->count <= 0) return 0;
    s32 low = 0;
    s32 high = table->count - 1;
    Entry* entry;
    do {
        s32 middle = (low + high) / 2;
        entry = &table->entries[middle];
        if (entry->hash == hash) break;
        if (entry->hash < hash) low = middle + 1;
        else high = middle - 1;
    } while (high - low >= 0);
    if (entry->hash != hash) entry = 0;
    if (entry != 0 && entry->info.word < 0) {
        u16 second = func_001ae270((int)name);
        if (entry != &table->entries[0] && entry[-1].hash == hash) {
            do {
                entry--;
            } while (entry[-1].hash == hash);
        }
        while (entry->hash == hash && entry->info.half != second) entry++;
        if (entry->hash != hash || entry->info.half != second) entry = 0;
    }
    return entry;
}
