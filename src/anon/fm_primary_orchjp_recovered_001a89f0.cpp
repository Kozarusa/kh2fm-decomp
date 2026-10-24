#include "../common/types.h"
extern "C" s32 func_001a8930(u8*, s32, s32);
extern "C" void func_0016fab0(s32, s32);
extern "C" u8 D_0032bae0[];
struct SlotTable {
    u8 header[16];
    u16 values[18];
};
extern "C" SlotTable D_01c6cc10;
extern "C" u8* D_01c6cc08;

void func_001a89f0() {
    s32 first = 0;
    s32 second = 0;
    u8* keys = D_0032bae0;
    u8 key = keys[0];
    s32 index;
    for (index = 0; index < 18; index++) {
        D_01c6cc10.values[index] = 0;
    }
    index = 0;
    u8* entry = D_01c6cc08 + 8;
    if (*(s32*)(D_01c6cc08 + 4) > 0) {
        do {
            if (func_001a8930(entry, key, keys[1]) != 0) {
                if (0 < *(s32*)(entry + 8)) {
                    first = *(s32*)(entry + 8);
                }
                if (0 < *(s32*)(entry + 12)) {
                    second = *(s32*)(entry + 12);
                }
                s32 slotIndex;
                for (slotIndex = 0; slotIndex < 18; slotIndex++) {
                    if (*(u16*)(entry + 16 + slotIndex * 2) != 0) {
                        D_01c6cc10.values[slotIndex] = *(u16*)(entry + 16 + slotIndex * 2);
                    }
                }
            }
            index++;
            entry += 52;
        } while (index < *(s32*)(D_01c6cc08 + 4));
    }
    func_0016fab0(first, second);
}
