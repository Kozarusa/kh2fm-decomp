#include "../common/types.h"

void func_00188a28(u8* object, s32 value) {
    s32 index;
    for (index = 0; index < object[0x12]; index++) {
        u16* slot = (u16*)(object + 0x34) + index;
        if (slot[0] == 0) {
            u16 current = slot[8];
            if (current == value) {
                slot[0] = value;
                return;
            }
            if (current == 0) {
                s32 search;
                for (search = 0; search < object[0x12]; search++) {
                    if (((u16*)(object + 0x44))[search] == value) {
                        slot[8] = value;
                        break;
                    }
                }
                slot[0] = value;
                return;
            }
        }
    }
}
