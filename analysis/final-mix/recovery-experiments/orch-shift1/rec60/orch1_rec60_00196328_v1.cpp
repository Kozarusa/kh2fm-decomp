#include "../common/types.h"
extern "C" u8* D_01c61b04;

u8* func_00196328(u8* color, s32 index) {
    color[0] = 0xff;
    color[1] = 0xff;
    index = index * 4;
    color[2] = 0xff;
    u16* half = (u16*)(color + 4);
    *(u16*)(color + 4) = 0xffff;
    half[2] = 0xffff;
    half[1] = 0xffff;
    color[0] = D_01c61b04[index];
    color[1] = D_01c61b04[index + 1];
    color[2] = D_01c61b04[index + 2];
    return color;
}
