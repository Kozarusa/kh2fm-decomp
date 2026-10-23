#include "../common/types.h"
struct Item {
    struct ItemVtable *vtable;
};
struct ItemVtable {
    u8 pad[72];
    void (*update)(Item *);
};
extern "C" void func_00177638(u8 *);

void func_00177540(u8 *object) {
    Item **slot = (Item **)(object + 0xaf8);
    s32 index = 1;
    do {
        Item *item = *slot;
        slot++;
        if (item != 0) {
            item->vtable->update(item);
        }
        index--;
    } while (index >= 0);
    func_00177638(object);
}
