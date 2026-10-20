#include "../common/types.h"
extern "C" u32 D_01d49960;
extern "C" u32 D_01d49968;
void func_001c8a90(void) { u32 *base=&D_01d49960; *base=0;
register u32 high asm("$15")=0x1d50000; asm volatile("" : "+r"(high)); base[1]=0; *(u32*)(high-0x6698)=0;
}