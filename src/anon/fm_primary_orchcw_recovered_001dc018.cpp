#include "../common/types.h"
struct Entry {
    s32 first;
    s32 second;
    s32 key;
    u8 pad[20];
};
struct Table {
    u8 pad[12];
    s32 count;
    Entry entries[1];
};
struct Holder {
    Table* table;
};

bool func_001dc018(Holder* holder, s32 key, s32* outFirst, s32* outSecond) {
    s32 index = 0;
    s32 result = 0;
    s32 count = holder->table->count;
    Entry* entry = holder->table->entries;
    if (count > 0) {
        do {
            if (entry->key == key) {
                *outFirst = entry->first;
                result = 1;
                *outSecond = entry->second;
                break;
            }
            index++;
            entry++;
        } while (index < count);
    }
    return result != 0;
}
