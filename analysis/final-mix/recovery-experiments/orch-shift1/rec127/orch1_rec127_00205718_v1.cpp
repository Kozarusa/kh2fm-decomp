#include "../common/types.h"

struct Inner {
    u8 pad[8];
    s32 offset;
};

struct Outer {
    u8 pad[12];
    Inner* inner;
};

struct Slots {
    u8 pad[80];
    u32 slot0;
    u32 slot1;
    u32 slot2;
};

extern "C" u32 D_01d9e6e4;
extern "C" void func_001e7798(u32, u32);

void func_00205718(u8* base, Outer* outer) {
    Slots* slots = (Slots*)(base + outer->inner->offset + 160);
    if (slots->slot0 != 0) {
        func_001e7798(D_01d9e6e4, slots->slot0);
        slots->slot0 = 0;
    }
    if (slots->slot1 != 0) {
        func_001e7798(D_01d9e6e4, slots->slot1);
        slots->slot1 = 0;
    }
    if (slots->slot2 != 0) {
        func_001e7798(D_01d9e6e4, slots->slot2);
        slots->slot2 = 0;
    }
}
