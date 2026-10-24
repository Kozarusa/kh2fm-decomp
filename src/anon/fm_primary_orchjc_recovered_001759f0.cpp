#include "../common/types.h"
struct Item;
struct ItemVtable {
    u8 pad[36];
    s32 (*check)(Item*);
};
struct Item {
    ItemVtable* vtable;
};
extern "C" u32 func_00198510(u32);

s32 func_001759f0(u32 object) {
    if (func_00198510(object) == 0) {
        return 0;
    }
    Item** slot = (Item**)(object + 0xaf8);
    s32 index = 0;
    do {
        Item* item = *slot;
        slot++;
        if (item != 0) {
            if (item->vtable->check(item) == 0) {
                return 0;
            }
        }
        index++;
    } while (index < 2);
    return 1;
}
