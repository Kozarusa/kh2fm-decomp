#include "../common/types.h"
extern "C" u32 D_0033cafc,D_0033caf4;
extern "C" u32 D_0033caf0;
extern "C" u32 D_0033cb00;
void func_00105af8(s64 mode)
{
 u32 low;asm("" : "=r"(low) : "0"(mode));
 register u32 upperBase asm("$11")=0x00340000;asm("" : "+r"(upperBase));
 register u32* table asm("$12")=(u32*)(upperBase-13568);asm("" : "+r"(table));
 D_0033cafc=low;
 D_0033caf0=table[(s32)low-1];
 if(mode!=3) {
 u32 selected=*(volatile u32*)(upperBase-13568);
 if(mode!=8) D_0033caf4=D_0033caf0;
 else D_0033caf4=selected;
 } else D_0033caf4=table[1];
}
