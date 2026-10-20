#include "../common/types.h"
struct Info { u8 pad[2]; u16 id; };
struct Entry { u8 pad[8]; Info* info; u8 rest[0x2c]; };
extern "C" s32 D_00350440;
extern "C" Entry D_01c62198[];

Entry* func_0019b260(s32 id) {
    s32 index;
    s32 count = D_00350440;
    if (count > 0) {
        Entry* entry = D_01c62198;
        for (index = 0; index < count; index++, entry++) {
            if (entry->info->id == id) {
                return entry;
            }
        }
    }
    return 0;
}