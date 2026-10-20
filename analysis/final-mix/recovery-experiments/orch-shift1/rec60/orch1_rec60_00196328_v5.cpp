#include "../common/types.h"
extern "C" u32 D_01c61b04;

u8* func_00196328(u8* color, s32 index) {
    u16 fill = 0xffff;
    // why: original keeps the half-word cursor in t4 (12), allocated before the table base
    register u16* half asm("$12") = (u16*)(color + 4);
    color[0] = fill;
    color[1] = fill;
    index = index * 4;
    color[2] = fill;
    *(u16*)(color + 4) = fill;
    half[2] = fill;
    half[1] = fill;
    color[0] = *(u8*)(index + D_01c61b04);
    color[1] = *(u8*)(index + D_01c61b04 + 1);
    color[2] = *(u8*)(index + D_01c61b04 + 2);
    return color;
}
