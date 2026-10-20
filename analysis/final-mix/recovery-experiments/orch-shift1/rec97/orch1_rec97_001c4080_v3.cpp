#include "../common/types.h"
struct Fill {
    u8 r;
    u8 g;
    u8 b;
    u8 pad;
    u16 x;
    u16 y;
    u16 z;
};
extern "C" Fill D_01d49570;

void func_001c4080(u32 mode, u32 value, u32 unused2, u32 unused3) {
    if (value == 0xffff && mode == 1) {
        D_01d49570.r = value;
        D_01d49570.g = value;
        D_01d49570.b = value;
        D_01d49570.x = value;
        D_01d49570.y = value;
        D_01d49570.z = value;
    }
}