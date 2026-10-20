#include "../common/types.h"
struct Item {
    s32 pad;
    s32 pad4;
    u32 flags;
};
struct Header {
    s32 pad;
    s32 count;
    s32 keys[1][2];
};
struct Owner {
    Header* header;
    s32 entries;
};

void func_001b3208(Owner* owner, s32 key) {
    Header* base = owner->header;
    Header* current = base;
    s32 index = 0;
    if (base->count > 0) {
        s32 offset = 0;
        do {
            s32 slot = index;
            index++;
            if (base->keys[slot][0] == key) {
                Item* item = *(Item**)(offset + owner->entries + 128);
                item->flags = item->flags | 2;
                current = owner->header;
            }
            base = current;
            offset += 144;
        } while (index < current->count);
    }
}
