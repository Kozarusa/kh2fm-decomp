#include "../common/types.h"
struct Entry {
    s32 key;
    f32 value;
};
struct Table {
    s32 header;
    Entry entries[4];
};
extern "C" u32 func_001d7b10(...);

u32 func_001d79b8(Table* table, s32 key, f32 value) {
    Entry* slot = 0;
    s32 index = 0;
    Entry* entry = table->entries;
    // why: keeps the entry cursor in its own register apart from the argument register`n    asm("" : "+r"(entry));`n    do {
        if (entry->key == key) {
            slot = entry;
            break;
        }
        index++;
        if (entry->key == 0) {
            slot = entry;
        }
        entry++;
    } while (index < 4);
    slot->value = value;
    slot->key = key;
    return func_001d7b10();
}

