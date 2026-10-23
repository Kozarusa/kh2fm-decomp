#include "../common/types.h"
struct Table { u8 pad[96]; s32 slots[4]; };
struct Pair { s32 first; s32 second; };
extern "C" Table D_01c620c8;
extern "C" s32 D_01c62138;
extern "C" Pair D_01c62140;
extern "C" void func_00199280(void*);
extern "C" s32 func_00102c18(s32, s32, void (*)(void*));

s32 func_00199548() {
    s32 index = 0;
    do {
        D_01c620c8.slots[index] = index;
        index++;
    } while (index < 4);
    // why: volatile keeps the 4 store ahead of the tail zero stores
    *(volatile s32*)&D_01c62138 = 4;
    D_01c62140.first = 0;
    D_01c62140.second = 0;
    return func_00102c18(1, 14500, func_00199280);
}
