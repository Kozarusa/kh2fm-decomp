#include "../common/types.h"
void func_00232ea0(u8* object, u8* data, s32* source, s32 value) {
    *(s32*)(object + 0) = source[0];
    *(s32*)(object + 4) = source[1];
    *(s32*)(object + 8) = source[2];
    f32 size = (f32)*(volatile u16*)(data + 8);
    *(f32*)(object + 20) = size + size;
    *(u16*)(object + 24) = *(volatile u16*)(data + 10);
    *(u16*)(object + 26) = *(volatile u16*)(data + 12);
    s32 offset = *(volatile s16*)(data + 16);
    s32 count = *(volatile u16*)(data + 8);
    *(u8*)(object + 48) = 1;
    *(s32*)(object + 12) = value;
    f32 result = (f32)(count - offset);
    result = result + result;
    *(f32*)(object + 16) = result;
}