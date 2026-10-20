#include "../common/types.h"
extern "C" u32 D_00347d30[8];
extern "C" u32 D_00347d40;
extern "C" void func_00136a98();
void func_00136ab8(){D_00347d30[0]=0;register volatile u32*base asm("$14")=D_00347d30;register volatile u32*tail asm("$13")=base+4;asm("":"+r"(base),"+r"(tail));register u32 page asm("$15");asm volatile("lui %0,0x34":"=r"(page),"+r"(tail)::"$31");tail[2]=0;*(volatile u32*)(page+0x7d40)=0;base[1]=0;base[7]=0;base[3]=0;base[2]=0;tail[1]=0;asm volatile(""::"m"(tail[1]):"$31");func_00136a98();}


