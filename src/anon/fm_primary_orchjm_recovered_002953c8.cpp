#include "../common/types.h"
struct Entry {
    s8 key;
    u8 pad[15];
};
extern "C" u32 func_00294000(u32);

Entry* func_002953c8(s32 value) {
    u32 object = func_00294000(0);
    s32 count = *(s32*)(object + 8);
    Entry* entries = (Entry*)(object + 16);
    s32 index;
    for (index = 0; index < count; index++) {
        if (entries[index].key == value) break;
    }
    return &entries[index];
}
