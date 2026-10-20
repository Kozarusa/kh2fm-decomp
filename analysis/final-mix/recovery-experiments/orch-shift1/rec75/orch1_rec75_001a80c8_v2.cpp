#include "../common/types.h"
struct Entry { u16 id; u8 pad[22]; };
struct Table { s32 a; s32 count; Entry entries[1]; };
extern "C" Table* D_01c6cb90;

Entry* func_001a80c8(s32 id) {
    Entry* entry;
    s32 index;
    for (index = 0, entry = D_01c6cb90->entries; index < D_01c6cb90->count; index++, entry++) {
        if (entry->id == id) {
            return entry;
        }
    }
    return 0;
}
