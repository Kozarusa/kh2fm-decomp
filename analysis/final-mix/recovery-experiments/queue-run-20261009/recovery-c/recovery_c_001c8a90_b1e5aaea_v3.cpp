#include "../common/types.h"
extern "C" u32 D_01d49960;
extern "C" u32 D_01d49968;
void func_001c8a90(void) { u32 *base=&D_01d49960; *base=0;
base[1]=0;asm volatile("" ::: "memory");D_01d49968=0;
}