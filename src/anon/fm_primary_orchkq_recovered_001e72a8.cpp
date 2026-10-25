#include "../common/types.h"
extern "C" s32 D_01d9e6b4;
// why: the callee's original leaves an integer in v0 on every exit (0 or -1 for a0==0, a status bitmask for a0!=0), no float, and this target returns it untouched; the accepted void(u32, u32) declarations at 0020f118, 0020f150, 0014d8d0 discard the result and no accepted definition exists
extern "C" s32 func_002f25a0(u32, u32);

// why: all exits are direct callee results, so the typed return is kept (clarification (iv)); the recovered call site fm_primary_orchdk_recovered_0021cda0.cpp declares this target void(u8*) and discards the result

s32 func_001e72a8(s32 tag) {
    s32 result = func_002f25a0(0, 0);
    if (D_01d9e6b4 != tag) {
        u8 state;
        do {
            u32 vif1 = *(volatile u32*)0x10009000;
            u32 gif = *(volatile u32*)0x1000a000;
            u32 masked = vif1 & 0x100;
            state = masked != 0;
            if ((gif & 0x100) != 0) {
                state = 2;
            }
            u32 stat = *(volatile u32*)0x10003c00;
            if ((stat & 0x1f000003) != 0) {
                state = 4;
            }
            u32 vpu;
            asm volatile("cfc2.ni %0,$29" : "=r"(vpu)); // why: VU0 status read, text identical to accepted 001e7538
            if ((vpu & 0x100) != 0) {
                state = 8;
            }
        } while (state != 0);
        *(volatile u32*)0x10009020 = 0;
        *(volatile u32*)0x10009030 = tag;
        *(volatile u32*)0x1000e010 = 2;
        D_01d9e6b4 = tag;
        *(volatile u32*)0x10009000 = 0x145;
    } else {
        u8 state;
        do {
            u32 vif1 = *(volatile u32*)0x10009000;
            u32 gif = *(volatile u32*)0x1000a000;
            u32 masked = vif1 & 0x100;
            state = masked != 0;
            if ((gif & 0x100) != 0) {
                state = 2;
            }
            u32 stat = *(volatile u32*)0x10003c00;
            if ((stat & 0x1f000003) != 0) {
                state = 4;
            }
            u32 vpu;
            asm volatile("cfc2.ni %0,$29" : "=r"(vpu)); // why: VU0 status read, text identical to accepted 001e7538
            if ((vpu & 0x100) != 0) {
                state = 8;
            }
        } while (state != 0);
    }
    return result;
}
