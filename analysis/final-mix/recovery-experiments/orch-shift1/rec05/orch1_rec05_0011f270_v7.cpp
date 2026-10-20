#include "../common/types.h"
struct Entry {
    u8 pad0[4];
    s16 parent;
    u8 pad1[2];
    u64 flags;
    u8 pad2[0x30];
};
struct Table {
    void** vtable;
};

s32 func_0011f270(Table* table, s32 index) {
    Entry* entries = ((Entry* (*)())table->vtable[8])();
    s32 parent = entries[index].parent;
    if (parent >= 0) {
        Entry* entry = &entries[parent];
        u64 mask = 0x100000000ULL;
        if ((entry->flags & mask) != 0) {
            do {
                parent = entry->parent;
                if (parent < 0) {
                    break;
                }
                entry = &entries[parent];
            } while ((entry->flags & mask) != 0);
        }
    }
    return parent;
}

