#include "../common/types.h"
extern "C" u8 D_01d49570;
extern "C" u8 D_01d49571;
extern "C" u8 D_01d49572;
extern "C" u16 D_01d49574;
extern "C" u16 D_01d49576;
extern "C" u16 D_01d49578;

void func_001c4080(u32 mode, u32 value, u32 unused2, u32 unused3) {
    if (value == 0xffff && mode == 1) {
        D_01d49578 = value;
        D_01d49572 = value;
        D_01d49574 = value;
        D_01d49571 = value;
        D_01d49570 = value;
        D_01d49576 = value;
    }
}