#include "../common/types.h"
struct Entry {
    u8 pad[600];
    s32 references;
    u8 pad2[8];
    s32 key;
};
struct Pool {
    Entry entries[64];
    s32 table[64];
    s32 count;
};
extern "C" Pool D_01c62fb8;
extern "C" u32 func_001db5a8(u32);
extern "C" u32 func_001a1018(u32);

Entry* func_001a1060(u32 value) {
    Entry* entry = 0;
    s32 key = func_001db5a8(value);
    for (;;) {
        Entry* found;
        Entry* cursor = &D_01c62fb8.entries[0];
        if (entry != 0) {
            cursor = entry + 1;
        }
        while (cursor < &D_01c62fb8.entries[64]) {
            s32 index = (((s32)cursor - (s32)&D_01c62fb8) >> 3) * 0x3f2b3885;
            s32 i;
            for (i = 0; i < D_01c62fb8.count; i++) {
                if (D_01c62fb8.table[i] == index) {
                    cursor++;
                    break;
                }
            }
            if (i == D_01c62fb8.count) {
                found = cursor;
                goto done;
            }
        }
        found = 0;
    done:
        entry = found;
        if (entry == 0) {
            break;
        }
        if (entry->key == key) {
            entry->references++;
            return entry;
        }
    }
    return (Entry*)func_001a1018(value);
}
