#include "../common/types.h"

struct Manager {
    u8 first[160];
    u8 second[160];
    u8 third[3200];
    s32 pad0;
    u8* blocks;
    u8* entries;
    s32 count;
    s32 pad1;
    s32 state[4];
    s32 pad2[3];
    s32 group;
    s32 pad3[3];
    s32 current;
};

extern "C" u32 func_002fde18(...);
extern "C" u32 func_001050d8(u32);
extern "C" u32 func_001e0cb8(...);
// why: extern "C" form from the accepted call site in fm_primary_capacity_recovered_00303c48.cpp; the asm-label form of fm_global_recovered_06.cpp fails the isolated link (v1)
extern "C" int func_001c0090(...);

// why: int return; the only exit leaves func_001c0090's direct v0 (no later call), and its accepted definition in fm_global_recovered_06.cpp returns int

int func_001e17b8(Manager* manager) {
    func_002fde18(manager->first, 0, 160);
    func_002fde18(manager->second, 0, 160);
    func_002fde18(manager->third, 0, 3200);
    manager->count = 0;
    s32 step = 6;
    s32 total = 0;
    s32 index = 14;
    do {
        total += step;
        index--;
        step += 3;
    } while (index >= 0);
    manager->count = total;
    s32 entry = 0;
    u8* blocks = (u8*)func_001050d8(total * 64);
    manager->blocks = blocks;
    func_002fde18(blocks, 0, manager->count << 6);
    manager->entries = (u8*)func_001050d8(manager->count * 48);
    if (manager->count > 0) {
        s32 offset = 0;
        do {
            func_001e0cb8(manager->entries + offset, entry);
            entry++;
            offset += 48;
        } while (entry < manager->count);
    }
    manager->state[0] = 0;
    manager->state[1] = 0;
    manager->state[2] = 0;
    manager->state[3] = 0;
    int group = func_001c0090();
    manager->group = group;
    register s32 none asm("$15") = -1; // why: original materializes the -1 marker in t7 (v3 used t6)
    manager->current = none;
    return group;
}
