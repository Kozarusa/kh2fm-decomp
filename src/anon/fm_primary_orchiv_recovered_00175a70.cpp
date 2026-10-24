#include "../common/types.h"
struct Item {
    struct ItemVtable *vtable;
};
struct ItemVtable {
    u8 pad[40];
    void (*update)(Item *);
};
struct Owner;
struct OwnerVtable {
    u8 pad[32];
    void (*prepare)(Owner *);
};
struct Owner {
    OwnerVtable *vtable;
    u8 pad0[0x104];
    u32 flags;
    u8 pad1[0x9ec];
    Item *items[2];
};
extern "C" u64 func_0016b668(...);

u64 func_00175a70(Owner *object) {
    if ((object->flags & 0x10000000) == 0) {
        object->vtable->prepare(object);
    }
    Item **slot = object->items;
    s32 index = 1;
    do {
        Item *item = *slot;
        slot++;
        if (item != 0) {
            item->vtable->update(item);
        }
        index--;
    } while (index >= 0);
    return func_0016b668(object);
}
