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

// Preserve original registry aliases.
s32 func_001708f8() asm("_ZN2YS10CACHE_BUFF5AllocEPKci");

s32 func_001708f8() {
    Entry* entry = func_00170240();
    s32 big;
    if (entry == 0 || (big = (entry->size < 10000) ^ 1) != 0) {
        func_00170e58();
    }
    entry->count = entry->count + 1;
    return entry->result;
}
