#include "../common/types.h"
struct Entry {
    u8 pad0[2];
    u16 count;
    u8 pad1[0x24];
    s32 size;
    u8 pad2[4];
    s32 result;
};
extern "C" Entry* func_00170240(...);
extern "C" u32 func_00170e58(void);

s32 func_001708f8() {
    Entry* entry = func_00170240();
    if (entry == 0 || entry->size >= 10000) {
        func_00170e58();
    }
    entry->count = entry->count + 1;
    return entry->result;
}