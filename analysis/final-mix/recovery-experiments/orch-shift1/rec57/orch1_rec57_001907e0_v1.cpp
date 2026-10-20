#include "../common/types.h"
struct Pool {
    s32 entries[640][0];
};
struct Entry {
    s32 a, b, c, d, e;
};
struct PoolBase {
    Entry entry[128];
    s32 pad[0];
};
extern "C" u8 D_01c60d50[];

Entry* func_001907e0(Entry* source) {
    s32* count = (s32*)(D_01c60d50 + 3072);
    *count = *count - 1;
    s32 index = *(s32*)(D_01c60d50 + 2560 + *count * 4);
    Entry* slot = (Entry*)D_01c60d50 + index;
    slot->a = source->a;
    slot->b = source->b;
    slot->c = source->c;
    slot->d = source->d;
    slot->e = source->e;
    return slot;
}
