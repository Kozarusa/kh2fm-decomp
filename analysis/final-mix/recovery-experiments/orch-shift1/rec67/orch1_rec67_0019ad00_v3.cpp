#include "../common/types.h"

struct Entry {
    u8 pad[0x48];
    u8 type;
    u8 pad2[0x13];
    u8 id;
    u8 pad3[0x23];
};

struct Table {
    u8 pad[4];
    u16 count;
    u8 pad2[0x42];
    Entry entries[1];
};

struct Object {
    u8 pad[8];
    Table* table;
};

s32 func_0019ad00(Object* object, u32 id) {
    Table* table = object->table;
    s32 index = 0;
    if (table->count != 0) {
        do {
            Table* base = table;
            u8* entry = (u8*)base + (index << 6);
            index++;
            if (entry[0x48] == 2 && entry[0x5c] == id) {
                return 1;
            }
        } while (index < (s32)object->table->count);
    }
    return 0;
}
