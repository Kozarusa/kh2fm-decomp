#include "../common/types.h"
extern "C" u8 D_01c60530[];

void func_00182720(u32 a, u32 b, u32 c, u32 d) {
    if (b == 0xffff) {
        if (a == 1) {
            *(u16*)(D_01c60530 + 8) = b;
            *(u8*)(D_01c60530 + 2) = b;
            *(u16*)(D_01c60530 + 4) = b;
            *(u8*)(D_01c60530 + 1) = b;
            *(u8*)(D_01c60530 + 0) = b;
            *(u16*)(D_01c60530 + 6) = b;
        }
    }
}