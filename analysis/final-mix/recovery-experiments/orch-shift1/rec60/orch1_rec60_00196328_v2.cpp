#include "../common/types.h"
extern "C" u8* D_01c61b04;

u8* func_00196328(u8* color, s32 index) {
    u16 fill = 0xffff;
    u16* half = (u16*)(color + 4);
    color[0] = fill;
    color[1] = fill;
    index = index * 4;
    color[2] = fill;
    *(u16*)(color + 4) = fill;
    half[2] = fill;
    half[1] = fill;
    color[0] = D_01c61b04[index];
    color[1] = D_01c61b04[index + 1];
    color[2] = D_01c61b04[index + 2];
    return color;
}
