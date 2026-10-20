#include "../common/types.h"
struct Item {
    struct ItemVtable *vtable;
};
struct ItemVtable {
    u8 pad[36];
    s64 (*check)(Item *);
};
extern "C" s64 func_00198510(u8 *);

s32 func_001759f0(u8 *object) {
    s32 result = 0;
    if (func_00198510(object) != 0) {
        Item **slot = (Item **)(object + 0xaf8);
        s32 index = 0;
        Item *item = *slot;
        while (1) {
            slot++;
            if (item != 0 && item->vtable->check(item) == 0) {
                return 0;
            }
            index++;
            if (index > 1) break;
            item = *slot;
        }
        result = 1;
    }
    return result;
}