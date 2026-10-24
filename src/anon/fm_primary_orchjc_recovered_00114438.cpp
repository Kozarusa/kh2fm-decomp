#include "../common/types.h"
struct Entry {
    s32 id;
    u8 pad[124];
};
struct Table {
    u8 pad[160];
    s32 count;
    s32 offset;
};
struct Object {
    u8 pad[8];
    Table* table;
};

Entry* func_00114438(Object* object, s32 value) {
    Table* table = object->table;
    Entry* result = 0;
    if (table != 0) {
        Entry* entries = (Entry*)((u8*)table + table->offset);
        register s32 count asm("$13") = table->count; // why: original loads the count into t5
        s32 index = 0;
        if (count > 0) {
            register s32 limit asm("$11") = count; // why: original copies the count into t3 for the loop test
            do {
                Entry* entry = (Entry*)((u32)(index * 128) + (u32)entries);
                index++;
                if (entry->id == value) {
                    result = entry;
                    break;
                }
            } while (index < limit);
        }
    }
    return result;
}
