#include "../common/types.h"

struct Entry {
    s32 key;
    s32 sub;
    u8 flag;
    u8 pad[3];
};

s32 func_0019f740(Entry* entries, s32 key, s32 sub) {
    s32 none = -1;
    Entry* end = entries + 8;
    do {
        if (entries->key == key) {
            if (entries->sub == none || entries->sub == sub) {
                if (entries->flag == 0) {
                    return 1;
                }
            }
        }
        entries++;
    } while ((s32)entries < (s32)end);
    return 0;
}
