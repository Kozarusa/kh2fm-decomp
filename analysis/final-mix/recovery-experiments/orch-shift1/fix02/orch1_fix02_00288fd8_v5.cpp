#include "../common/types.h"
void func_00288fd8(u8* object, s32 index, u32 value, u32 alternate) {
    s32 count = 3;
    s32 offset = index << 3;
    index <<= 2;
    do {
        --count;
        *(u16*)(offset + *(volatile s32*)(object + 0x2c)) = value;
        offset += 2;
    } while (count >= 0);
    index <<= 1;
    s32 secondCount = 3;
    do {
        u16* destination = (u16*)(index + *(volatile s32*)(object + 0x30));
        index += 2;
        u32 selected = alternate;
        if (alternate == 0) selected = value;
        --secondCount;
        *destination = selected;
    } while (secondCount >= 0);
}




