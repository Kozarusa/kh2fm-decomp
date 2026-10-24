#include "../common/types.h"
struct Item {
    s32 pad0;
    s32 pad4;
    s32 flags;
};
struct Key {
    s32 key;
    s32 value;
};
struct Header {
    s32 pad0;
    s32 count;
    Key keys[1];
};
struct Slot {
    u8 pad[128];
    Item* item;
    u8 pad84[12];
};
struct Owner {
    s32 header;
    Slot* slots;
};

// Preserve original registry aliases.
void func_001b3208(Owner* owner, s32 key) asm("_ZN2YS6OBJOCC7disableEi");

void func_001b3208(Owner* owner, s32 key) {
    for (s32 index = 0; index < ((Header*)owner->header)->count; index++) {
        if (((Header*)owner->header)->keys[index].key == key) {
            owner->slots[index].item->flags |= 2;
        }
    }
}
