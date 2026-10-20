#include "../common/types.h"
struct Entry { u16 id; u8 pad[22]; };
struct Table { s32 a; s32 count; Entry entries[1]; };
extern "C" Table* D_01c6cb90;

Entry* func_001a80c8(s32 id) {
    s32 index = 0;
    Table* table = D_01c6cb90;
    s32 count = table->count;
    if (count > 0) {
        Entry* entry = table->entries;
        do {
            if (entry->id == id) {
                return entry;
            }
            entry++;
            index++;
        } while (index < count);
    }
    return 0;
}
