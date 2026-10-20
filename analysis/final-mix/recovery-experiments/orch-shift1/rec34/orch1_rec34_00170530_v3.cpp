#include "../common/types.h"
extern "C" u8* func_00170400(u32, u32, u32);

void func_00170530(u32 a, u32 b, u32 value, u32 c) {
    u8* object = func_00170400(a, b, c);
    // why: keeps store order
    *(volatile u16*)(object + 0x38) = value;
    *(volatile u16*)(object + 0x3a) = 0xffff;
    *object = 1;
}