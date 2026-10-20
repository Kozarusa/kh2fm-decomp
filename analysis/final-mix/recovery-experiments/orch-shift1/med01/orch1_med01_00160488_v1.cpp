#include "../common/types.h"

void func_00160488(u8* object, u32 red, u32 green, u32 blue) {
    u8* base = object + 0x1a4;
    object[0x2aa] = ((u8)blue * base[2]) >> 7;
    object[0x2a9] = ((u8)green * base[1]) >> 7;
    object[0x2a8] = ((u8)red * base[0]) >> 7;
}
