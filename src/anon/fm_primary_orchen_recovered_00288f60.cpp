#include "../common/types.h"

void func_00288f60(u8* object, s32 index, u16* source, u16* alternate) {
    s32 offset = index << 3;
    u16* pointer = source;
    index = index << 2;
    s32 count = 3;
    do {
        --count;
        *(u16*)(offset + *(volatile s32*)(object + 0x2c)) = *pointer;
        ++pointer;
        offset += 2;
    } while (count >= 0);
    index <<= 1;
    u32 alternatePointer = (u32)alternate;
    count = 3;
    do {
        u16* destination = (u16*)(index + *(volatile s32*)(object + 0x30));
        u16 value;
        if (alternate != 0) value = *(u16*)alternatePointer;
        else value = *source;
        *destination = value;
        ++source;
        alternatePointer += 2;
        --count;
        index += 2;
    } while (count >= 0);
}
