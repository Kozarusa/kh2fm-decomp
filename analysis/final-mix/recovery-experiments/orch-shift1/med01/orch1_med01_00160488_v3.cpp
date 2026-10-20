#include "../common/types.h"

void func_00160488(u8* object, u32 red, u32 green, u32 blue) {
    u8 channel[3];
    u8* base = object + 0x1a4;
    s32 blueResult = (u8)blue * base[2];
    s32 greenResult = (u8)green * base[1];
    s32 redResult = (u8)red * base[0];
    object[0x2aa] = blueResult >> 7;
    object[0x2a9] = greenResult >> 7;
    object[0x2a8] = redResult >> 7;
}
