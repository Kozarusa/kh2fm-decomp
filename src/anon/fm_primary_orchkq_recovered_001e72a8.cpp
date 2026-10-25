#include "../common/types.h"
extern "C" s32 D_01d9e6b4;
extern "C" s32 func_002f25a0(u32, u32);

#define WAIT_FOR_DMA() \
    do { \
        u8 state; \
        do { \
            u32 vif1Chcr = *(volatile u32*)0x10009000; \
            u32 gifChcr = *(volatile u32*)0x1000a000; \
            u32 vif1Busy = vif1Chcr & 0x100; \
            state = vif1Busy != 0; \
            if ((gifChcr & 0x100) != 0) { \
                state = 2; \
            } \
            u32 vif1Stat = *(volatile u32*)0x10003c00; \
            if ((vif1Stat & 0x1f000003) != 0) { \
                state = 4; \
            } \
            u32 vpuStat; \
            asm volatile("cfc2.ni %0,$29" : "=r"(vpuStat)); \
            if ((vpuStat & 0x100) != 0) { \
                state = 8; \
            } \
        } while (state != 0); \
    } while (0)

s32 func_001e72a8(s32 tag) {
    s32 result = func_002f25a0(0, 0);
    if (D_01d9e6b4 != tag) {
        WAIT_FOR_DMA();
        *(volatile u32*)0x10009020 = 0;
        *(volatile u32*)0x10009030 = tag;
        *(volatile u32*)0x1000e010 = 2;
        D_01d9e6b4 = tag;
        *(volatile u32*)0x10009000 = 0x145;
    } else {
        WAIT_FOR_DMA();
    }
    return result;
}
