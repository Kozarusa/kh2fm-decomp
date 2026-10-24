#include "../common/types.h"
extern "C" u8 D_0032e020[];
extern "C" u32 func_001a3820(...);

void func_001a39c8(u32 value) {
    u8* base = D_0032e020;
    register u16* slots asm("$14"); // why: original keeps the slot cursor in t6
    s32 index;
    if (*(u16*)(base + 0x11f8) == 0 && *(u16*)(base + 0x120e) == 0) {
        *(u16*)(base + 0x120e) = func_001a3820(value);
    }
    slots = (u16*)(base + 0x11f0);
    for (index = 0; index < 8; index++) {
        if (slots[4] == 0) {
            slots[4] = value;
            return;
        }
        if (slots[4] == value) {
            return;
        }
        slots++;
    }
}
