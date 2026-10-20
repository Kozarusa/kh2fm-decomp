#include "../common/types.h"

void func_00198aa8(s32 object, s32 index, s32 value, s32 slot) {
    if (slot == 0) {
        slot = -1;
        s32 entry = *(s32*)(object + 0x9b4);
        if (entry != 0) {
            slot = *(s16*)(entry + 2);
        }
    }
    s32 total = slot * 1000 + value;
    *(s32*)(index * 12 + object + 0x9e4) = total;
}