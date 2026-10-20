#include "../common/types.h"
extern "C" u32 D_00347d30[8];
extern "C" u32 D_00347d40;
extern "C" void func_00136a98();
void func_00136ab8(){D_00347d30[0]=0;register u32*base asm("$14")=D_00347d30;register u32*tail asm("$13")=base+4;asm("":"+r"(base),"+r"(tail));tail[2]=0;D_00347d40=0;base[1]=0;base[7]=0;base[3]=0;base[2]=0;tail[1]=0;func_00136a98();}

