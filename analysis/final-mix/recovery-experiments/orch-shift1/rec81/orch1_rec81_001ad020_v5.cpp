#include "../common/types.h"
struct Entry {
    u8 pad[0x148];
    s32 x;
    s32 y;
    u8 tail[0x158 - 0x150];
};
struct Owner {
    u8 pad[0x608];
    Entry entries[1];
};
extern "C" u32 func_00239bf8(s32, s32);

void func_001ad020(u8* object, s32 x, s32 y, s32 kind) {
    s32 index = *(s32*)(object + 0xb68);
    Entry* entry = ((Owner*)object)->entries + index;
    *(s32*)(object + 0xb68) = index + 1;
    func_00239bf8((s32)entry, kind + 10);
    entry->y = (y - 0x7300) >> 4;
    entry->x = (x - 0x7000) >> 4;
}
