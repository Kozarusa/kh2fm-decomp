#include "../common/types.h"

struct Pair {
    s32 first;
    s32 second;
};

struct Entry {
    u8 pad[20];
    u16 id;
};

extern "C" Pair D_01c60be0;
extern "C" Entry* func_00187ab8(s32, s32);
extern "C" void func_00188398(u8*, u16, Pair*, s32);

void func_001884d0(u8* object, s32* source) {
    s32 owner = *(s32*)(object + 140);
    if (owner != 0) {
        Entry* entry = func_00187ab8(owner, source[0]);
        if (entry != 0) {
            D_01c60be0.first = *(s32*)(object + 136);
            D_01c60be0.second = source[1];
            func_00188398(object, entry->id, &D_01c60be0, 2);
        }
    }
}
