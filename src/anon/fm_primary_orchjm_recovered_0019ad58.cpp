#include "../common/types.h"
struct Entry {
    u32 chara;
    u8 pad04[0x18];
    u8 kind;
    u8 pad1d;
    u16 id;
    u8 pad20[0x10];
    u8 level;
    u8 pad31[0xf];
};
struct Group {
    u32 pad0;
    u16 count;
    u8 pad06[0x26];
    Entry entries[1];
};
struct Owner {
    u32 pad0;
    u32 pad4;
    Group* group;
    u8 pad0c[0x14];
    u8 level;
};
extern "C" u64 func_0019ac30(...);
extern "C" u8* func_0016e920(u32);

s32 func_0019ad58(Owner* owner) {
    s32 total = 0;
    for (s32 index = 0; index < owner->group->count; index++) {
        switch (owner->group->entries[index].kind) {
        case 2:
            if (owner->level < owner->group->entries[index].level) {
                break;
            }
        case 0:
        case 3:
            if (func_0019ac30(owner, owner->group->entries[index].id) == 0) {
                total += func_0016e920(owner->group->entries[index].chara)[0x54];
            }
            break;
        }
    }
    return total;
}
