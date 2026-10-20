#include "../common/types.h"

struct Entry {
    u8 pad[16];
    void (*callback)(void*);
};

struct Owner {
    u8 pad0[100];
    s32 count;
    u8 pad1[16];
    Entry** entries;
};

void func_001e7810(Owner* owner) {
    s32 index = 0;
    if (owner->count > 0) {
        do {
            Entry* entry = owner->entries[index];
            void (*callback)(void*) = entry->callback;
            index++;
            if (callback != 0) {
                callback(owner);
            }
        } while (index < owner->count);
    }
}