#include "../common/types.h"
struct Entry {
    s32 key;
    s32 sub;
    u8 pad[80];
};
extern "C" Entry D_01c61b48[];

Entry* func_00198bd0(s32 key, s32 sub) {
    Entry* result = 0;
    Entry* entry = D_01c61b48;
    Entry* end = D_01c61b48 + 16;
    do {
        if (entry->key == key) {
            if (entry->sub == sub) {
                return entry;
            }
            if (sub < 0 || entry->sub < 0) {
                result = entry;
            }
        }
        entry++;
    } while (entry < end);
    return result;
}
