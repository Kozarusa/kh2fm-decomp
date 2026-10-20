#include "../common/types.h"

void func_00188b68(s32 pointer, u16 value, u8 flag) {
    s32 index;

    pointer = pointer + 0x50;
    index = 0;
    do {
        if ((*(u16*)(pointer + 4) & 0x7fff) == 0) {
            *(u16*)(pointer + 4) = (value & 0x7fff) | ((flag != 0) << 15);
            return;
        }
        index = index + 1;
        pointer = pointer + 2;
    } while (index < 0x50);
}
