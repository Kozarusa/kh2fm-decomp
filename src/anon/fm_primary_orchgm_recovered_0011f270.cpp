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
    // why: original keeps the table base in t4, the cursor in t5 and the mask in t6
    register Entry* entries asm("$12") = ((Entry* (*)())table->vtable[8])();
    s32 parent = entries[index].parent;
    // why: original keeps the mask in t6
    register u64 mask asm("$14");
    if (parent >= 0) {
        mask = 0x100000000ULL;
        u32 offset = parent << 6;
        asm("" : "+r"(offset)); // why: keeps the scaled offset out of the cursor register
        Entry* entry = (Entry*)(offset + (u32)entries);
        if ((entry->flags & mask) != 0) {
            do {
                parent = entry->parent;
                if (parent < 0) {
                    break;
                }
                offset = parent << 6;
                asm("" : "+r"(offset)); // why: keeps the scaled offset out of the cursor register
                entry = (Entry*)(offset + (u32)entries);
            } while ((entry->flags & mask) != 0);
        }
    }
    return parent;
}
