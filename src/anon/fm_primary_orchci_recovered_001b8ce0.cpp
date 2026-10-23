#include "../common/types.h"
struct Entry {
    u8 id;
    u8 pad[3];
    s32 key;
    s32 extra[2];
};
struct Table {
    s32 header;
    s32 count;
    Entry entries[1];
};
extern "C" Table* D_01d48d90;
extern "C" void func_001b8838(u8);

void func_001b8ce0(s32 key) {
    s32 index = 0;
    Entry* entry = D_01d48d90->entries;
    if (D_01d48d90->count > 0) {
        do {
            if (entry->key == key) {
                func_001b8838(entry->id);
            }
            index++;
            entry++;
        } while (index < D_01d48d90->count);
    }
}
