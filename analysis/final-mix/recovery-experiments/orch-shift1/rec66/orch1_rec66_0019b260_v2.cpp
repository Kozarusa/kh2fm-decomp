#include "../common/types.h"
struct Info { u8 pad[2]; u16 id; };
struct Entry { u8 pad[8]; Info* info; u8 rest[0x2c]; };
extern "C" s32 D_00350440;
extern "C" Entry D_01c62198[];

Entry* func_0019b260(s32 id) {
    s32 index = 0;
    s32 total = D_00350440;
    if (total > 0) {
        s32 count = total;
        Entry* entry = D_01c62198;
        for (; index < count; index++, entry++) {
            if (entry->info->id == id) {
                return entry;
            }
        }
    }
    return 0;
}