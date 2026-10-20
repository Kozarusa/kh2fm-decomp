#include "../common/types.h"
extern "C" u8 D_004f37b0[];
extern "C" u8 D_004f37a0[];
extern "C" u8 D_004f3790[];
extern "C" u8 D_004f3780[];
extern "C" u8 D_004f37e0[];
extern "C" u8 D_004f37d0[];

void func_0015cff0() {
    u8* dst = D_004f37b0;
    u8* src = D_004f37a0;
    if (dst != src) {
        // why: original moves the quad through t0 ($8), like the accepted copy helpers
        asm volatile("lq $8,0(%1); sq $8,0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    }
    dst = D_004f3790;
    src = D_004f3780;
    if (dst != src) {
        // why: original moves the quad through t0 ($8), like the accepted copy helpers
        asm volatile("lq $8,0(%1); sq $8,0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    }
    dst = D_004f37e0;
    src = D_004f37d0;
    if (dst != src) {
        // why: original moves the quad through t0 ($8), like the accepted copy helpers
        asm volatile("lq $8,0(%1); sq $8,0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    }
}
