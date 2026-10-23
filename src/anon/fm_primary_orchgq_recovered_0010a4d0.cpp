#include "../common/types.h"
struct Slot {
    s32 value00;
    s32 handle;
    s32 value08;
    s32 pad0c;
    u8 block10[64];
    u8 block50[64];
    u8 block90[64];
    u8 blockd0[64];
    s32 value110;
    s32 pad114[3];
};
extern "C" u32 D_0033cc68;
extern "C" u8* D_0033cc70;
extern "C" void func_0011d740(s32, u8*, u8*, s32, u8*, u8*, s32, s32);

void func_0010a4d0() {
    u32 index = 0;
    if (D_0033cc68 != 0) {
        do {
        Slot* slot = &((Slot*)D_0033cc70)[index];
        if (slot->handle != 0) {
            func_0011d740(slot->handle, slot->block50, slot->block10, slot->value08,
                          slot->block90, slot->blockd0, slot->value00, slot->value110);
            slot->handle = 0;
            slot->value00 = 0;
            slot->value08 = 0;
        }
        index++;
        } while (index < D_0033cc68);
    }
}
