#include "../common/types.h"
extern "C" u32 func_00139570(s32);

struct Group {
    u8 pad0[4];
    s16 count;
    u8 pad6[34];
    s32* entries;
};

void func_0028a908(Group* group) {
    s32 index = 0;
    if (group->count > 0) {
        do {
            s32 entry = group->entries[index];
            index++;
            if (entry != 0) {
                func_00139570(entry);
            }
        } while (index < group->count);
    }
}
