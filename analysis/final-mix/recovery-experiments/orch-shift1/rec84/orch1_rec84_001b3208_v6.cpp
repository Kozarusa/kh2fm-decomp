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
    Header* header = owner->header;
    s32 index = 0;
    s32 offset = 0;
    while (index < header->count) {
        Header* base = header;
        s32 slot = index;
        index++;
        if (base->keys[slot][0] == key) {
            Item* item = *(Item**)(offset + owner->entries + 128);
            item->flags |= 2;
            header = owner->header;
        }
        offset += 144;
    }
}
