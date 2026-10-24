#include "../common/types.h"
struct EntryRange {
    u16 first;
    u16 second;
    u16 third;
};
struct Entry {
    u8 index;
    u8 kind;
    u8 flag;
    u8 pad;
    EntryRange range;
};
extern "C" u8 D_0032bae0;
extern "C" u8* D_01c62148[];
extern "C" u8 D_0031f148[];
extern "C" u8* func_002fd248(u32, u8*, u32, u32, u8*);

Entry* func_00199718(Entry* entry, u32 value, s32 index) {
    if (index < 0) {
        index = D_0032bae0;
    }
    u8* found = func_002fd248(value, D_01c62148[index] + 8, *(u32*)(D_01c62148[index] + 4), 4, D_0031f148);
    u16 kind = *(u16*)(found + 2);
    entry->index = index;
    entry->kind = kind;
    entry->flag = 0;
    EntryRange* range = &entry->range;
    entry->range.first = value;
    u32 none = 0xffff;
    range->second = none;
    range->third = none;
    entry->range.second = value;
    entry->range.third = value;
    return entry;
}
