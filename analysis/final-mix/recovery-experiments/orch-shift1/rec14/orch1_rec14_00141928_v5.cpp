#include "../common/types.h"

struct Entry {
    u8 pad[16];
    u8 flag;
    u8 id;
    u8 pad2[2];
};

struct Holder {
    u8 pad[8];
    Entry* entries;
    u8 pad2[24];
    s32 count;
};

void func_00141928(Holder* object, u8 id) {
    s32 total = object->count;
    if (total > 0) {
        s32 count = total;
        s32 i = 0;
        do {
            Entry* entry = &object->entries[i];
            i++;
            if (entry->id == id) {
                entry->flag = 1;
            }
            count--;
        } while (count != 0);
    }
}
