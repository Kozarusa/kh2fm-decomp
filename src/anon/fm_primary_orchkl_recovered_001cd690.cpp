#include "../common/types.h"
struct Entry {
    s32 value;
    s32 handle;
};
extern "C" bool func_0019ba60(u64);

// why: every exit leaves the v0 of the last func_0019ba60 call untouched, so that flag is returned

bool func_001cd690(Entry* entries, s32 value, s32 handle) {
    s32 index;
    Entry* entry = entries;
    for (index = 7; index >= 0; index--, entry++) {
        u32 invalid = 0;
        if (entry->handle == 0 || !func_0019ba60(entry->handle)) {
            invalid = 1;
        }
        if ((invalid & 0xff) == 0) {
            if (!func_0019ba60(entry->handle)) {
                entry->handle = 0;
            }
        }
    }
    bool alive = func_0019ba60(handle);
    if (alive) {
        Entry* slot = 0;
        for (index = 0; index < 8; index++) {
            Entry* current = (Entry*)(index * 8 + (u32)entries);
            if (current->handle == handle) {
                slot = current;
                break;
            }
            bool invalid = false;
            if (current->handle == 0 || !(alive = func_0019ba60(current->handle))) {
                invalid = true;
            }
            if (invalid) {
                slot = entries + index;
            }
        }
        slot->value = value;
        slot->handle = handle;
    }
    return alive;
}
