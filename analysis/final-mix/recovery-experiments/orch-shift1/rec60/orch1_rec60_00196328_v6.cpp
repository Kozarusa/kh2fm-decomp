#include "../common/types.h"
extern "C" u32 D_01c61b04;

u8* func_00196328(u8* color, s32 index) {
    u8* tail = color + 4;
    u16 fill = 0xffff;
    color[0] = fill;
    color[1] = fill;
    index = index * 4;
    color[2] = fill;
    *(u16*)(color + 4) = fill;
    *(u16*)(tail + 4) = fill;
    *(u16*)(tail + 2) = fill;
    color[0] = *(u8*)(index + D_01c61b04);
    color[1] = *(u8*)(index + D_01c61b04 + 1);
    color[2] = *(u8*)(index + D_01c61b04 + 2);
    return color;
}
