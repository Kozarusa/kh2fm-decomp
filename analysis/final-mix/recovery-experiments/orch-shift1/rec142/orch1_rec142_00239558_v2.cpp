#include "../common/types.h"
void func_00239558(u8* object, u16* first, u16* second) {
    *(u32*)(object + 16) |= 64;
    u8* cursor = object;
    s32 index = 0;
    do {
        s32 offset = index * 2;
        ++index;
        *(u16*)(cursor + 160) = *(u16*)((u8*)first + offset);
        *(u16*)(cursor + 168) = *(u16*)((u8*)second + offset);
        cursor += 2;
    } while (index < 4);
}