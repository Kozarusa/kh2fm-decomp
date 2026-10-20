#include "../common/types.h"
void func_00239558(u8* object, s32 first, s32 second) {
    *(u32*)(object + 16) |= 64;
    u8* cursor = object;
    s32 index = 0;
    do {
        s32 offset = index * 2;
        ++index;
        *(u16*)(cursor + 160) = *(u16*)(offset + first);
        *(u16*)(cursor + 168) = *(u16*)(offset + second);
        cursor += 2;
    } while (index < 4);
}