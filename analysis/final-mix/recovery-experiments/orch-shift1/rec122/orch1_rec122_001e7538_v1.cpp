#include "../common/types.h"

void func_001e7538() {
    u8 state;
    do {
        u32 vif1 = *(volatile u32*)0x10009000;
        u32 gif = *(volatile u32*)0x1000a000;
        state = (vif1 & 0x100) != 0;
        u32 stat = *(volatile u32*)0x10003c00;
        if ((gif & 0x100) != 0) {
            state = 2;
        }
        if ((stat & 0x1f000003) != 0) {
            state = 4;
        }
        u32 vpu;
        asm volatile("cfc2.ni %0,$29" : "=r"(vpu)); // why: VU0 status read, same pattern as accepted cfc2 siblings
        if ((vpu & 0x100) != 0) {
            state = 8;
        }
    } while (state != 0);
}