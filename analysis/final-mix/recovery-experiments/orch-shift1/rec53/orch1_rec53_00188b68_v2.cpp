#include "../common/types.h"

void func_00188b68(s32 pointer, s32 value, u8 flag) {
    s32 index;
    u32 low = value & 0x7fff;
    u32 high = (flag != 0);
    high = high << 15;

    pointer = pointer + 0x50;
    index = 0;
    do {
        if ((*(u16*)(pointer + 4) & 0x7fff) == 0) {
            *(u16*)(pointer + 4) = low | high;
            return;
        }
        index = index + 1;
        pointer = pointer + 2;
    } while (index < 0x50);
}
