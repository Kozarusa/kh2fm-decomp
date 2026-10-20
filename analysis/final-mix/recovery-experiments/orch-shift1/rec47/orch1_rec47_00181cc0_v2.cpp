#include "../common/types.h"

extern "C" void func_00181d30(s16*, s16*);

void func_00181cc0(s16* base, s32 key) {
    u16 current = *(u16*)base;
    s16* entry = base;
    while ((s16)current != -1) {
        s16* next = (s16*)((s32)entry + entry[1]);
        if ((s16)current == key) {
            func_00181d30(base, entry + 2);
            return;
        }
        current = *(u16*)next;
        entry = next;
    }
}