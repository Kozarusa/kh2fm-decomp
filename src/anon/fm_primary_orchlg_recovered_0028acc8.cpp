#include "../common/types.h"
// why: the only recovered call sites declare no argument, but the original passes the entry in a0 and tests the v0 result
extern "C" u32 func_00139d78(s32);

struct Group {
    u8 pad0[4];
    s16 count;
    u8 pad6[34];
    s32* entries;
};

// Preserve original registry aliases.
u32 func_0028acc8(Group* group) asm("_ZN2Tz6Select9isCreatedEz");

u32 func_0028acc8(Group* group) {
    s32 index = 0;
    if (group->count > 0) {
        do {
            s32 entry = group->entries[index];
            index++;
            if (entry != 0) {
                if (func_00139d78(entry) != 0) {
                    return 1;
                }
            }
        } while (index < group->count);
    }
    return 0;
}
