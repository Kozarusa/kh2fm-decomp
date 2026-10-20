#include "../common/types.h"
struct Table { u8 pad[96]; s32 slots[4]; };
extern "C" Table D_01c620c8;
extern "C" volatile s32 D_01c62138; // why: keeps store order
extern "C" s32 D_01c62140[];
extern "C" void func_00199280(void*);
extern "C" s32 func_00102c18(s32, s32, void (*)(void*));

s32 func_00199548() {
    s32 index = 0;
    do {
        D_01c620c8.slots[index] = index;
        index++;
    } while (index < 4);
    s32* tail = D_01c62140;
    D_01c62138 = 4;
    tail[0] = 0;
    tail[1] = 0;
    return func_00102c18(1, 14500, func_00199280);
}

