#include "../common/types.h"

struct Entry {
    u8 pad[20];
    void (*callback)(void*);
};

struct Holder {
    u8 pad0[100];
    s32 count;
    u8 pad1[16];
    Entry** entries;
};

void func_001e7878(Holder* argument) {
    s32 index = 0;
    Holder* object = argument;
    if (object->count > 0) {
        do {
            void (*callback)(void*) = object->entries[index]->callback;
            index++;
            if (callback != 0) {
                callback(object);
            }
        } while (index < object->count);
    }
}
