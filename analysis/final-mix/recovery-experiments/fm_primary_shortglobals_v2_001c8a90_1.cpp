#include "../common/types.h"
extern "C" u32 D_01d49960;
void func_001c8a90(void)
{
  register u32 *base asm("$14")=&D_01d49960;
  *base=0;
  register u32 high asm("$15");
  asm volatile("lui %0,0x1d5" : "=r"(high) : : "memory");
  base[1]=0;
  *(u32 *)(high-26264)=0;
}
