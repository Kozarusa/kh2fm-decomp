#include "../common/types.h"

struct Manager {
    u8 pad[128];
    u8* table;
};

struct Slot {
    u8 pad0[12];
    s32 index;
    s32 offset;
};

extern "C" Manager* D_01d9e6e0;
extern "C" u8* func_001e7a98(Manager*, u8*);

void func_001ea100(u32 value, Slot* slot, s16* source) {
    if (slot->index != -1) {
        u8* result = 0;
        u8* entry = D_01d9e6e0->table + slot->index * 16;
        if (entry != 0) {
            result = func_001e7a98(D_01d9e6e0, entry);
            *(u32*)(result + 4) = value;
        }
        f32* target = (f32*)(result + slot->offset + 160);
        target[0] = (f32)source[0];
        asm volatile("" ::: "memory"); // why: keeps store order
        register s32 second asm("$14") = source[1]; // why: original loads the second element into t6
        target[1] = (f32)second;
        asm volatile("" ::: "memory"); // why: keeps store order
        target[2] = (f32)source[2];
    }
}
