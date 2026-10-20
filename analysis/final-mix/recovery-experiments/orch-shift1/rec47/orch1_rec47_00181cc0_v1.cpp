#include "../common/types.h"

extern "C" void func_00181d30(s16*, s16*);

void func_00181cc0(s16* base, s16 key) {
    s16 current = *base;
    s16* entry = base;
    while (current != -1) {
        if (current == key) {
            func_00181d30(base, entry + 2);
            return;
        }
        entry = (s16*)((s32)entry + entry[1]);
        current = *entry;
    }
}