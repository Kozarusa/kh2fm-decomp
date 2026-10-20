#include "../common/types.h"
struct Entry {
    s32 a, b, c, d, e;
};
struct Pool {
    Entry entry[128];
    s32 freeList[128];
    s32 count;
};
extern "C" Pool D_01c60d50;

Entry* func_001907e0(Entry* source) {
    D_01c60d50.count = D_01c60d50.count - 1;
    s32 index = D_01c60d50.freeList[D_01c60d50.count];
    Entry* slot = &D_01c60d50.entry[index];
    *slot = *source;
    return slot;
}
