#include "../common/types.h"
struct Entry {
    s32 offset;
    s32 amount;
};
struct Table {
    Entry entries[10];
};
extern "C" Table D_0036e860;

void func_001e08c8(u8* object) {
    Table table = D_0036e860;
    s32 index = 0;
    if (table.entries[0].offset != 0) {
        u8* base = object + 0xd80;
        do {
            // why: original loads the whole amount word (lw) instead of a narrowed lbu
            base[table.entries[index].offset] += *(volatile s32*)&table.entries[index].amount;
            index++;
        } while (table.entries[index].offset != 0);
    }
}
