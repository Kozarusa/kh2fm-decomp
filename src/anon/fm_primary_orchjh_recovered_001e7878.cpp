#include "../common/types.h"

struct Entry {
    u8 pad[20];
    void (*callback)(void*);
};

struct Owner {
    u8 pad0[100];
    s32 count;
    u8 pad1[16];
    Entry** entries;
};

void func_001e7878(Owner* owner) {
    register s32 index asm("$16") = 0; // why: original keeps index in s0
    register Owner* self asm("$17") = owner; // why: original keeps owner in s1
    s32 count = owner->count;
    if (count > 0) {
        do {
            Entry* entry = self->entries[index];
            void (*callback)(void*) = entry->callback;
            index++;
            if (callback != 0) {
                callback(self);
                count = self->count;
            }
        } while (index < count);
    }
}
