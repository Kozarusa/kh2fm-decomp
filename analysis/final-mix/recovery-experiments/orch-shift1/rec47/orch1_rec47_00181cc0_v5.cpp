#include "../common/types.h"

extern "C" void func_00181d30(s16*, s16*);

void func_00181cc0(s16* base, s32 key) {
    u16 current = *(u16*)base;
    s16* entry = base;
    if (((current << 16) >> 16) == -1) {
        return;
    }
    do {
        s16 offset = entry[1];
        if (((current << 16) >> 16) == key) {
            func_00181d30(base, entry + 2);
            return;
        }
        entry = (s16*)((s32)entry + offset);
        current = *(u16*)entry;
    } while (((current << 16) >> 16) != -1);
}