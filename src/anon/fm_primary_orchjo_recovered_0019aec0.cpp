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
    u8 pad21[3];
    Entry* entries;
};
extern "C" u8 D_0034f250[];
extern "C" u64 func_001956e8(...);
extern "C" u64 func_0019ac30(...);

void func_0019aec0(Owner* owner, s32 level) {
    for (s32 index = 0; index < owner->group->count; index++) {
        if (owner->group->entries[index].kind == 2) {
            if (owner->entries[index].level < level) {
                continue;
            }
            if (func_0019ac30(owner, owner->entries[index].id) != 0) {
                func_001956e8(D_0034f250, owner->entries[index].id);
            }
        }
    }
    owner->level = level;
}
