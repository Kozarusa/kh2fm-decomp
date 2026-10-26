#include "../common/types.h"
struct Entry {
    u8 head[0x148];
    s32 x;
    s32 y;
    u8 tail[0x158 - 0x150];
};
struct Owner {
    u8 head[0x608];
    Entry entries[4];
    s32 count;
};
extern "C" u32 func_00239bf8(Entry*, s32);

u32 func_001ad020(Owner* owner, s32 x, s32 y, s32 kind) {
    Entry* entry = &owner->entries[owner->count++];
    u32 result = func_00239bf8(entry, kind + 10);
    entry->x = (x - 0x7000) >> 4;
    entry->y = (y - 0x7300) >> 4;
    return result;
}
