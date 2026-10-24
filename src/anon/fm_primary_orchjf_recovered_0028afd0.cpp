// func_0028afd0: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"

struct Item {
    s16 base;
    u8 pad2[16];
    s16 value;
    u8 pad20[17];
    u8 flag;
};

extern "C" bool func_0028b1c0(Item*, s32);
extern "C" void func_00289b30(Item*, Item*, s16*);

void func_0028afd0(Item* item, s32 value) {
    item->value = value;
    s32 index = (s16)value + item->base;
    if (item->flag == 0) {
        if (func_0028b1c0(item, index)) {
            func_00289b30(item, item, &item->value);
        }
    }
}
