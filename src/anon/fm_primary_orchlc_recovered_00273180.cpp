#include "../common/types.h"
struct Entry {
    u8 head[5];
    u8 key;
    u8 tail[2];
};
extern "C" Entry D_00373ab0[];
extern "C" Entry D_00373af8[];
extern "C" Entry D_00373ae0[];

Entry* func_00273180(s32 kind, s32 key) {
    Entry* found = 0;
    Entry* table = 0;
    s32 count = 0;
    switch (kind) {
    case 2:
        count = 2;
        table = D_00373af8;
        break;
    case 3:
        count = 6;
        table = D_00373ab0;
        break;
    case 4:
        count = 3;
        table = D_00373ae0;
        break;
    }
    if (key < 0) {
        return table;
    }
    for (s32 index = 0; index < count; index++) {
        if (table[index].key == key) {
            found = &table[index];
            break;
        }
    }
    return found;
}
